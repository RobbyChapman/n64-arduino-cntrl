
# N64 Arduino Controller

Main controller for &lt;${PROJ_NAME}>

![Alt text](./assets/Controller.jpeg?raw=true "Optional Title")

2012 Michele Perla. He was the original author of N64-To-USB. This repo essentially
wraps his work into an Arduino compatible library. This was done to free up an
existing sketch I am working on for the XBees. N64_To_USB_Atmega16u2 was removed
from this fork as that functionality is outside the scope of this project.

For more information on the original implementation, see below:

https://github.com/MickMad/N64-To-USB


This Arduino application uses the two ATmega on your Arduino to turn it into
an N64 to USB joystick for two controllers; the ATmega328p is used to read 
the status of the two N64 controlers and write it via SPI to the ATmega16u2,
which enumerates as an HID joystick with 4 axis and 36 buttons, reads the 
status of the controllers from the ATmega328p and writes that in a USB packet.

To install it, first plug your Arduino to the USB port, and program it with 
the N64_To_USB.ino sketch in the N64_To_USB folder; plug +3.3v and GND 
from your Arduino to the N64 controllers, plug the DATA line of one controller 
to DIGITAL PIN 2, and the other to DIGITAL PIN 3; then put your Arduino in DFU 
mode (short the two ISP pins for RESET and GND of the ATmega16u2 ISP port, or 
check for further information about it on Google), and program the ATmega16u2 
with the Arduino-joystick.hex file in the N64_To_USB_ATmega16u2 folder. 
After that reset your Arduino and it will no longer enumerate as an Arduino, 
but as Arduino Joystick. Congratulations! Go configure your N64 emulator now!!!

NOTE:Only works with Arduino UNO, or with any Arduino with an Atmega8/16u2 as a
USB transceiver.

The Arduino sketch which reads the status of the N64 controllers is written on
code made by Andrew Brown, Peter Den Hartog; the hex file for the Atmega16u2
is a modification of the Arduino Joystick code made by Darran, using LUFA;

Hope you like it!


Links:
Darran original Arduino Joystick:
http://hunt.net.nz/users/darran/weblog/a3599/Arduino_UNO_Joystick_HID_firmware.html

Andrew Brown instructable:
http://www.instructables.com/id/Use-an-Arduino-with-an-N64-controller/


