---
layout: post
title:  "The Bicicletta Project"
date:   2014-11-29 11:57:12
categories: update
---
Bicicletta is a project to provide an iOS / Android interface to you electric bicycle.

#Motivation

I've got this great electric bicycle that I put together from a kit. It has a battery, a motor, a motor controller (something of a black box full of electronics for making the motor spin), and some controls on the handlebar. Barebones, to be sure.

I want to build an ass-kicking interface to this kit. I want to know:

* How much battery do I have left?
* How hard am I pushing the battery?
* How fast am I going?

In addition, I want to be able to:

* Program my own throttle response curve
* Use a torque sensor in the pedals to feel like the 6-Million-Dollar Man when I hit the hills
* Maybe even lock the bike electronically

And, I want to do all of this with my iPhone.

#Tech Stack

To make this happen, I am starting with the [RedBearLab Blend Micro][blend]. This Arduino Leonardo-compatible board is tiny, and includes a built-in [Bluetooth Low Energy (BLE)][ble] radio for talking to modern smartphones.

But, as awesome as this little board is, it needs some help…I'll need to build three things to make this project work:

* More hardware
* Firmware to drive the hardware
* An iOS app

I've already started on the hardware. The firmware and app will follow closely behind.

##Hardware

The hardware has several tasks to perform. These tasks are complicated by the fact that the bicycle components are all 5V signals, whereas the Blend Micro is a 3.3V device, so level-shifters must be employed on all inputs and outputs.

* Measure battery voltage
* Measure motor current
* Measure bicycle speed
* Measure motor temperature
* Sense throttle position
* Sense auxiliary inputs
* Measure torque on pedals
* Measure speed of pedal crank
* Send speed signal to motor controller

Moreover, I want the hardware to take a modular design, with boards about the same size as the Blend Micro (roughly the size of a stick of gum). A modular design allows incremental improvements in functionality, without disturbing what already works. I anticipate building out at least four modules containing circuits needed to perform the tasks listed above.

##Firmware

Being an Arduino, the Blend Micro is dead easy to program using the Arduino IDE. However, I hate the Arduino IDE and would much rather use Atmel Studio to develop the firmware. Unfortunately, there is no ISP header available on the Blend Micro (although the SPI pins are broken out, so this could be dealt with on a breadboard), and I'm not yet familiar enough with the Blend Micro's bootloader to know how easy it will be to develop code outside of the Arduino IDE, and still have access to the more interesting functionality of the board. This all remains to be seen.

##App

I've never written an iOS or Android app before, so I'm excited about the possibilities here. I want first and foremost to be able to provide an easy-to-read interface to the bicycle. I have a handlebar mount for my phone, and I'd like the important numbers (voltage, current, speed, temperature) to be large, and clearly legible.

I'd also like to be able to see a map of my surroundings, possibly with bicycle routes highlighted. It would be nice to be able to take advantage of the buttons and switches I already have mounted on the handlebars to switch between display modes, so that I don't have to take my hands off the handlebars for common or frequent interactions with the app.

Finally, it would be nice if my phone could act as a kind of ignition switch, such that the motor would not spin without the phone's physical presence. This kind of behavior is supported by Bluetooth Low Energy, but it remains to be seen whether I can lock the rear wheel without draining the battery.

[blend]: http://redbearlab.com/blendmicro/
[ble]: http://en.wikipedia.org/wiki/Bluetooth_low_energy