/* Copyright 2022 Thomas Baart <thomas@splitkb.com>
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

#ifdef RGBLIGHT_ENABLE
#    define RGBLIGHT_ANIMATIONS
#    define RGBLIGHT_HUE_STEP  8
#    define RGBLIGHT_SAT_STEP  8
#    define RGBLIGHT_VAL_STEP  8
#    define RGBLIGHT_LIMIT_VAL 150
#endif

// Lets you roll mod-tap keys
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_TERM 250
#define PERMISSIVE_HOLD

#define TAPPING_TOGGLE 1

#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD

#define COMPOSE_KEY X_APP

#define UNICODE_SELECTED_MODES UC_LNX

#define PIMORONI_TRACKBALL_SCALE 5
#define POINTING_DEVICE_ROTATION_180
#define POINTING_DEVICE_GESTURES_CURSOR_GLIDE_ENABLE

#define ENCODER_RESOLUTION 2

#define TRACKBALL_SCROLL_SCALE 0.3

#define MOUSEMODE_LINGER 700
