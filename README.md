![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# RTD Click

- **CIC Prefix**  : RTD
- **Author**      : Djordje Rosic
- **Verison**     : 1.0.0
- **Date**        : Nov 2017

---

### Software Support

We provide a library for the RTD Click on our [LibStock](https://libstock.mikroe.com/projects/view/2240/rtd-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

This library contains functions for basic reading and writing into the click's registers,
as well as convert temperature function that can convert raw data into degrees celsius.
Check documentation for more details.

Key functions :

- ``` void rtd_writeRegister(uint8_t regAddress, uint8_t writeData) ``` - Writes data into a register
- ``` uint16_t rtd_readTemperature() ``` - Reads temperature from temperature registers
- ``` float rtd_convertTemperature(uint16_t inputData, uint16_t referentResistance) ``` - Converts raw data to degrees celsius

**Examples Description**

The application is composed of three sections :

- System Initialization - Initializes SPI peripheral, CS pin, and UART logger
- Application Initialization - Initializes RTD click driver, and sets the
                               proper configuration mode for three wire RTD.
- Application Task (code snippet) - Measures temperature, converts the data to celsius degrees,
                     and outputs them via UART.


```.c
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
```


The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/2240/rtd-click) page.

Other mikroE Libraries used in the example:

- UART
- Conversions
- C_string

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
---
