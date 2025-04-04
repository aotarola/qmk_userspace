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
#define Z_CTL MT(MOD_LCTL, KC_Z)
#define SPC_L1 LT(1, KC_SPC)
#define ENT_L2 LT(2, KC_ENT)


enum {
    TD_GUI_GUISPC,
    TD_GRV_CTRLGRV
};

#define T_GUI  TD(TD_GUI_GUISPC)  // Tap for Cmd, double tap for Cmd + Space
#define T_GRV  TD(TD_GRV_CTRLGRV) // Tap for GRV, double tap for Cmd + GRV

tap_dance_action_t tap_dance_actions[] = {
    [TD_GUI_GUISPC]   = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, LGUI(KC_SPC)),
    [TD_GRV_CTRLGRV]  = ACTION_TAP_DANCE_DOUBLE(KC_GRV, LGUI(KC_GRV))   
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------|.                   |------------------------------------------------------|
            KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                          KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSLS,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+---------|
            KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,                          KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+---------|
            KC_LSFT, Z_CTL,   KC_X,    KC_C,    KC_V,    KC_B,                          KC_K,    KC_M,    KC_COMM, KC_DOT, SLSH_RCTL, KC_EQL,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+---------|
                                         T_GUI, SPC_L1, KC_LSFT,                       BSC_SFT, ENT_L2,  DEL_ALT
                                   //`--------------------------'                    `--------------------------'

        ),

    // L1
    [1] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------|.                   |------------------------------------------------------|
            T_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                          KC_6,   KC_7,    KC_8,    KC_9,    KC_0,   KC_MINUS,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+---------|
            KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+---------|
            KC_VOLD, XXXXXXX, XXXXXXX,  KC_F12, XXXXXXX, XXXXXXX,                       XXXXXXX, KC_MUTE, KC_MPLY, KC_MPRV, KC_MNXT, KC_VOLU,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+---------|
                                      KC_LGUI,  KC_SPC, _______,                         MO(4), KC_ENT, KC_RALT
                                   //`--------------------------'                    `--------------------------'
        ),

    // L2
    [2] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------|.                   |------------------------------------------------------|
            KC_F7, KC_F8, KC_F9,  KC_LCBR, KC_RCBR, XXXXXXX,                           XXXXXXX, KC_HOME, KC_UP,    KC_END, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+---------|
            KC_F4, KC_F5, KC_F6,  KC_LPRN, KC_RPRN, KC_PIPE,                           XXXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+---------|
            KC_F1, KC_F2, KC_F3,  KC_LBRC, KC_RBRC, XXXXXXX,                           XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+---------|
                                       KC_LGUI, KC_SPC,   MO(4),                       _______, KC_ENT, KC_RALT
                                   //`--------------------------'                    `--------------------------'
        ),

    [3] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------|.                   |------------------------------------------------------|
            XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, RRRRRRR, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+---------|
            XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+---------|
            XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+---------|
                                      XXXXXXX, XXXXXXX,   XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX
                                   //`--------------------------'                    `--------------------------'
        ),

    [4] = LAYOUT_split_3x6_3(
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
