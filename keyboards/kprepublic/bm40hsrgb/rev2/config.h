/* Copyright 2020 tominabox1
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
#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x4B50 // "KP"
#define PRODUCT_ID      0x3430 // "40"
#define DEVICE_VER      0x0002
#define MANUFACTURER    KPRepublic
#define PRODUCT         BM40 Hotswap RGB

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 12

/* key matrix pins */
#define MATRIX_ROW_PINS { D7, F7, F6, F5 }
#define MATRIX_COL_PINS { B2, B3, D5, D3, D2, B7, F0, B4, B5, B6, C6, C7 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION ROW2COL

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
// #define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
// #define LOCKING_RESYNC_ENABLE

#define RGB_DI_PIN B0
#define RGBLED_NUM 6
#ifdef RGB_DI_PIN
#    define RGBLIGHT_LIMIT_VAL 150 // Limit to vendor-recommended value
#endif
#ifdef RGB_MATRIX_ENABLE
// IS31FL3733 configuration
#    define DRIVER_COUNT 1
#    define DRIVER_ADDR_1 0b1010000
#    define DRIVER_1_LED_TOTAL 47
#    define ISSI_LED_TOTAL DRIVER_1_LED_TOTAL
// Underglow LEDs are WS2812, but someone might want to use RGBLIGHT for them;
// don't use those LEDs in RGB Matrix in that case.
#    ifdef RGBLIGHT_ENABLE
#        define WS2812_LED_TOTAL 0
#    else
#        define WS2812_LED_TOTAL 6
#    endif
#    define DRIVER_LED_TOTAL (ISSI_LED_TOTAL + WS2812_LED_TOTAL)

#    define RGB_DISABLE_WHEN_USB_SUSPENDED // turn off effects when suspended
#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 180 // Limit to vendor-recommended value
// RGB Matrix Animation modes. Explicitly enabled
// For full list of effects, see:
// https://docs.qmk.fm/#/feature_rgb_matrix?id=rgb-matrix-effects
#endif

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define ONESHOT_TAP_TOGGLE 2
#define ONESHOT_TIMEOUT 1000
#define IGNORE_MOD_TAP_INTERRUPT
