/*
Copyright 2023 F1shlab

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

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
                                   KC_MUTE,
        KC_P7,    KC_P8,  KC_P9,   KC_A,
        KC_P4,    KC_P5,  KC_P6,   KC_B,
        KC_P1,    KC_P2,  KC_P3,   KC_C,
        KC_PAST,  KC_P0,  KC_PDOT, KC_D
    ),
    [1] = LAYOUT(
                                   _______,
        _______, _______, _______, _______,
        _______, _______, _______, _______,
        _______, _______, _______, _______,
        _______, _______, _______, _______
    ),
    [2] = LAYOUT(
                                   _______,
        _______, _______, _______, _______,
        _______, _______, _______, _______,
        _______, _______, _______, _______,
        _______, _______, _______, _______
    ),
    [3] = LAYOUT(
                                   _______,
        _______, _______, _______, _______,
        _______, _______, _______, _______,
        _______, _______, _______, _______,
        _______, _______, _______, _______
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0]  = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [1]  = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [2]  = {ENCODER_CCW_CW(RGB_HUD, RGB_HUI)},
    [3]  = {ENCODER_CCW_CW(RGB_RMOD, RGB_MOD)}
};
#endif
