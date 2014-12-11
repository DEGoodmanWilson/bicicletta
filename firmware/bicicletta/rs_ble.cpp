#include <WProgram.h>

#include <aci.h>
#include <aci_cmds.h>
#include <aci_evts.h>
#include <aci_protocol_defines.h>
#include <aci_queue.h>
#include <aci_setup.h>
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

#include <RBL_nRF8001.h>

#include <SPI.h>

#include "rs_ble.h"
#include "bicicletta.h"

void rs_ble_init(void)
{
    ble_set_name("Bicicletta");
    ble_begin();
}

static byte buf_len = 0;

void ble_write_string(byte *bytes, uint8_t len)
{
    int j;
    if (buf_len + len > 20)
    {
        for (j = 0; j < 15000; j++)
            ble_do_events();

        buf_len = 0;
    }

    for (j = 0; j < len; j++)
    {
        ble_write(bytes[j]);
        buf_len++;
    }

    if (buf_len == 20)
    {
        for (j = 0; j < 15000; j++)
            ble_do_events();

        buf_len = 0;
    }
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
}
