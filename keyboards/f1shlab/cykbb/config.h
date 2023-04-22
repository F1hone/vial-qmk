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
#define MATRIX_ROW_PINS { A3, A8,  C9, C8, C7,  C6,  B15, B14, B13, B12, B11, B10, B0,  C5,  A7,  A6,  A3,  C3 }
#define MATRIX_COL_PINS { C4,  A5,  A4,  A2,  A1,  C2, C1,  C0 }

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

#define LED_CAPS_LOCK_PIN  D2
#define LED_SCROLL_LOCK_PIN  A15
#define LED_NUM_LOCK_PIN  C11
#define LED_PIN_ON_STATE 0

#define NO_ACTION_NO_BOOT
