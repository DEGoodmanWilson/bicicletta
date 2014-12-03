---
layout: page
title:  "Battery Sensor module"
date:   2014-12-03 10:56:12
categories: module
---
The Battery Sensor module measures battery perfomance, including instantaneous voltage level and current consumption.

#Provides

* Battery status over SPI

#Requires

* 5V
* 3.3V
* Battery voltage (from CA3)
* Battery shunt + and - (from CA3)
* SS line (from Blend Micro)

##Summary

##Design Notes

There are a number of potentially cool power monitors on the market, but only the LMP92064 would actually work in this project. I considered a discrete design from rail-to-rail op-amps, but I don't really trust my math on the various factors that entails (gain and bias calculations) to get the battery voltage (which on my bicycle can vary from 42.5V to 54.6V) compressed to a range the AVR's ADC could sample with any accuracy. So I decided on a dedicated IC with digital outputs (SPI or I2C).

Linear makes a couple of really attractive power monitors with I2C interfaces, the [LTC2945] and [LTC2946]. They offer bus voltage monitoring up to 75V or 100V (depending on the model), and can be powered directly from the battery. Unfortunately, these multiple the voltage sensor and one of the current shunt sensor leads, meaning that the chips can only sense current on the high side. THe motor controllers I am working with provide their own low-side current shunt resistor, so these awesome-looking chips are off the table.

TI makes some very compact power monitors that can be hooked directly into the battery voltage, such as the [INA220]. Unfortunately, they all max out at 26V, whereas my batteries are 50 models, and I want something that could potentially monitor even larger batteries than that.

The [LMP92064] does all of this. It can monitor voltages arbitrarily high, and do low-side current sensing. But it has a couple of drawbacks, none of them showstoppers thankfully. First, it uses SPI instead of I2C. Normally, I don't have a preference between these two, but the BLE radio on the Blend Micro uses an erstaz SPI protocol that requires some hackish workarounds in software to be fully compatible with other SPI devices. Second, this is a 5V part, so we'll also need a voltage translator so that it can talk on the 3.3V SPI bus the MCU participates in, an additional cost.

So, since it is the only one that works, I went for the [LMP92064]. I chose the well-received [TXB0108] for the voltage translator. This chip offers automatic bi-directional signalling---not really necessary in this application, but a nice to have---with a very high (100Mbs) throughput on totem-pole lines (like, say, SPI).

That said, I'm still on the lookout for a chip like the [LTC2945] that can handle low-side current monitoring independent of the voltage monitoring, with an I2C interface.

##Illustration

![Board outline](../images/bicicletta-battery-sensor-thumb.png 'Board outline')

[LTC2945]:      http://www.linear.com/product/LTC2945
[LTC2946]:      http://www.linear.com/product/LTC2946
[INA220]:       http://www.ti.com/product/ina220
[LMP92064]:     http://www.ti.com/product/lmp92064
[TXB0108]:      http://www.ti.com/product/txb0108
