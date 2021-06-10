 /* Copyright 2020 Josef Adamcik
  * Modification for VIA support and RGB underglow by Jens Bonk-Wiltfang
  *
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 2 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
  */

#include QMK_KEYBOARD_H

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),           ENCODER_CCW_CW(KC_PGDN, KC_PGUP) },
    [1] = { ENCODER_CCW_CW(KC_BRID, KC_BRIU),           ENCODER_CCW_CW(_______, _______) },
    [2] = { ENCODER_CCW_CW(_______, _______),           ENCODER_CCW_CW(_______, _______) },
    [3] = { ENCODER_CCW_CW(_______, _______),           ENCODER_CCW_CW(_______, _______) },
    [4] = { ENCODER_CCW_CW(_______, _______),           ENCODER_CCW_CW(_______, _______) }
};
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Space  /       \Enter \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[0] = LAYOUT(
  KC_GRV,         KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_MINS,
  LT(1, KC_TAB),  KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  LT(1, KC_BSLS),
  LSFT_T(KC_ESC), KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                       KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  RSFT_T(KC_QUOT),
  KC_LALT,        KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,     _______, KC_N,    KC_M,    KC_COMM,  KC_DOT, KC_SLSH,  KC_RALT,
                          KC_MENU, KC_LGUI, KC_LCTL, KC_SPACE, KC_BSPC,    KC_RGUI, KC_ENT,  KC_RCTL, KC_RALT, MO(2)
),
/*
 * CAPS HELD
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   F  |   P  |   G  |                    |   J  |   L  |   U  |   Y  |   ;  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   A  |   R  |   S  |   T  |   D  |-------.    ,-------|   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   K  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `-----------------------------------'           '------''---------------------------'
 */

[1] = LAYOUT(
  _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,   KC_F5,                        KC_F6,      KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,
  KC_UNDO,  KC_WREF,  KC_BTN3,  KC_MS_U,  KC_BTN2, _______,                      KC_CIRC,    KC_LBRC,  KC_RBRC,  KC_HOME,  KC_END,   KC_F12,
  KC_CAPS,  KC_WHOM,  KC_MS_L,  KC_MS_D,  KC_MS_R, _______,                      KC_LEFT,    KC_DOWN,  KC_UP,    KC_RGHT,  KC_DEL,   KC_BSPC,
  KC_WBAK,  KC_WFWD,  KC_WH_D,  _______,  KC_WH_U, _______, _______,    _______, KC_ASTR,    KC_LPRN,  KC_RPRN,  KC_AMPR,  _______,  _______,
                KC_MPRV,        KC_MPLY,  KC_MNXT, _______, KC_DEL,     _______, _______, _______, _______, _______
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | Shift|  =   |  -   |  +   |   {  |   }  |-------|    |-------|   [  |   ]  |   ;  |   :  |   \  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[2] = LAYOUT(
  _______,  _______,  _______,  _______,  _______, _______,                      _______,    _______,    _______,    _______,    _______,  _______,
  KC_TAB,  KC_INS,    KC_APP,   _______,  _______, _______,                      _______,    _______,    _______,    _______, _______,  KC_BSLS,
  KC_LSFT,  KC_PSCR,  _______,  _______,  _______, _______,                      _______,    _______,    _______,    _______,    _______,  KC_RSFT,
  _______,  _______,  _______,  _______,  _______, _______, _______,      _______,_______,    _______, _______,  _______, _______,  _______,
                _______,_______,_______,_______, _______,      _______,  _______, _______, _______, _______
),
/* RAISE
 * ,----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc  | Ins  | Pscr | Menu |      |      |                    |      | PWrd |  Up  | NWrd | DLine| Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  | LAt  | LCtl |LShift|      | Caps |-------.    ,-------|      | Left | Down | Rigth|  Del | Bspc |
 * |------+------+------+------+------+------|  MUTE  |   |       |------+------+------+------+------+------|
 * |Shift | Undo |  Cut | Copy | Paste|      |--------|   |-------|      | LStr |      | LEnd |      | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[3] = LAYOUT(
  _______, _______ , _______ , _______ , _______ , _______,                           _______,  _______  , _______,  _______ ,  _______ ,_______,
  _______,  KC_INS,  KC_PSCR,   KC_APP,  XXXXXXX, XXXXXXX,                        KC_PGUP, _______,   KC_UP, _______,_______, KC_BSPC,
  _______, KC_LALT,  KC_LCTL,  KC_LSFT,  XXXXXXX, KC_CAPS,                       KC_PGDN,  KC_LEFT, KC_DOWN, KC_RGHT,  KC_DEL, KC_BSPC,
  _______,KC_UNDO, KC_CUT, KC_COPY, KC_PASTE, XXXXXXX,  _______,       _______,  XXXXXXX, _______, XXXXXXX, _______,   XXXXXXX, _______,
                         _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),


/*
 * CAPS HELD
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   F  |   P  |   G  |                    |   J  |   L  |   U  |   Y  |   ;  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   A  |   R  |   S  |   T  |   D  |-------.    ,-------|   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   K  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `-----------------------------------'           '------''---------------------------'
 */

[4] = LAYOUT(
  _______,  _______,  _______,  _______,  _______, _______,                      _______,    _______,    _______,    _______,    _______,  _______,
  _______,  _______,  _______,  _______,  _______, _______,                      _______,    _______,    _______,    _______, _______,  _______,
  _______,  _______,  _______,  _______,  _______, _______,                      _______,    _______,    _______,    _______,    _______,  _______,
  _______,  _______,  _______,  _______,  _______, _______, _______,      _______,_______,    _______, _______,  _______, _______,  _______,
                _______,_______,_______,_______, _______,      _______,  _______, _______, _______, _______
),
};

