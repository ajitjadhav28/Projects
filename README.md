# Smart Study Table
##### Study Table Project
-------

**B**asic aim of smart study table concept is to provide good comfortable environment to students while studying. 
Concept also consist a self assessment system by which student can measure certain parameters such as working time, 
average reading speed per page etc.
System consists main controller bord which is connected to [PIR], [Ultrasonic], [LDR] 
sensors and drives LCD, [MOSFET] and [LED]. It is also connected to [Real Time Clock][RTC] and 
[Bluetooth]. [PIR] and Ultrasonic sensors are used to conform the presence of human near 
table or on chair. [LDR] is used to sense the light intensity in invironment. LCD which is 
16x2 is used to display various prameters such as time, reminders and records. [MOSFET] 
is used to drive high bright [LED]. [RTC] module is used for clock and [Bluetooth] module is 
used to transfer data between reading desk and main controller wirelessly.
On reading desk we have another [Ultrasonic] sensor which detects turning of pages 
and counts it. This data is sent to main controller using [Bluetooth] module.

>#### Proposed System Specifications -
1. Adaptive Lighting.
2. Working / Sitting time measurement.
3. Average reading speed per page.
4. Average writing speed per page.
5. Bluetooth communication between reading desk and main controller.
6. Record Synchronisation with PC
7. Setting custom reminders from PC using serial communication.
8. Real Time Clock Display.

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

###### _Note - All PCBs are designed in KiCAD and are single layer._

[PIR]: https://en.wikipedia.org/wiki/Passive_infrared_sensor
[Ultrasonic]: https://docs.google.com/document/d/1Y-yZnNhMYy7rwhAgyL_pfa39RsB-x2qR4vP8saG73rE/edit
[LDR]: https://en.wikipedia.org/wiki/Photoresistor
[MOSFET]: https://en.wikipedia.org/wiki/MOSFET
[Bluetooth]: http://wiki.iteadstudio.com/Serial_Port_Bluetooth_Module_%28Master/Slave%29_:_HC-05
[RTC]: https://en.wikipedia.org/wiki/Real-time_clock
[LED]: https://en.wikipedia.org/wiki/Light-emitting_diode
