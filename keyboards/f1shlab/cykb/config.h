// Copyright 2022 HriyKun (@HriyKun)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "config_common.h"

// #define CH_CFG_ST_RESOLUTION 16

/* Layer states */
#define LAYER_STATE_8BIT

// #define USB_POLLING_INTERVAL_MS 1

/* key matrix size */
#define MATRIX_ROWS 18
#define MATRIX_COLS 8

// ROWS: Top to bottom, COLS: Left to right
#define MATRIX_ROW_PINS { C13, B7,  A10, A15, B3,  A8,  B4,  B15, B14, B13, B12, B10, B2,  B1,  A7,  A6,  A3,  A0 }
#define MATRIX_COL_PINS { B0,  A5,  A4,  A2,  A1,  C15, B9,  B8 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

// #define LED_PIN_ON_STATE 0
/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

#define LED_CAPS_LOCK_PIN  A9
#define LED_SCROLL_LOCK_PIN  B5
#define LED_NUM_LOCK_PIN  B6
#define LED_PIN_ON_STATE 0

#define NO_ACTION_NO_BOOT