#ifdef OLED_ENABLE
#include "matrix.h"
#include OLED_FONT_H

extern matrix_row_t matrix[MATRIX_ROWS];

#define ANIM_FRAME_DURATION 100
#define IDLE_FRAMES 5
#define IDLE_TIMEOUT 750
#define SLEEP_TIMEOUT 15000

static bool OLED_redraw = true;

static const uint8_t bongofont[] PROGMEM = {
    0xC1, 0xC1, 0xC2, 0x04, 0x08, 0x10,
    0xC0, 0x38, 0x04, 0x03, 0x00, 0x00,
    0xA0, 0x22, 0x24, 0x14, 0x12, 0x12,
    0xA0, 0x21, 0x22, 0x12, 0x11, 0x11,
    0x83, 0x7C, 0x41, 0x41, 0x40, 0x40,
    0x82, 0x82, 0x84, 0x08, 0x10, 0x20,
    0x80, 0x80, 0x00, 0x00, 0x00, 0x00,
    0x80, 0x70, 0x19, 0x06, 0x00, 0x00,
    0x80, 0x70, 0x0C, 0x03, 0x00, 0x00,
    0x80, 0x00, 0x30, 0x30, 0x00, 0xC0,
    0x80, 0x00, 0x30, 0x30, 0x00, 0x00,
    0x49, 0x88, 0x08, 0x08, 0x08, 0x00,
    0x44, 0x84, 0x04, 0x04, 0x00, 0x00,
    0x40, 0x80, 0x00, 0x00, 0x00, 0x00,
    0x40, 0x40, 0x20, 0x20, 0x20, 0x20,
    0x3C, 0xC2, 0x01, 0x01, 0x02, 0x02,
    0x35, 0x01, 0x8A, 0x7C, 0x00, 0x00,
    0x20, 0x40, 0x80, 0x00, 0x00, 0x00,
    0x20, 0x21, 0x22, 0x12, 0x11, 0x11,
    0x20, 0x20, 0x10, 0x10, 0x10, 0x10,
    0x1E, 0xE1, 0x00, 0x00, 0x01, 0x01,
    0x1C, 0xE2, 0x01, 0x01, 0x02, 0x02,
    0x18, 0x64, 0x82, 0x02, 0x02, 0x02,
    0x18, 0x60, 0x80, 0x00, 0x00, 0x00,
    0x18, 0x18, 0x1B, 0x03, 0x00, 0x40,
    0x18, 0x06, 0x05, 0x98, 0x99, 0x84,
    0x12, 0x0B, 0x08, 0x08, 0x08, 0x08,
    0x11, 0x09, 0x08, 0x08, 0x08, 0x08,
    0x10, 0x10, 0xD0, 0x11, 0x0F, 0x21,
    0x10, 0x10, 0x10, 0x11, 0x0F, 0x01,
    0x10, 0x08, 0x08, 0x04, 0x04, 0x04,
    0x10, 0x08, 0x04, 0x02, 0x02, 0x04,
    0x0C, 0x30, 0x40, 0x80, 0x00, 0x00,
    0x0C, 0x0C, 0x0D, 0x01, 0x00, 0x40,
    0x08, 0xE8, 0x08, 0x07, 0x10, 0x24,
    0x08, 0x30, 0x40, 0x80, 0x00, 0x00,
    0x08, 0x08, 0x08, 0x07, 0x00, 0x00,
    0x08, 0x08, 0x04, 0x02, 0x02, 0x02,
    0x08, 0x04, 0x02, 0x01, 0x01, 0x02,
    0x05, 0x05, 0x09, 0x09, 0x10, 0x10,
    0x04, 0x38, 0x40, 0x80, 0x00, 0x00,
    0x04, 0x04, 0x08, 0x08, 0x10, 0x10,
    0x04, 0x04, 0x04, 0x04, 0x04, 0x04,
    0x04, 0x04, 0x02, 0x01, 0x00, 0x00,
    0x02, 0x02, 0x81, 0x80, 0x80, 0x00,
    0x02, 0x02, 0x04, 0x04, 0x08, 0x08,
    0x02, 0x02, 0x02, 0x01, 0x01, 0x01,
    0x02, 0x02, 0x01, 0x00, 0x00, 0x00,
    0x01, 0xE1, 0x1A, 0x06, 0x09, 0x31,
    0x01, 0x01, 0x02, 0x04, 0x08, 0x10,
    0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x80, 0x80, 0x00, 0x00, 0x00,
    0x00, 0x80, 0x40, 0x40, 0x20, 0x20,
    0x00, 0x00, 0x80, 0x80, 0x40, 0x40,
    0x00, 0x00, 0x60, 0x60, 0x00, 0x81,
    0x00, 0x00, 0x01, 0x01, 0x00, 0x40,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x18,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x0C,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x03,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00};


