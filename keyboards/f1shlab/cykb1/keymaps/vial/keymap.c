#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_F1 , KC_PPLS,KC_PENT , KC_BSPC ,KC_ESC ,   
        KC_F2 , KC_P0  ,KC_P1   , KC_P2   ,   
        KC_F3 , KC_P3  ,KC_P4   , KC_P5   ,    
        KC_F4 , KC_P6  ,KC_P7   , KC_P8   ,                         
        KC_F5 , KC_P9  ,KC_PDOT , KC_UP   , 
        KC_F6 , KC_LEFT,KC_DOWN , KC_RGHT                                                               
    )
};

void board_init(void) {
  // Call the keyboard pre init code.
  setPinOutput(C11);
  setPinOutput(D2);
  setPinOutput(A15);
}
