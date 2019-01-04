/*
    __rtd_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__rtd_driver.h"
#include "__rtd_hal.c"

/* ------------------------------------------------------------------- MACROS */



/* ---------------------------------------------------------------- VARIABLES */

const uint8_t _RTD_OK     = 0;                                     /**< NO ERROR */
const uint8_t _RTD_ERR    = 1;                                     /**< ERROR OCCURED */

const uint16_t _RTD_REF_RESISTANCE_470  = 470;       /**< Value of referent resistor in Ohms */


const uint8_t _RTD_CONFIGURATION         = 0x00;      /**< Configuration Register */
const uint8_t _RTD_RTD_MSB               = 0x01;      /**< RTD Data MSB Register*/
const uint8_t _RTD_RTD_LSB               = 0x02;      /**< RTD Data LSB Register*/
const uint8_t _RTD_HI_FLT_THRHLD_MSB     = 0x03;      /**< High Fault Threshold MSB register */
const uint8_t _RTD_HI_FLT_THRHLD_LSB     = 0x04;      /**< High Fault Threshold LSB register */
const uint8_t _RTD_LO_FLT_THRHLD_MSB     = 0x05;      /**< Low Fault Threshold MSB register */
const uint8_t _RTD_LO_FLT_THRHLD_LSB     = 0x06;      /**< Low Fault Threshold LSB register */
const uint8_t _RTD_FLT_STATUS            = 0x07;      /**< Fault Status Register */

#ifdef   __RTD_DRV_I2C__
static uint8_t _slaveAddress;
#endif

/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */



/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */



/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __RTD_DRV_SPI__

void rtd_spiDriverInit(T_RTD_P gpioObj, T_RTD_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __RTD_DRV_I2C__

void rtd_i2cDriverInit(T_RTD_P gpioObj, T_RTD_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __RTD_DRV_UART__

void rtd_uartDriverInit(T_RTD_P gpioObj, T_RTD_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif

// GPIO Only Drivers - remove in other cases
void rtd_gpioDriverInit(T_RTD_P gpioObj)
{
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
}

/* ----------------------------------------------------------- IMPLEMENTATION */

void rtd_writeRegister(uint8_t regAddress, uint8_t writeData)
{
    uint8_t tmp[2];
    regAddress |= 0x80;
    tmp[0] = regAddress;
    tmp[1] = writeData;

    hal_gpio_csSet(0);
    HAL_spiWrite(tmp, 2);
    hal_gpio_csSet(1);
}

uint8_t rtd_readRegister(uint8_t regAddress)
{
    uint8_t tmp;

    hal_gpio_csSet(0);
    HAL_spiWrite(&regAddress, 1);
    HAL_spiRead(&tmp, 1);
    hal_gpio_csSet(1);

    return tmp;
}

uint16_t rtd_readTemperature()
{
    volatile uint16_t returnValue;

    returnValue = RTD_readRegister(0x01);
    returnValue <<= 8;
    returnValue |= RTD_readRegister(0x02);

    return returnValue;
}

float rtd_convertTemperature(uint16_t inputData, uint16_t referentResistance)
{
    float floatValue;
    float coefficient;
    coefficient = (referentResistance/400.0);

    inputData >>= 1;
    floatValue = (float)inputData * coefficient;
    floatValue /= 32;
    floatValue -= 256;

    return floatValue;
}

/* -------------------------------------------------------------------------- */
/*
  __rtd_driver.c

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */