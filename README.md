# JoystickRC

Thrustmaster T.16000M FCS to PPM Signal for R/C Aircrafts

> There is no warranty for the program. Use at your own risk.



### Equipments

* Thrustmaster T.16000M FCS Joystick
* Jumper T20 Radio Transmitter
* Arduino Uno
* USB Host Shield 2.0



### Connections

PPM output on pin 7

Short these pads on the USB Host Shield:

![img](https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEhviMRAGp6h0vnbZ2_ErEXUL3RXfdZkn_MQgzK0v-S3rGcsUY-zodMHxzRvyD-T3BT2RUaHWvCRhjBP4v9H9WevDsZSQLg0YQn-UXgmkyTSZp-ihoK_rwFiRzEvPdtEUWcvEUPDzNZ0eawj/s1600/usb_host_shield_fix_small.jpg)



### Dependencies

[USB Host Shield Library 2.0](https://github.com/felis/USB_Host_Shield_2.0) by Oleg Mazurov

> Install through Arduino IDE Library Manager



### Credits

JoystickParser is adapted from [Simplified Thrustmaster T.16000M FCS Joystick Report Parser](https://github.com/felis/USB_Host_Shield_2.0/tree/master/examples/HID/t16km) by gdsports.

PPM Encoder is cloned with tiny changes from [PPMEncoder](https://github.com/schinken/PPMEncoder) by schinken.