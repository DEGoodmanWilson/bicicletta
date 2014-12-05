#include <SPI.h>
#include <RBL_nRF8001.h>

#include "rs_ble.h"
#include "bicicletta.h"

void rs_ble_init(void)
{
    ble_set_name("Bicicletta");
    ble_begin();
}

void rs_ble_process(void)
{
    while (ble_available())
    {
        byte cmd;
        cmd = ble_read();
        Serial.write(cmd);

        // Parse data here
        switch (cmd)
        {
        case 'V': // query protocol version
        {
            byte buf[] = {'V', PROTOCOL_MAJOR, PROTOCOL_MINOR, PROTOCOL_BUGFIX};
            ble_write_string(buf, 4);
        }
        break;

        // send out any outstanding data
        ble_do_events();
        buf_len = 0;

        return; // only do this task in this loop
    }

    // process text data
    if (Serial.available())
    {
        byte d = 'Z';
        ble_write(d);

        delay(5);
        while (Serial.available())
        {
            d = Serial.read();
            ble_write(d);
        }

        ble_do_events();
        buf_len = 0;

        return;
    }

    ble_do_events();
    buf_len = 0;
}