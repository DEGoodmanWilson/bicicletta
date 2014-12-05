#include <stdint.h>
#include <aci.h>
#include <aci_cmds.h>
#include <aci_evts.h>
#include <aci_protocol_defines.h>
#include <aci_queue.h>
#include <acilib.h>
#include <acilib_defs.h>
#include <acilib_if.h>
#include <acilib_types.h>
#include <ble_assert.h>
#include <boards.h>
#include <dtm.h>
#include <hal_aci_tl.h>
#include <hal_platform.h>
#include <lib_aci.h>
#include <aci_setup.h>

#include <RBL_nRF8001.h>

#include <SPI.h>

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
