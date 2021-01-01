/*
    Copyright (C) 2020 Yaotian Feng, Codetector<codetector@codetector.cn>

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#include "annepro2_ble.h"
#include "ch.h"
#include "hal.h"
#include "host.h"
#include "host_driver.h"

/* -------------------- Static Function Prototypes -------------------------- */
static uint8_t ap2_ble_leds(void);
static void ap2_ble_mouse(report_mouse_t *report);
static void ap2_ble_system(uint16_t data);
static void ap2_ble_consumer(uint16_t data);
static void ap2_ble_keyboard(report_keyboard_t *report);

static void ap2_ble_swtich_ble_driver(void);

/* -------------------- Static Local Variables ------------------------------ */
static host_driver_t ap2_ble_driver = {
    ap2_ble_leds,   ap2_ble_keyboard, ap2_ble_mouse,
    ap2_ble_system, ap2_ble_consumer,
};

static uint8_t bleMcuWakeup[11] = {0x7b, 0x10, 0x53, 0x10, 0x03, 0x00,
                                   0x01, 0x7d, 0x02, 0x01, 0x02};
static uint8_t bleMcuStartBroadcast[11] = {
    0x7b, 0x10, 0x53, 0x10, 0x03, 0x00,
    0x00, 0x7d, 0x40, 0x01, 0x00 // Broadcast ID[0-3]
};
static uint8_t bleMcuConnect[11] = {
    0x7b, 0x10, 0x53, 0x10, 0x03, 0x00,
    0x00, 0x7d, 0x40, 0x04, 0x00 // Connect ID [0-3]
};
static uint8_t bleMcuSendReport[10] = {
    0x7b, 0x10, 0x53, 0x10, 0x0A, 0x00, 0x00, 0x7d, 0x10, 0x04,
};
static uint8_t bleMcuUnpair[10] = {
    0x7b, 0x10, 0x53, 0x10, 0x02, 0x00, 0x00, 0x7d, 0x40, 0x05,
};

static host_driver_t *lastHostDriver = NULL;
#ifdef NKRO_ENABLE
static bool lastNkroStatus = false;
#endif // NKRO_ENABLE

/* -------------------- Public Function Implementation ---------------------- */

void annepro2_ble_startup(void) { sdWrite(&SD1, bleMcuWakeup, 11); }

void annepro2_ble_broadcast(uint8_t port) {
  if (port > 3) {
    port = 3;
  }
  // sdPut(&SD1, 0x00);
  sdWrite(&SD1, bleMcuStartBroadcast, 10);
  sdPut(&SD1, port);
  static int lastBroadcast = -1;
  if (lastBroadcast == port) {
    annepro2_ble_connect(port);
  }
  lastBroadcast = port;
}

void annepro2_ble_connect(uint8_t port) {
  if (port > 3) {
    port = 3;
  }
  sdWrite(&SD1, bleMcuConnect, 10);
  sdPut(&SD1, port);
  ap2_ble_swtich_ble_driver();
}

void annepro2_ble_disconnect(void) {
  /* Skip if the driver is already enabled */
  if (host_get_driver() != &ap2_ble_driver) {
    return;
  }

  clear_keyboard();
#ifdef NKRO_ENABLE
  keymap_config.nkro = lastNkroStatus;
#endif
  host_set_driver(lastHostDriver);
}

void annepro2_ble_unpair(void) {
  // sdPut(&SD1, 0x0);
  sdWrite(&SD1, bleMcuUnpair, 11);
}

/* ------------------- Static Function Implementation ----------------------- */
static void ap2_ble_swtich_ble_driver(void) {
  if (host_get_driver() == &ap2_ble_driver) {
    return;
  }
  clear_keyboard();
  lastHostDriver = host_get_driver();
#ifdef NKRO_ENABLE
  lastNkroStatus = keymap_config.nkro;
#endif
  keymap_config.nkro = false;
  host_set_driver(&ap2_ble_driver);
}

static uint8_t ap2_ble_leds(void) {
  return 0; // TODO: Figure out how to obtain LED status
}

static void ap2_ble_mouse(report_mouse_t *report) {}

static void ap2_ble_system(uint16_t data) {}

static void ap2_ble_consumer(uint16_t data) {}

/*!
 * @brief  Send keyboard HID report for Bluetooth driver
 */
static void ap2_ble_keyboard(report_keyboard_t *report) {
  sdPut(&SD1, 0x0);
  sdWrite(&SD1, bleMcuSendReport, 10);
  sdWrite(&SD1, &report->raw[0], 8);
}