static const uint8_t bongo_line_x[] = {51, 49, 48, 57};
static const uint8_t bongo_line_y[] = {0, 8, 16, 24};
static const uint8_t bongo_line_len[] = {5, 7, 8, 6};

const uint8_t bongo_line_data[8][26] PROGMEM = {
    { //idle1
    60, 52, 19, 30, 35,
    22, 47, 51, 60, 9, 0, 17,
    1, 57, 33, 3, 27, 41, 29, 50,
    45, 36, 60, 60, 60, 60},
    { //idle2
    60, 52, 19, 30, 35,
    22, 47, 51, 60, 9, 0, 17,
    1, 57, 33, 3, 27, 41, 29, 50,
    45, 36, 60, 60, 60, 60},
    { //idle3
    60, 53, 14, 31, 23,
    15, 43, 60, 60, 54, 5, 13,
    7, 56, 24, 2, 26, 39, 29, 50,
    45, 36, 60, 60, 60, 60},
    { //idle4
    6, 52, 19, 38, 32,
    20, 47, 51, 60, 9, 0, 17,
    8, 57, 33, 3, 27, 41, 29, 50,
    45, 36, 60, 60, 60, 60},
    { //idle5
    60, 52, 19, 37, 40,
    21, 47, 51, 60, 9, 0, 17,
    8, 57, 33, 3, 27, 41, 29, 50,
    45, 36, 60, 60, 60, 60},
    { //prep
    6, 52, 19, 38, 32,
    20, 44, 51, 60, 10, 48, 16,
    8, 25, 4, 18, 27, 42, 46, 50,
    60, 60, 60, 60, 60, 60},
    { //tap1
    6, 52, 19, 38, 32,
    20, 44, 51, 60, 10, 49, 17,
    8, 25, 4, 18, 27, 41, 28, 11,
    60, 60, 60, 60, 58, 59},
    { //tap2
    6, 52, 19, 38, 32,
    20, 47, 51, 60, 10, 48, 16,
    8, 60, 55, 3, 27, 42, 46, 50,
    45, 34, 12, 60, 60, 60}
};

enum anin_states { sleep, idle, prep, tap };
uint8_t anim_state = idle;
uint32_t idle_timeout_timer = 0;
uint32_t anim_timer = 0;
uint8_t current_idle_frame = 0;
uint8_t current_tap_frame = 6;
uint8_t last_bongo_frame = 12;

void write_bongochar_at_pixel_xy(uint8_t x, uint8_t y, uint8_t data, bool invert) {
    uint8_t i, j, temp;
    for (i = 0; i < 6 ; i++) { // 6 = font width
        temp = pgm_read_byte(&bongofont[data * 6]+i);
        for (j = 0; j < 8; j++) {  // 8 = font height
            if (temp & 0x01) {
                oled_write_pixel(x + i, y + j, !invert);
            } else {
                oled_write_pixel(x + i, y + j, invert);
            }
            temp >>= 1;
        }
    }
}

bool is_key_down(void) {
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        if (matrix[i] > 0) {
            return true;
        }
    }
    return false;
}

void eval_anim_state(void) {
    bool key_down;
    key_down = is_key_down();

    switch (anim_state) {
        case sleep:
            if(key_down) { anim_state = tap; }
            break;
        case idle:
            if(key_down) { anim_state = tap; }
            else if (timer_elapsed32(idle_timeout_timer) >= SLEEP_TIMEOUT) //prep to idle
                {
                    anim_state = sleep;
                    current_idle_frame = 0;
                }
            break;
        case prep:
            if(key_down) { anim_state = tap; }
            else if (timer_elapsed32(idle_timeout_timer) >= IDLE_TIMEOUT) //prep to idle
                {
                    anim_state = idle;
                    current_idle_frame = 0;
                }
            break;
        case tap:
            if (!key_down)
            {
                anim_state = prep;
                idle_timeout_timer = timer_read32();
            }
            break;
        default:
            break;
    }
}

