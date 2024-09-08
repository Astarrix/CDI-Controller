# CD-I RollerController to Mouse (WIP)

## Description
This personal development project aims to update a Philips CD-I Roller Controller for use in Modern Games;
This is done by first mapping the pinout of the controller, and then converting that data into a readable format, and finally executing mouse commands from the arduino, (hence the requirement for the ATMega32u4) making the controller read as a mouse.

## Requirements
* Philips CD-I Roller Controller
* Microcontroller with the ATMega-32u4 chip (i.e Arduino Micro or Leonardo)
* Some Cables to connect the Arduino & The PCB

### Extra Requirements
There is support in the INO file to add these, however they are not necessary and can be disabled easily in the INO file
* 10k Potentiometer for Sensitivity
* SPST Switch for a hardware disable


## Libraries
This allows the data to be read correctly - [Custom Software Serial](https://github.com/ledongthuc/CustomSoftwareSerial)

This allows the mouse to be moved - [Mouse.h](https://downloads.arduino.cc/libraries/github.com/arduino-libraries/Mouse-1.0.1.zip)

## Attribution
CustomSoftwareSerial Library Author - [@ledongthuc](https://github.com/ledongthuc)

Datasheets Used for Development - [ICDIA.co.uk](http://www.icdia.co.uk/docs/pointing_devices.pdf)

I couldn't have created this project without the massive amount of help i recieved from [Dan Williamson](https://uk.linkedin.com/in/daniel-williamson-engineer); He helped me map the pinout of the PCB and interpret the data coming in from it. 


# To Do List:
* Finish Mapping Analog
* Import Mouse
