//ble_busy is the key func to check
#include "battery.h"
#include <RBL_nRF8001.h>

void battery_init(void)
{
  SPI.begin();
  
  SPI.setDataMode(SPI_MODE1);
  SPI.setBitOrder(MSBFIRST);
}

void battery_process(void)
{
  if(ble_busy()) { return; }
  uint8_t val1, val2, val3, val4;
  
  digitalWrite(13, LOW);
  SPI.transfer(0x80);
  SPI.transfer(0x0C);
  val1 = SPI.transfer(0x00); //read it back out
  digitalWrite(13, HIGH);
  
  digitalWrite(13, LOW);
  SPI.transfer(0x80);
  SPI.transfer(0x0D);
  val2 = SPI.transfer(0x00); //read it back out
  digitalWrite(13, HIGH);
  
//  digitalWrite(13, LOW);
//  SPI.transfer(0x82);
//  SPI.transfer(0x01);
//  val3 = SPI.transfer(0x00); //read it back out
//  digitalWrite(13, HIGH);
//  
//  digitalWrite(13, LOW);
//  SPI.transfer(0x82);
//  SPI.transfer(0x00);
//  val4 = SPI.transfer(0x00); //read it back out
//  digitalWrite(13, HIGH);
  
  Serial.println(val1);
  Serial.println(val2);
//  Serial.println(val3);
//  Serial.println(val4);
  Serial.println("###");
}