void draw_bongo_table(void) {
    //draws the table edge for bongocat, this edge doesn't change during the animation
    uint8_t i;
    uint8_t y = 31;
    uint8_t j = 0;
    for (i = 17; i < 57; i++) {
        oled_write_pixel(i, y, true); //every five horizontal pixels, move up one pixel to make a diagonal line
        if (j == 4) {
            --y;
            j=0;
        } else {
            j++;
        }
    }

    y=15;
    j=0;
    for (i = 91; i < 128; i++) {

        oled_write_pixel(i, y, true); //every four horizontal pixels, move up one pixel to make a diagonal line
        if (j == 3) {
            --y;
            j=0;
        } else {
            j++;
        }
    }


}


void draw_bongocat_frame(int framenumber) {
    //only redraw if the animation frame has changed
    if (framenumber != last_bongo_frame) {
        last_bongo_frame = framenumber;
        uint8_t i, j, current_bongochar = 0;
        for (i = 0; i < 4; i++) {
            for (j = 0; j < bongo_line_len[i]; j++) {
                write_bongochar_at_pixel_xy(bongo_line_x[i] + j*6, bongo_line_y[i], pgm_read_byte(&bongo_line_data[framenumber][current_bongochar]), false);
                current_bongochar++;
            }
        }
    }

}

bool is_new_tap(void) {
    static matrix_row_t old_matrix[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    bool new_tap = false;
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        if (matrix[i] > old_matrix[i]) { // more 1's detected, there was a new tap
            new_tap = true;
        }
        old_matrix[i] = matrix[i];
    }
    return new_tap;
}

void draw_bongocat(void) {
    static bool already_tapped = false;
    if (is_new_tap()) {
        already_tapped = false;
    };
    eval_anim_state();
    switch (anim_state) {
        case sleep:
            draw_bongocat_frame(4);
            break;
        case idle:
            draw_bongocat_frame(4 - current_idle_frame);
            if (timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
                current_idle_frame = (current_idle_frame + 1) % 5;
                anim_timer = timer_read32();
            }
            break;
        case prep:
            draw_bongocat_frame(5);
            already_tapped = false;
            break;
        case tap:
            draw_bongocat_frame(current_tap_frame);
            if (already_tapped == false) {
                if (current_tap_frame == 6) {
                    current_tap_frame = 7;
                }
                else {
                    current_tap_frame = 6;
                }
            }
            already_tapped = true;
            break;
        default:
            draw_bongocat_frame(4);
            already_tapped = false;
            break;

    }
}

bool oled_right_task_user(void) {

    if (OLED_redraw){
        oled_clear();
        last_bongo_frame = 12; //force a redraw
        draw_bongo_table();
        OLED_redraw = false;
    }
    draw_bongocat();
    return false;
}

static os_variant_t prev_detected_os = OS_UNSURE;

bool process_detected_host_os_kb(os_variant_t detected_os) {
  prev_detected_os = detected_os;
  return true;
}

bool oled_led_task_user(void) {
  oled_write_ln("LAY:", false);

  // Print current layer
  switch (get_highest_layer(layer_state)) {
    case 0:
      oled_write_ln(" bas", false);
      break;
    case 1:
      oled_write_ln(" one", false);
      break;
    case 2:
      oled_write_ln(" two", false);
      break;
    case 3:
      oled_write_ln(" thr", false);
      break;
    case 4:
      oled_write_ln(" for", false);
      break;
    default:
      oled_write_ln(" und", false);
  }

  oled_write_ln("\nOS:", false);
  switch (prev_detected_os) {

    case OS_LINUX:
      oled_write_ln(" lin", false);
      break;
    case OS_WINDOWS:
      oled_write_ln(" win", false);
      break;
    case OS_MACOS:
      oled_write_ln(" mac", false);
      break;
    case OS_IOS:
      oled_write_ln(" ios", false);
      break;
    default:
      oled_write_ln(" ???", false);
      break;
  }

  led_t led_usb_state = host_keyboard_led_state();
  oled_write_ln("\nCAP:", false);
  oled_write_ln(led_usb_state.caps_lock ? " yes" : " no", false);
  oled_write_ln("\nNUM:", false);
  oled_write_ln(led_usb_state.num_lock ? " yes" : " no", false);

  return false;
}

bool oled_task_user(void) {
  if (is_keyboard_left()) {
    return oled_led_task_user();
  }
  return oled_right_task_user();
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (is_keyboard_left()) {
    return rotation;
  }
  return OLED_ROTATION_180;
}


#endif
