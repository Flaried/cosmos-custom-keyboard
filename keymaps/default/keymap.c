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
        KC_LEFT, KC_Q, KC_W, KC_E, KC_R, KC_T,            // row 1
        KC_RIGHT, KC_A, KC_S, KC_D, KC_F, KC_G,            // row 2
        KC_END, KC_Z, KC_X, KC_C, KC_V, KC_B,            // row 3
        KC_L, KC_L, KC_DOWN, KC_UP, // Extra keys in rows

        // Cluster
        KC_BACKSPACE, KC_KP_DOT, // Top thumb buttons
        KC_NO, KC_NO, KC_ESC, KC_CAPS_LOCK, // bottom thumb keys
        KC_LEFT_SHIFT, KC_LEFT_ALT,       // middle thumb keys

        // second keyboard

        KC_6, KC_7, KC_8, KC_9, KC_0, KC_EQUAL,       // row 0
        KC_Y, KC_U, KC_I, KC_O, KC_P,  KC_BACKSLASH, // row 1
        KC_H, KC_J, KC_K, KC_L, KC_SEMICOLON,  KC_QUOTE, // row
        KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH,  KC_MINUS, // row 3
        KC_ENTER, KC_SPACE, KC_LEFT_BRACKET, KC_RIGHT_BRACKET, // Extra keys in rows

        // Cluster
        KC_BACKSPACE, KC_KP_DOT, // Top thumb buttons
        KC_RCMD, KC_RIGHT_CTRL, KC_TAB, KC_D, KC_E // bottom thumb keys

    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
  return true;
}

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}
