/*
    __rtd_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __rtd_driver.h
@brief    RTD Driver
@mainpage RTD Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   RTD
@brief      RTD Click Driver
@{

| Global Library Prefix | **RTD** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **Nov 2017.**      |
| Developer             | **Djordje Rosic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _RTD_H_
#define _RTD_H_

/** 
 * @macro T_RTD_P
 * @brief Driver Abstract type 
 */
#define T_RTD_P    const uint8_t*

/** @defgroup RTD_COMPILE Compilation Config */              /** @{ */

   #define   __RTD_DRV_SPI__                            /**<     @macro __RTD_DRV_SPI__  @brief SPI driver selector */
//  #define   __RTD_DRV_I2C__                            /**<     @macro __RTD_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __RTD_DRV_UART__                           /**<     @macro __RTD_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup RTD_VAR Variables */                           /** @{ */

extern const uint16_t _RTD_REF_RESISTANCE_470;       /**< Value of referent resistor in Ohms */
extern const uint8_t _RTD_OK;
extern const uint8_t _RTD_ERR;


extern const uint8_t _RTD_CONFIGURATION;              /**< Configuration Register */
extern const uint8_t _RTD_RTD_MSB;                    /**< RTD Data MSB Register*/
extern const uint8_t _RTD_RTD_LSB;                    /**< RTD Data LSB Register*/
extern const uint8_t _RTD_HI_FLT_THRHLD_MSB;          /**< High Fault Threshold MSB register */
extern const uint8_t _RTD_HI_FLT_THRHLD_LSB;          /**< High Fault Threshold LSB register */
extern const uint8_t _RTD_LO_FLT_THRHLD_MSB;          /**< Low Fault Threshold MSB register */
extern const uint8_t _RTD_LO_FLT_THRHLD_LSB;          /**< Low Fault Threshold LSB register */
extern const uint8_t _RTD_FLT_STATUS;                 /**< Fault Status Register */

                                                                       /** @} */
/** @defgroup RTD_TYPES Types */                             /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup RTD_INIT Driver Initialization */              /** @{ */

#ifdef   __RTD_DRV_SPI__
void rtd_spiDriverInit(T_RTD_P gpioObj, T_RTD_P spiObj);
#endif
#ifdef   __RTD_DRV_I2C__
void rtd_i2cDriverInit(T_RTD_P gpioObj, T_RTD_P i2cObj, uint8_t slave);
#endif
#ifdef   __RTD_DRV_UART__
void rtd_uartDriverInit(T_RTD_P gpioObj, T_RTD_P uartObj);
#endif

// GPIO Only Drivers - remove in other cases
void rtd_gpioDriverInit(T_RTD_P gpioObj);
                                                                       /** @} */
/** @defgroup RTD_FUNC Driver Functions */                   /** @{ */




/**
 * @brief Write to Register
 *
 * @param[in] regAddress   Address to write to
 * @param[in] writeData    Data to write
 *
 * RTD SPI Write function, that will write input data into the chosen register.
 *
 * @note
 * This function automaticaly adds write bit as needed by this device.
 */
void rtd_writeRegister(uint8_t regAddress, uint8_t writeData);
/**
 * @brief Read from Register
 *
 * @param[in] regAddress   Address to read from
 * @retval                 Read data
 *
 * RTD SPI Read function, that will read data from the chosen register.
 */
uint8_t rtd_readRegister(uint8_t regAddress);
/**
 * @brief Read Temperature
 *
 * @retval                 Read unconverted temperature data
 *
 * RTD Read Temperature function, that reads data from temperature registers.
 */
uint16_t rtd_readTemperature();
/**
 * @brief Convert Temperature
 *
 * @param[in] inputData            Unconverted input data
 * @param[in] referentResistance   Value of external referent resistance in Ohms
 * @retval                         Converted Temperature data
 *
 * This value will take raw input data (such as supplied by the read
 * temperature function), and will convert it into readable format.
 * Returned float value is in degrees celsius.
 *
 * @note
 * Referent resistance on the click board can be changed to better match the
 * sensor in use. Input the value of the resistor used in Ohms to get correct
 * data.
 */
float rtd_convertTemperature(uint16_t inputData, uint16_t referentResistance);


                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_RTD_STM.c
    @example Click_RTD_TIVA.c
    @example Click_RTD_CEC.c
    @example Click_RTD_KINETIS.c
    @example Click_RTD_MSP.c
    @example Click_RTD_PIC.c
    @example Click_RTD_PIC32.c
    @example Click_RTD_DSPIC.c
    @example Click_RTD_AVR.c
    @example Click_RTD_FT90x.c
    @example Click_RTD_STM.mbas
    @example Click_RTD_TIVA.mbas
    @example Click_RTD_CEC.mbas
    @example Click_RTD_KINETIS.mbas
    @example Click_RTD_MSP.mbas
    @example Click_RTD_PIC.mbas
    @example Click_RTD_PIC32.mbas
    @example Click_RTD_DSPIC.mbas
    @example Click_RTD_AVR.mbas
    @example Click_RTD_FT90x.mbas
    @example Click_RTD_STM.mpas
    @example Click_RTD_TIVA.mpas
    @example Click_RTD_CEC.mpas
    @example Click_RTD_KINETIS.mpas
    @example Click_RTD_MSP.mpas
    @example Click_RTD_PIC.mpas
    @example Click_RTD_PIC32.mpas
    @example Click_RTD_DSPIC.mpas
    @example Click_RTD_AVR.mpas
    @example Click_RTD_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __rtd_driver.h

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