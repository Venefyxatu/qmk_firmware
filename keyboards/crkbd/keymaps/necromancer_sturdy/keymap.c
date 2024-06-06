/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifdef CONSOLE_ENABLE
    #include "print.h"
#endif

#include QMK_KEYBOARD_H

#define C_MAGIC QK_AREP
#define C_RCTL_MINS RCTL_T(KC_MINS)
#define C_LCTL_BSPC LCTL(KC_BSPC)
#define C_LALT_ENT LALT_T(KC_ENT)
#define C_RSFT_ENT RSFT_T(KC_ENT)

enum layers {
    BASE,
    SYMB,
    NUMFUNC,
};

/*
enum tap_dance {
    TD_L_SYMB,
    TD_L_NUMFUNC,
};

void tap_dance_numfunc(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 2:
            layer_clear();
            layer_on(NUMFUNC);
            break;
        default:
            set_oneshot_layer(NUMFUNC, ONESHOT_OTHER_KEY_PRESSED);
    }
}

void tap_dance_symbols(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 2:
            layer_clear();
            layer_on(SYMB);
            break;
        default:
            set_oneshot_layer(SYMB, ONESHOT_OTHER_KEY_PRESSED);
    }
}


tap_dance_action_t tap_dance_actions[] = {
    [TD_L_SYMB] = ACTION_TAP_DANCE_FN(tap_dance_symbols),
    [TD_L_NUMFUNC] = ACTION_TAP_DANCE_FN(tap_dance_numfunc),
};
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[BASE] = LAYOUT_split_3x6_3(
  //,----------------------------------------------------------------------------------.                              ,----------------------------------------------------------------------------------.
        KC_V,          KC_M,         KC_L,         KC_C,         KC_P,       KC_SCLN,                                    KC_COMMA,        KC_B,       C_MAGIC,        KC_U,         KC_O,       KC_BSPC,
  //|-------------+-------------+-------------+-------------+-------------+------------|                              |-------------+-------------+-------------+-------------+-------------+------------|
        KC_S,      LCTL_T(KC_T), LALT_T(KC_R), LGUI_T(KC_D), LSFT_T(KC_Y),    KC_Q,                                       KC_SLASH,    RSFT_T(KC_F), RGUI_T(KC_N), RALT_T(KC_E), RCTL_T(KC_A),     KC_I,
  //|-------------+-------------+-------------+-------------+-------------+------------|                              |-------------+-------------+-------------+-------------+-------------+------------|
       KC_TAB,         KC_X,          KC_K,         KC_J,         KC_G,        KC_W,                                       KC_Z,         KC_H,       KC_QUOT,       KC_QUES,       KC_DOT,      _______ ,
  //|-------------+-------------+-------------+-------------+-------------+------------+-------------|  |-------------+-------------+-------------+-------------+-------------+------------+-------------|
                                                              OSL(NUMFUNC),   OSL(SYMB),     KC_SPC,           KC_ENT,       QK_REP,       KC_ESC
                                                          // TD(TD_L_NUMFUNC),   TD(TD_L_SYMB),     KC_SPC,         KC_ENT,       QK_REP,    KC_ESC
                                                          //`----------------------------------------'   `----------------------------------------'
    ),
    [SYMB] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_DEL, KC_QUOT,  KC_LT,   KC_GT,   KC_DQT,  KC_DOT,                      KC_AMPR, KC_GRAVE, KC_LBRC, KC_RBRC, KC_PERC,_______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, KC_EXLM, KC_MINS, KC_PLUS,  KC_EQL,  KC_HASH,                     KC_PIPE, KC_COLN, KC_LPRN, KC_RPRN, KC_QUES, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, KC_CIRC, KC_SLASH, KC_ASTR, KC_BSLS, KC_UNDS,                     KC_TILD, KC_DLR,  KC_LCBR, KC_RCBR,  KC_AT,  _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                      OSL(NUMFUNC), TO(BASE), KC_SPC,     KC_ENT, QK_REP,  KC_ESC
                                  //`------------------------------'  `------------------------------'
    ),
    // transparent keys on the right are important to have comma, dot and backspace available
    [NUMFUNC] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     _______,  KC_F12,  KC_F11,  KC_F10,  KC_F9,  _______,                      _______,   KC_7,   KC_8,    KC_9,    KC_UP,  _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_HOME,  KC_F8,   KC_F7,   KC_F6,   KC_F5,  KC_PGUP,                        KC_0,    KC_4,    KC_5,   KC_6,   KC_DOWN,  KC_LEFT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_END,   KC_F4,   KC_F3,   KC_F2,   KC_F1,  _______,                      CW_TOGG,   KC_1,    KC_2,   KC_3,   _______, KC_RIGHT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         OSL(SYMB), TO(BASE), KC_SPC,    KC_ENT,  QK_REP,  KC_ESC
                                  //`------------------------------'  `------------------------------'
    )
    /*
    [NUMFUNC] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                         KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_HOME,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_PGUP,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_END, KC_COMMA, _______,  _______, CW_TOGG, RGB_MOD,                      _______, KC_LEFT, KC_RIGHT, KC_UP, KC_DOWN, KC_PGDN,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                   TO(SYMB), TO(BASE), KC_SPC,     KC_ENT, QK_REP,  KC_ESC
                                  //`------------------------------'  `------------------------------'
    )
    */
};

uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
    // the 0x codes are what happens instead of KC_* when mod taps are applied to the keys
    // I've put them directly behind their corresponding KC_* constants to keep things readable, but
    // technically the KC_* constant is not needed here.
    #ifdef CONSOLE_ENABLE
        uprintf("Keycode: 0x%04X", keycode);
        uprintf("Mods: %s", mods);
    #endif
    switch (keycode) {
        case KC_B:
            return KC_Z;
        case KC_C:
            return KC_D;
        case KC_D:
        case 0x2807:
            return KC_C;
        case KC_P:
        case KC_G:
        case KC_W:
        case KC_Z: return KC_Y;
        case KC_F:
        case 0x3209:
            return KC_B;
        case KC_Y:
        case 0x221C:
            return KC_P;
        case KC_R:
        case 0x2415:
            return KC_L;
        case KC_K: return KC_L;
        case KC_I: return KC_O;
        case KC_N:
        case 0x3811:
            return false; // just here to save the keycode for MT(...KC_N) somewhere
        case KC_L:
        case KC_S: return KC_K;
        case KC_U: return KC_E;
        case KC_E:
        case 0x3408:
            return KC_U;
        case KC_O: return KC_A;
        case KC_T:
        case 0x2117:
            return KC_S;
        case KC_A:
            case 0x3104:
            return KC_O;
        case KC_M:
            return KC_V;
        case KC_V:
            return KC_M;
        case KC_X:
            return KC_T;
        case KC_DOT:
            if (mods & MOD_MASK_SHIFT) {
                return KC_EQL;
            } else {
                return KC_SLASH;
            }
        case KC_COMM:
            if (mods & MOD_MASK_SHIFT) {
                return KC_EQL;
            }
        case KC_EQL: return KC_SPC;
        case C_RCTL_MINS:
        case KC_MINS: return KC_RABK;
        case KC_1 ... KC_0: return KC_DOT;
    }

    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        int rep_count = get_repeat_key_count();
        if (rep_count < -1) {
            send_char('n');
            return false;
        }
    }
    return true;
}
