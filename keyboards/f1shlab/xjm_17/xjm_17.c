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
#include "quantum.h"

led_config_t g_led_config = {
    {
		{16, 15, 14, 13},
		{12, 11, 10, NO_LED},
		{9, 8,  7,  6},
		{5,  4,  3,  NO_LED},
		{NO_LED,  2,  1,  0}
    },
    {
		{28, 3},  {84, 3},  {140, 3},  {196, 3},
		{28, 16}, {84, 16}, {140, 16},
		{28, 29}, {84, 29}, {140, 29}, {182, 19},
		{28, 41}, {84, 41}, {140, 41},
		          {56, 54}, {140, 54}, {182, 45}
    },
    {
		8, 1, 1, 1,
		4, 4, 4,
		4, 4, 4, 1,
		4, 4, 4,
		   4, 4, 1
    }
};

#if defined(RGB_MATRIX_ENABLE) && defined(NUM_LOCK_LED_INDEX)

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_user(keycode, record)) { return false; }
    switch (keycode) {
#ifdef RGB_MATRIX_ENABLE
        case RGB_TOG:
            if (record->event.pressed) {
                switch (rgb_matrix_get_flags()) {
                    case LED_FLAG_ALL: {
                        rgb_matrix_set_flags(LED_FLAG_NONE);
                        rgb_matrix_set_color_all(0, 0, 0);
                    } break;
                    default: {
                        rgb_matrix_set_flags(LED_FLAG_ALL);
                    } break;
                }
            }
            if (!rgb_matrix_is_enabled()) {
                rgb_matrix_set_flags(LED_FLAG_ALL);
                rgb_matrix_enable();
            }
            return false;
#endif
    }
    return true;
}

__attribute__((weak)) void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    // RGB_MATRIX_INDICATOR_SET_COLOR(index, red, green, blue);

    if (host_keyboard_led_state().num_lock) {
        RGB_MATRIX_INDICATOR_SET_COLOR(NUM_LOCK_LED_INDEX, 255, 0, 0);
    } else {
        if (!rgb_matrix_get_flags()) {
           RGB_MATRIX_INDICATOR_SET_COLOR(NUM_LOCK_LED_INDEX, 0, 0, 0);
        }
    }
}

#endif // NUM_LOCK_LED_INDEX



