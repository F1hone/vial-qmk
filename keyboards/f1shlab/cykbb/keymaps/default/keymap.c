/* Copyright 2022 HiryKun (@HiryKun)
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* 默认层 */
  [0] = LAYOUT(
        KC_PSLS, KC_PPLS, KC_PMNS, KC_P2  , KC_P5  , KC_PENT, KC_PDOT, KC_P8  ,
        KC_P7  , KC_P6  , KC_P9  , KC_P0  , KC_P1  , KC_PAST, KC_P3  , KC_P4  , 
                 KC_SLEP, KC_LWIN,          KC_APP ,                   
        KC_F5  , KC_F9  , KC_SLEP, KC_F10 , KC_BSLS, KC_ENT , KC_SPC , KC_BSPC, 
                 KC_DEL ,          KC_F11 ,                   KC_DOWN,       
        KC_UP  ,                            MO(1)  , KC_PAUS, KC_LEFT,       
                 KC_INS ,          KC_F12 ,                   KC_RGHT,       
        KC_LALT, 			       KC_PSCR,				      KC_RALT,		
                 KC_LCTL,					         KC_RCTL,				
        KC_F6  , KC_EQL , KC_I   , KC_8   , KC_K   , KC_COMM,		   KC_RBRC,	
        KC_QUOT, KC_MINS, KC_P   , KC_0   , KC_SCLN,          KC_SLSH, KC_LBRC,	
                 KC_F8  , KC_O   , KC_9   , KC_L   , KC_DOT , 	       KC_F7  ,	
        KC_G   , KC_5   , KC_R   , KC_4   , KC_F   , KC_V   , KC_B   , KC_T   ,	
                 KC_F1  , KC_W   , KC_2   , KC_S   , KC_X   ,          KC_CAPS,	
        KC_F4  , KC_F2  , KC_E   , KC_3   , KC_D   , KC_C   ,  	       KC_F3  ,	
        KC_H   , KC_6   , KC_U   , KC_7   , KC_J   , KC_M   , KC_N   , KC_Y   ,	
        KC_ESC , KC_GRV , KC_Q   , KC_1   , KC_A   , KC_Z   ,          KC_TAB ,	
                                                     KC_RSFT,          KC_LSFT 	
    ),
  
  /* Fn层 */
  [1] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
                 KC_TRNS, KC_TRNS,          KC_TRNS,                   
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
                 KC_NUM ,          KC_TRNS,                   KC_TRNS,       
        KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS,       
                 KC_SCRL,          KC_TRNS,                   KC_TRNS,       
        KC_TRNS, 			       KC_SYRQ,				      KC_TRNS,		
                 KC_TRNS,					         KC_TRNS,				
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,		   KC_TRNS,	
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS,	
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 	       KC_TRNS,	
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,	
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,	
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  	       KC_TRNS,	
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,	
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,	
                                                     KC_TRNS,          KC_TRNS 	
    )
};

void keyboard_pre_init_user(void) {
  // Set our LED pins as output
  setPinOutput(A9);
  setPinOutput(C14);
  setPinOutput(B6);
}

bool led_update_kb(led_t led_state) {
    // writePin sets the pin high for 1 and low for 0.
    // In this example the pins are inverted, setting
    // it low/0 turns it on, and high/1 turns the LED off.
    // This behavior depends on whether the LED is between the pin
    // and VCC or the pin and GND.
    writePin(A9, led_state.num_lock);
    writePin(C14, led_state.caps_lock);
    writePin(B6, led_state.scroll_lock);
    return false;
}