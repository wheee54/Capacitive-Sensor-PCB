# Capacitive-Sensor-PCB
Demo Project for NUS Shape of Sound Class

This project is based on the (1) USBMIDI library for Arduino by Blokas [Link: https://github.com/BlokasLabs/USBMIDI] and (2) Electronics as Material Touch Sensor example by clementzheng [Link: https://github.com/clementzheng/Electronics-As-Material]

## Hardware

The dreamer nano microcontroller [Link: https://www.dfrobot.com/product-786.html] is used as a midi device and needs to be connected to a VST via USB.
The PCB files have headers for the microcontoller and also features a built in touch sensor into the top copper layer.

## Code

The .h files required should be downloaded before use.
It is recommended to uncomment the Serial.print lines to read and tune capVal for your specific design.
