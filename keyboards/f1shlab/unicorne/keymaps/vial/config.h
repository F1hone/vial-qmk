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

#pragma once

#define VIAL_KEYBOARD_UID {0x4D, 0x59, 0x73, 0xA5, 0x97, 0x80, 0x33, 0x27}

#define VIAL_UNLOCK_COMBO_ROWS { 0, 4 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 0 }

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#ifdef RGBLIGHT_ENABLE
    #define RGBLIGHT_EFFECT_BREATHING
    #define RGBLIGHT_EFFECT_RAINBOW_MOOD
    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
    #define RGBLIGHT_EFFECT_SNAKE
    #define RGBLIGHT_EFFECT_KNIGHT
    #define RGBLIGHT_EFFECT_CHRISTMAS
    #define RGBLIGHT_EFFECT_STATIC_GRADIENT
//  #define RGBLIGHT_EFFECT_RGB_TEST
//  #define RGBLIGHT_EFFECT_ALTERNATING
//  #define RGBLIGHT_EFFECT_TWINKLE
    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17
#endif

// #define OLED_FONT_H "keyboards/f1shlab/corne/lib/glcdfont.c"
