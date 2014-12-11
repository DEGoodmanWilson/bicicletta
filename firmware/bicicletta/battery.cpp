//ble_busy is the key func to check
#include "battery.h"
#include <RBL_nRF8001.h>

void battery_init(void)
{
}

void battery_process(void)
{
  if(ble_busy()) { return; }
}
   // // No input data, no commands, process analog data
   //  if (!ble_connected())
   //      queryDone = false; // reset query state

   //  if (queryDone) // only report data after the query state
   //  {
   //      byte input_data_pending = reportDigitalInput();
   //      if (input_data_pending)
   //      {
   //          ble_do_events();
   //          buf_len = 0;

   //          return; // only do this task in this loop
   //      }

   //      reportPinAnalogData();

   //      ble_do_events();
   //      buf_len = 0;

   //      return;
   //  }
