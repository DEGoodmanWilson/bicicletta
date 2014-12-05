#include <SPI.h>
#include <RBL_nRF8001.h>

#include "bicicletta.h"
#include "rs_ble.h"

void setup(void) {
  Serial.begin(57600);
  Serial.print("Bicicletta v");
  Serial.print(PROTOCOL_MAJOR);
  Serial.print(".");
  Serial.print(PROTOCOL_MINOR);
  Serial.print(".");
  Serial.println(PROTOCOL_BUGFIX);

  //Initialize BLE
  rs_ble_init();

  //Initialize SPI communication with battery power IC
}

void loop(void) {
  rs_ble_process();
}
