# Smart Study Table
##### Study Table Project
-------

> **B**asic aim of smart study table concept is to provide good comfortable environment to students while studying. 
Concept also consist a self assessment system by which student can measure certain parameters such as working time, 
average reading speed per page etc.
>#### **C**oncept of _Smart Study Table_ consists following - 
* Working/ Sitting/ Studying time measurement.
* Average Reading time per page.
* Average Writing time per page.
* Adaptive lighting for table.
* Display for clock, reminder, current and yesterday's record.
* Synchronisation of data with PC using serial communication.

>#### Current system consists following major hardware components -
* PIC18F46K22
* HC-05
* HC-SR04
* USB to Serial (TTL) Converter
* LDR
* PIR Sensor
* Gate Controlled Mosfet with high bright LED
* 5V power supply

>#### Repository files description - 
1. **main.c** - _Main program file of pic18._
2. **config.h** - _configuration register definations of controller._
3. **lcd.c** - _4bit mode LCD functions for JHD162 LCD._
4. **lcd.h** - _LCD functiosn declaration._
5. **ST_Schematic.pdf** - _Schematic of main controller._
6. **RT_Schematic.pdf** - _Schematic of reading table controller._
7. **ST_Gerber.zip** - _Gerber file of main controller for PCB manufacturing._
8. **RT_Gerber.zip** - _Gerber file of reading table controller for PCB manufacturing._
