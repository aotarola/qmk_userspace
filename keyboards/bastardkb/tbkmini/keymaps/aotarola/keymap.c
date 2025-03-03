/*
 * Copyright 2021 Quentin LEBASTARD <qlebastard@gmail.com>
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
#define SLSH_RCTL MT(MOD_RCTL, KC_SLSH)
#define DEL_ALT MT(MOD_RALT, KC_DEL)
#define BSC_SFT MT(MOD_RSFT, KC_BSPC)
#define SPC_L1 LT(1, KC_SPC)
#define ENT_L2 LT(2, KC_ENT)

enum {
    TD_GUI_GUISPC,
};

#define T_GUI  TD(TD_GUI_GUISPC)  // Tap for Cmd, double tap for Cmd + Space

tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_GUI_GUISPC]   = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, LGUI(KC_SPC)),
    
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------|.                   |------------------------------------------------------|
            KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                          KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSLS,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+---------|
            KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,                          KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+---------|
            KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,                          KC_K,    KC_M,    KC_COMM, KC_DOT, SLSH_RCTL, KC_EQL,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+---------|
                                         T_GUI, KC_LSFT, SPC_L1 ,                       ENT_L2, BSC_SFT,  DEL_ALT
                                   //`--------------------------'                    `--------------------------'

        ),

    // L1
    [1] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------|.                   |------------------------------------------------------|
            KC_TAB,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                          KC_6,   KC_7,    KC_8,    KC_9,    KC_0,   KC_BSPC,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+---------|
            KC_ESC,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+---------|
            KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+---------|
                                      KC_LGUI,  KC_SPC, _______,                         MO(3), KC_ENT, KC_RALT
                                   //`--------------------------'                    `--------------------------'
        ),

    // L2
    [2] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------|.                   |------------------------------------------------------|
             KC_TAB, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+---------|
            KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS, KC_EQL , KC_LBRC, KC_RBRC, KC_BSLS, KC_GRV,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+---------|
            KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+---------|
                                       KC_LGUI, KC_SPC,   MO(3),                       _______, KC_ENT, KC_RALT
                                   //`--------------------------'                    `--------------------------'
        ),

    [3] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------|.                   |------------------------------------------------------|
           QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+---------|
           RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+---------|
           RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+---------|
                                        KC_LGUI, KC_SPC, _______,                      _______, KC_ENT, KC_RALT
                                   //`--------------------------'                    `--------------------------'
        )};
