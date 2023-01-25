 /* Copyright 2021 OpenAnnePro community
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

#include <sys/_stdint.h>
#include "rgb_matrix.h"
#include QMK_KEYBOARD_H

enum anne_pro_layers {
  _BASE_LAYER,
  _WIFE_LAYER,
  _NO_ESC_LAYER,
  _CAPS_LAYER,
  _FN1_LAYER,
  _FN2_LAYER,
  _TAP2_LAYER,
  _FNX_LAYER,
};

enum custom_codes {
  KC_AP_WIN = AP2_SAFE_RANGE,
  KC_AP_LIN,
  KC_AP_MAC,
};

enum tap_dance_codes {
  KC_AP_TD_RCTRL
};

// clang-format off
// Key symbols are based on QMK. Use them to remap your keyboard
/*
* Layer BASE
* ,-----------------------------------------------------------------------------------------.
* | esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |    Bksp   |
* |-----------------------------------------------------------------------------------------+
* | Tab    |  q  |  w  |  e  |  r  |  t  |  y  |  u  |  i  |  o  |  p  |  [  |  ]  |   \    |
* |-----------------------------------------------------------------------------------------+
* | Caps    |  a  |  s  |  d  |  f  |  g  |  h  |  j  |  k  |  l  |  ;  |  '  |    Enter    |
* |-----------------------------------------------------------------------------------------+
* | Shift      |  z  |  x  |  c  |  v  |  b  |  n  |  m  |  ,  |  .  |  /  |    Shift       |
* |-----------------------------------------------------------------------------------------+
* | Ctrl  |  L1   |  Alt  |               space             |  Alt  |  FN1  |  FN2  | Ctrl  |
* \-----------------------------------------------------------------------------------------/
* Layer TAP in BASE
* ,-----------------------------------------------------------------------------------------.
* |     |     |     |     |     |     |     |     |     |     |     |     |     |           |
* |-----------------------------------------------------------------------------------------+
* |        |     |     |     |     |     |     |     |     |     |     |     |     |        |
* |-----------------------------------------------------------------------------------------+
* |         |     |     |     |     |     |     |     |     |     |     |     |             |
* |-----------------------------------------------------------------------------------------+
* |            |     |     |     |     |     |     |     |     |     |     |       UP       |
* |-----------------------------------------------------------------------------------------+
* |       |       |       |                                 |       |  LEFT | DOWN  | RIGHT |
* \-----------------------------------------------------------------------------------------/
*/
 const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE_LAYER]  = LAYOUT_60_ansi(/* Base */
        KC_GRAVE, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, LT(_TAP2_LAYER, KC_BSLS),
        LT(_CAPS_LAYER, KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
        KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, TT(_FN1_LAYER), LT(_FN2_LAYER, KC_APP), KC_RALT, TD(KC_AP_TD_RCTRL)),
    [_WIFE_LAYER]  = LAYOUT_60_ansi(/* Base */
        KC_GRAVE, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, LT(_TAP2_LAYER, KC_BSLS),
        LT(_CAPS_LAYER, KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_UP,
        KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, TT(_FN1_LAYER), KC_LEFT, KC_DOWN, KC_RIGHT),
    [_NO_ESC_LAYER]  = LAYOUT_60_ansi(/* Base */
        KC_GRAVE, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, LT(_TAP2_LAYER, KC_BSLS),
        TT(_CAPS_LAYER), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
        KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, TT(_FN1_LAYER), LT(_FN2_LAYER, KC_APP), KC_RALT, TD(KC_AP_TD_RCTRL)),
    [_CAPS_LAYER] = LAYOUT_60_ansi(/* Hold CapsLock */
        _______, _______, _______, _______, _______, KC_AUDIO_VOL_DOWN, KC_AUDIO_MUTE, KC_AUDIO_VOL_UP, KC_BRID, KC_BRIU, _______, _______, _______, KC_DELETE,
        _______, _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______, _______, KC_HOME, KC_END, _______,
        _______, _______, _______, LCTL(KC_D), LCTL(KC_F), _______, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_PGUP, KC_PGDN, _______,
        _______, _______, _______, _______, LCTL(KC_V), LCTL(KC_B), _______, _______, _______, KC_INSERT, KC_DELETE, _______,
        _______, _______, _______, _______, _______, _______, _______, _______),
    [_FN1_LAYER]   = LAYOUT_60_ansi(/* FN1 */
        _______, _______, _______, _______, _______, _______, _______, _______, KC_KP_ASTERISK, KC_NUM_LOCK, KC_KP_0, KC_KP_MINUS, KC_KP_PLUS, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_KP_7, KC_KP_8, KC_KP_9, _______, _______, _______, _______,
        _______, _______, _______, KC_AP_WIN, _______, _______, _______, KC_KP_4, KC_KP_5, KC_KP_6, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_SLASH, KC_UP,
        _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT),
    [_FN2_LAYER]   = LAYOUT_60_ansi(/* FN2 */
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PSCR, KC_HOME, KC_END, RGB_TOG,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PGUP, KC_PGDN, RGB_MOD,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_VAI,
        _______, _______, _______, _______, TT(_FNX_LAYER), _______, _______, _______),
    [_TAP2_LAYER]   = LAYOUT_60_ansi(/* Hold |\ */
        KC_ESC,  KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, _______,
        _______, KC_MS_BTN1, KC_MS_UP, KC_MS_BTN2, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        KC_CAPS, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_MS_WH_DOWN, _______, KC_MS_WH_UP, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______),
    [_FNX_LAYER]   = LAYOUT_60_ansi(/* Holding FN2 => FN1 at the same time */
        KC_AP2_USB, KC_AP2_BT1, KC_AP2_BT2, KC_AP2_BT3, KC_AP2_BT4, KC_AP2_BT_UNPAIR, _______, _______, _______, RGB_SPD, RGB_SPI, _______, _______, DB_TOGG,
	_______, _______, DF(_WIFE_LAYER), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        DF(_NO_ESC_LAYER), _______, _______, KC_AP_WIN, _______, _______, _______, _______, _______, KC_AP_LIN, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_AP_MAC, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______),
};
// clang-format on

void keyboard_post_init_user(void) {
    // ap2_led_enable();
    // ap2_led_set_profile(7);
    debug_enable = false;
}

/*
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case FN1:
            // Set the leds to green
            ap2_led_set_foreground_color(0x00, 0xFF, 0x00);
            break;
        case FN2:
            // Set the leds to blue
            ap2_led_set_foreground_color(0x00, 0x00, 0xFF);
            break;
        default:
            // Reset back to the current profile
            ap2_led_reset_foreground_color();
            break;
    }
    return state;
}
*/

// The function to handle the caps lock logic
// It's called after the capslock changes state or after entering layers 1 and 2.
bool led_update_user(led_t leds) {
    if (leds.caps_lock) {
        // Set the caps-lock to red
        const ap2_led_t color = {.p.red = 0xff, .p.green = 0x00, .p.blue = 0x00, .p.alpha = 0xff};

        ap2_led_mask_set_key(2, 0, color);
        /* NOTE: Instead of colouring the capslock only, you can change the whole
           keyboard with ap2_led_set_foreground_color */
    } else {
        // Reset the capslock if there is no layer active
        if (!layer_state_is(_FN1_LAYER) && !layer_state_is(_FN2_LAYER)) {
            const ap2_led_t color = {.p.red = 0xff, .p.green = 0x00, .p.blue = 0x00, .p.alpha = 0x00};
            ap2_led_mask_set_key(2, 0, color);
        }
    }

    return true;
}

#ifdef UCIS_ENABLE
void dance_cln_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        // tap 3 times to start unicode input
        qk_ucis_start();
    } else {
        register_code(KC_RCTL);
    }
}
#endif

