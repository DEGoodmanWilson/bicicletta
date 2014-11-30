---
layout: post
title:  "The Bicicletta Project"
date:   2014-11-29 11:57:12
categories: update
---
Bicicletta is a project to provide an iOS / Android interface to you electric bicycle.

##Motivation

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

##Tech Stack

To make this happen, I am starting with the [RedBearLab Blend Micro][blend]. This Arduino Leonardo-compatible board is tiny, and includes a built-in [Bluetooth Low Energy (BLE)][ble] radio for talking to modern smartphones.

But, as awesome as this little board is, it needs some help…I'll need to build three things to make this project work:

* More hardware
* Firmware to drive the hardware
* An iOS app

I've already started on the hardware. The firmware and app will follow closely behind.

[blend]: http://redbearlab.com/blendmicro/
[ble]: http://en.wikipedia.org/wiki/Bluetooth_low_energy