#include "kb.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    KEYMAP(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,  KC_F4,   KC_F5,   KC_F6, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        KC_GRV,  KC_1,    KC_2,    KC_3,   KC_4,    KC_5,    KC_6,  KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,    KC_T,    KC_Y,  KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        KC_CAPS, KC_A,    KC_S,    KC_D,   KC_F,    KC_G,    KC_H,  KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  KC_MUTE,
        KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,    KC_B,    KC_N,  KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_HOME, KC_PGUP,
        KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, KC_RALT, MO(2), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT, KC_UP,   KC_END,  KC_PGDN),

    KEYMAP(
        KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL,
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
        KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_SPC,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_HOME, KC_PGUP,
        KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, KC_RALT, MO(2), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT, KC_UP, KC_END, KC_PGDN),

    KEYMAP(
        RESET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN, RGB_M_K, RGB_M_X, RGB_M_G, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_MOD, TG(1),
        KC_TRNS, RGB_HUI, RGB_SAI, RGB_VAI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, RGB_TOG, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, BL_TOGG, BL_DEC, BL_BRTG, BL_INC, KC_TRNS, KC_TRNS),

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch (id)
    {
    }
    return MACRO_NONE;
}

void matrix_init_user(void) {}

bool is_alt_tab_active = false; // ALT_TAB激活状态。
uint16_t alt_tab_timer = 0;     // ALT_TAB状态计时器。

void matrix_scan_user(void)
{
    if (is_alt_tab_active)
    {
        if (timer_elapsed(alt_tab_timer) > 1000) // ALT_TAB释放KC_LALT延迟，1000ms。
        {
            unregister_code(KC_LALT);
            is_alt_tab_active = false;
        }
    }
}

bool is_rshift_pressed = false; // RSHIFT按下状态。

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    switch (keycode)
    {
    case KC_RSFT:
        if (record->event.pressed)
        {
            is_rshift_pressed = true;
        }
        else
        {
            is_rshift_pressed = false;
        } //检测RSHIFT是否按下，返回给is_rshift_pressed。
        return true;

    default:
        return true;
    }
}

//以下为旋钮相关功能实现：
void encoder_update_user(uint8_t index, bool clockwise)
{
    switch (biton32(layer_state))
    {
    case 1:
        clockwise ? tap_code(KC_MS_LEFT) : tap_code(KC_MS_RIGHT);
        //为steam游戏《Spin Rhythm XD》设置，勉强能玩。
        break;

    case 2:
        clockwise ? rgblight_decrease_val_noeeprom() : rgblight_increase_val_noeeprom();
        //旋钮在FN层调节RGB亮度，且不保存到EEPROM。
        break;

    default:
        if (is_rshift_pressed)
        {
            if (clockwise)
            {
                tap_code(KC_VOLD);
                tap_code(KC_VOLD);
            }
            else
            {
                tap_code(KC_VOLU);
                tap_code(KC_VOLU);
            } // 当右SHIFT按下时旋钮调节系统音量，旋转一格步进4%。(WINDOWS10系统下KEYCODE: KC_VOLD , KC_VOLU 一次步进为2%)。
        }
        else
        {
            if (!clockwise) //反转以实现旋钮顺时针旋转向后切换，逆时针旋转向前切换。
            {
                if (!is_alt_tab_active)
                {
                    is_alt_tab_active = true;
                    register_code(KC_LALT);
                }
                alt_tab_timer = timer_read();
                tap_code16(KC_TAB);
            }
            else
            {
                if (!is_alt_tab_active)
                {
                    is_alt_tab_active = true;
                    register_code(KC_LALT);
                }
                alt_tab_timer = timer_read();
                tap_code16(S(KC_TAB));
            } //旋钮默认进行ALT_TAB任务切换。
        }
        break;
    }
}

void led_set_user(uint8_t usb_led)
{
    if (usb_led & (1 << USB_LED_NUM_LOCK))
    {
    }
    else
    {
    }

    if (usb_led & (1 << USB_LED_CAPS_LOCK))
    {
        DDRB |= (1 << 6);
        PORTB &= ~(1 << 6);
    }
    else
    {
        DDRB &= ~(1 << 6);
        PORTB &= ~(1 << 6);
    }

    if (usb_led & (1 << USB_LED_SCROLL_LOCK))
    {
    }
    else
    {
    }

    if (usb_led & (1 << USB_LED_COMPOSE))
    {
    }
    else
    {
    }

    if (usb_led & (1 << USB_LED_KANA))
    {
    }
    else
    {
    }
}

// 以下为RGB灯效分层设置：
// Light LEDs 0 to 4 in red when caps lock is active. Hard to ignore!
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 4, HSV_RED});

// Light LEDs 0 to 4 in cyan when keyboard layer 1 is active
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 4, HSV_CYAN});

// Light LEDs 0 to 4 in green when keyboard layer 2 is active
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 4, HSV_GREEN});

const rgblight_segment_t *const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_layer, my_layer1_layer,
    my_layer2_layer // Overrides other layers
);

void keyboard_post_init_user(void)
{
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state)
{
    // Both layers will light up if both kb layers are active
    rgblight_set_layer_state(1, layer_state_cmp(state, 1));
    rgblight_set_layer_state(2, layer_state_cmp(state, 2));
    return state;
}

bool led_update_user(led_t led_state)
{
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}
