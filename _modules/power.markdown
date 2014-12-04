---
layout: page
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

This module's job is quite simple: Take the (nominal) 48V battery power, and convert it into a usable 5V.

#Design Notes

There are lots of ways to convert something like 48V to 5V for use as a low-current power signal. Apparently many cheap motor controllers just use a power resistor to an [LM317]. I guess this works OK if you aren't drawing more than a few milliamps, but honestly this is just shoddy design. What is really called for, especially since we don't know the power requirements at this stage (being the first module designed!) is a buck regulator.

I've never designed with switching regulators before, but TI offers a nice offering of simplified ICs in their Simple Switcher line of products. There's a lot of math involved in designing a switching regulator circuit, and a nice feature of this line of products is an online calculator to help you choose the right IC, and the right components to do what you want. It even puts together a Digikey shopping cart for you, so that's helpful.

I wanted to support a wide range of input voltages, from 24V to 75V, and ended up with a design centered around the [LM5574] buck regulator. I used the schematic provided, and borrowed heavily from the reference PCB layout, modified to fit within the very small board outline of the Blend Micro, so I could stack them.

I was pleasantly surprised upon soldering up the first prototype board that it worked nearly perfectly from the start. The measured voltage is a bit low for my liking, about 4.9V rather than 5.0V, but this might just be my cheap Harbor Freight multimeter. Honestly, I doubt it, and suspect that some of the resistors in my order might be a bit too far out of spec, and I might need to go through and measure and replace some of them.

The Battery Power module is also where the CA3 wiring harness is attached. Many motor controllers ship with this harness, which is used to connect to the [Cycle Analyst v3][CA3]---basically, the piece of kit that I am aiming to replace. The CA3 provides battery monitoring and some advanced throttle control, with a UI consisting of a two-line character display and four buttons. Bicicletta is aimed at providing a superset of this functionality, only using your phone as the UI, instead of that tiny display. So it makes sense to piggyback on any standardized cabling already available for this product.

Anyway, the CA3 harness provides 6 lines: Battery voltage, shunt resistor + and - taps, a single-line rotary encoder from the motor's hall sensors for speed, a throttle input to the motor controller, and ground. This module only cares about the battery voltage and ground, but will need to pass along all six lines to other modules in the final stack, so the design includes a new stackable header containing these signals, as well as the mating CA3 cable assembly.

##Illustration

![Board outline](../images/bicicletta-power-thumb.png 'Board outline')

[LM317]:      http://en.wikipedia.org/wiki/LM317
[LM5574]:     http://www.ti.com/product/lm5574
[CA3]:        http://www.ebikes.ca/product-info/grin-products/cycle-analyst-3.html
