---
layout: post
title:  "Battery Power module"
date:   2014-11-29 11:57:12
categories: module
---
The Battery Power module draws power from the bicycle's battery, and provides 5V @ 500mA for consumption by the Bicicletta stack.

#Provides

* 5V @ 500mA (max) power

#Requires

* CA3 connection to motor controller

##Summary

At the heart of the Battery Power module is the [TI LM5574][LM5574] buck regulator, which takes the high voltage power from the battery, and provides low-voltage power to the MCU and other bicycle accessories. The LM5574 has been configured for optimium efficiency with 24--48V battery packs.

The Battery Power module is also where the CA3 wiring harness is attached. The CA3 connection is how Bicicletta communicates with the electric bicycle's motor controller, and is a standardized connection often available as an option on most Chinese and custom motor controllers.

##Illustration

![Board outline](../images/bicicletta-power-thumb.png 'Board outline')


[LM5574]:     http://www.ti.com/product/lm5574