void dance_cln_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count != 3) {
        unregister_code(KC_RCTL);
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
#ifdef UCIS_ENABLE
    [KC_AP_TD_RCTRL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset),
#endif
};


#ifdef UCIS_ENABLE
const qk_ucis_symbol_t ucis_symbol_table[] = UCIS_TABLE(
    UCIS_SYM("poop", 0x1F4A9),                  // 💩
    UCIS_SYM("rofl", 0x1F923),                  // 🤣
    UCIS_SYM("tm", 0x2122),                     // ™
    UCIS_SYM("copy", 0x00A9),                   //©
    UCIS_SYM("look", 0x0CA0, 0x005F, 0x0CA0),   // ಠ_ಠ
    UCIS_SYM("euro", 0x20AC),                   // €
    UCIS_SYM("shrug", 0xAF, 0x5C, 0X5F, 0x28, 0x30C4, 0x29, 0x5F, 0x2F, 0xAF),  // ¯\_(ツ)_/¯
    UCIS_SYM("sweat", 0x1F605),                  // 😅
    UCIS_SYM("kiss", 0x1F48B),                   // 💋
    UCIS_SYM("wave", 0x1F44B),                   // 👋
    UCIS_SYM("thumb", 0x1F44D),                  // 👍
    UCIS_SYM("up", 0x2B06, 0xFE0F),              // ⬆
    UCIS_SYM("down", 0x2B07, 0xFE0F),             // ⬆
    UCIS_SYM("flip", 0x28, 0x256F, 0xB0, 0x25A1, 0xB0, 0x29, 0x256F, 0xFE35, 0x20, 0x253B, 0x2501, 0x253B),             // (╯°□°)╯︵ ┻━┻
    UCIS_SYM("face",0x28, 0x20, 0x360, 0xB0, 0x20, 0x35F, 0x296, 0x20, 0x361, 0xB0, 0x29)  // ( ͠° ͟ʖ ͡°)
);
#endif

void matrix_init_user(void) {
#ifdef UCIS_ENABLE
    set_unicode_input_mode((uint8_t)UC_LINX);
#endif
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_AP_WIN:
      if (record->event.pressed) {
        default_layer_set(1 << _BASE_LAYER);
        // requires installation of
        // https://github.com/samhocevar/wincompose
        // on Windows machine
#ifdef UCIS_ENABLE
        set_unicode_input_mode((uint8_t)UC_WINC);
#endif
      }
      return false;
    case KC_AP_LIN:
      if (record->event.pressed) {
        default_layer_set(1 << _BASE_LAYER);
#ifdef UCIS_ENABLE
        set_unicode_input_mode((uint8_t)UC_LINX);
#endif
      }
      return false;
    case KC_AP_MAC:
      if (record->event.pressed) {
        default_layer_set(1 << _BASE_LAYER);
#ifdef UCIS_ENABLE
        set_unicode_input_mode((uint8_t)UC_MAC);
#endif
      }
      return false;
    default:
      return true; // Process all other keycodes normally
  }
}
