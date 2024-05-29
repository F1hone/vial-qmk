#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_PSLS, KC_PPLS, KC_PMNS, KC_P2  , KC_P5  , KC_PENT, KC_PDOT, KC_P8  ,
        KC_P7  , KC_P6  , KC_P9  , KC_P0  , KC_P1  , KC_PAST, KC_P3  , KC_P4  ,
                 KC_END,  KC_LWIN, KC_PGUP, KC_APP ,
        KC_F5  , KC_F9  ,          KC_F10 , KC_BSLS, KC_ENT , KC_SPC , KC_BSPC,
                 KC_PAUS,          KC_F11 ,                   KC_DOWN,
        KC_UP  , KC_HOME,          KC_PGDN, MO(1)  , KC_DEL,  KC_LEFT,
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
                                                     KC_RSFT,          KC_LSFT,
        KC_SLEP
    ),
    /*FN层*/
    [1] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  //0
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  //1
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                             //2
        KC_MSTP, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  //3
                 KC_TRNS,          KC_BRID,                   KC_TRNS,           //4
        KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_SCRL, KC_TRNS,           //5
                 KC_TRNS,          KC_BRIU,                   KC_TRNS,           //6
        KC_TRNS, 			             KC_TRNS,				      KC_TRNS,   //7
                 KC_TRNS,					         KC_TRNS,                    //8
        KC_MPLY, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,		   KC_TRNS,  //9
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS,  //10
                 KC_MSEL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 	       KC_MNXT,  //11
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  //12
                 KC_MUTE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,	 //13
        KC_MPRV, KC_VOLD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  	       KC_VOLU,  //14
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  //15
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,  //16
                                                     KC_TRNS,          KC_TRNS,  //17
        KC_TRNS                                                                  //18
    )
};

void board_init(void) {
  // Call the keyboard pre init code.
  setPinOutput(C11);
  setPinOutput(D2);
  setPinOutput(A15);
}
