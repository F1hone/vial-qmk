#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID 0xFEED
#define PRODUCT_ID 0x6060
#define DEVICE_VER 0x0001
#define MANUFACTURER Neilzx
#define PRODUCT Final84
#define DESCRIPTION Keyboard

/* key matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 14

/* key matrix pins */
#define MATRIX_ROW_PINS        \
    {                          \
        E6, F7, D6, B7, D4, D5 \
    }
#define MATRIX_COL_PINS                                        \
    {                                                          \
        D7, B4, C6, C7, F6, F5, F4, F1, F0, B1, B2, B3, D1, D0 \
    }
#define UNUSED_PINS

/* encoder pins */
#define ENCODERS_PAD_A \
    {                  \
        D3             \
    }
#define ENCODERS_PAD_B \
    {                  \
        D2             \
    }
#define ENCODER_RESOLUTION 4

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION ROW2COL

/* number of backlight levels */
#define BACKLIGHT_PIN B5
#ifdef BACKLIGHT_PIN
#define BACKLIGHT_LEVELS 5
#define BACKLIGHT_BREATHING
#define BREATHING_PERIOD 4
#define BACKLIGHT_ON_STATE 1
#endif

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#define RGB_DI_PIN B0
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 24
#define RGBLIGHT_SLEEP
#define RGBLED_SPLIT \
    {                \
        4, 20        \
    } //RGB分区
#define RGBLIGHT_LED_MAP                                                                     \
    {                                                                                        \
        1, 2, 3, 0, 20, 21, 22, 23, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 \
    } //重新调整RGB灯顺序。
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
#define RGBLIGHT_SLEEP
#define RGBLIGHT_LIMIT_VAL 200
#define RGBLIGHT_LAYERS
#define RGBLIGHT_LAYER_BLINK
#define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF //RGB LAYERS在RGB关闭的情况下仍然有效，实现全局分层指示灯。
#define MOUSEKEY_DELAY 0
#define MOUSEKEY_INTERVAL 17
#define MK_3_SPEED
#define MK_MOMENTARY_ACCEL
#define MK_C_OFFSET_UNMOD 64 //旋钮作为鼠标指针左右移动时的灵敏度,单位：像素。
#define MK_C_INTERVAL_UNMOD 17

#endif
