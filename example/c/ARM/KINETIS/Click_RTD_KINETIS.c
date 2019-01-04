/*
Example for RTD Click

    Date          : Nov 2017.
    Author        : Djordje Rosic

Test configuration KINETIS :
    
    MCU              : MK64
    Dev. Board       : HEXIWEAR
    ARM Compiler ver : v6.0.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes SPI peripheral, CS pin, and UART logger
- Application Initialization - Initializes RTD click driver, and sets the
                               proper configuration mode for three wire RTD.
- Application Task - Measures temperature, converts the data to celsius degrees,
                     and outputs them via UART.

*/

#include "Click_RTD_types.h"
#include "Click_RTD_config.h"

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_CS_PIN, _GPIO_OUTPUT );
    mikrobus_spiInit( _MIKROBUS1, &_RTD_SPI_CFG[0] );
    mikrobus_logInit( _MIKROBUS2, 9600 );

    Delay_ms( 100 );
}

void applicationInit()
{
    rtd_spiDriverInit( (T_RTD_P)&_MIKROBUS1_GPIO, (T_RTD_P)&_MIKROBUS1_SPI );
    rtd_writeRegister(_RTD_CONFIGURATION, 0xD0);
}

void applicationTask()
{
    uint16_t readValue;
    float convertedValue;
    char testTxt [20];

    readValue = rtd_readTemperature();
    convertedValue = rtd_convertTemperature(readValue, _RTD_REF_RESISTANCE_470);

    floatToStr(convertedValue, testTxt);
    mikrobus_logWrite("Current temperature: ", _LOG_TEXT );
    mikrobus_logWrite(testTxt, _LOG_LINE );

    delay_ms(1000);
}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
        applicationTask();
    }
}