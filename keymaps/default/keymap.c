// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┐
     * │ 7 │ 8 │ 9 │ / │
     * ├───┼───┼───┼───┤
     * │ 4 │ 5 │ 6 │ * │
     * ├───┼───┼───┼───┤
     * │ 1 │ 2 │ 3 │ - │
     * ├───┼───┼───┼───┤
     * │ 0 │ . │Ent│ + │
     * └───┴───┴───┴───┘
     */
    [0] = LAYOUT(
        KC_GRAVE, KC_1, KC_2, KC_3, KC_4, KC_5,       // row 0
        KC_Q, KC_Q, KC_W, KC_E, KC_R, KC_T,            // row 1
        KC_Q, KC_A, KC_S, KC_D, KC_F, KC_G,            // row 2
        KC_Q, KC_Z, KC_X, KC_C, KC_V, KC_B,            // row 3
        KC_NO, KC_NO, KC_LEFT_BRACKET, KC_RIGHT_BRACKET, // Extra keys in rows

        // Cluster
        KC_BACKSPACE, KC_KP_DOT, // Top thumb buttons
        KC_NO, KC_NO, KC_A, KC_S, // bottom thumb keys
        KC_D, KC_F       // middle thumb keys
    )
};
