#include QMK_KEYBOARD_H
enum layers {
    _QWERTY,
    _NIGHT,
    _STURDY,
};

// Custom keycodes for layer switching
enum custom_keycodes {
    NEXT_LAYER = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
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
        KC_SPACE, KC_RCMD, KC_LEFT_BRACKET, KC_RIGHT_BRACKET, // Extra keys in rows

        // Cluster
        KC_BACKSPACE, KC_KP_DOT, // Top thumb buttons
        KC_ENTER, KC_RIGHT_CTRL, KC_TAB, NEXT_LAYER, KC_E // bottom thumb keys

    ),

    // Night layer
    [_NIGHT] = LAYOUT(
        KC_GRAVE, KC_1, KC_2, KC_3, KC_4, KC_5,       // row 0
        KC_HOME, KC_B, KC_F, KC_L, KC_K, KC_Q,        // row 1
        KC_END, KC_N, KC_S, KC_H, KC_T, KC_M,         // row 2
        KC_PGUP, KC_X, KC_V, KC_J, KC_D, KC_Z,        // row 3
        KC_SPACE, KC_RCMD, KC_LEFT_BRACKET, KC_RIGHT_BRACKET, // Extra keys in rows

        // Cluster
        KC_BACKSPACE, KC_R, // Top thumb buttons
        KC_NO, KC_NO, KC_ESC, KC_CAPS_LOCK, // bottom thumb keys
        KC_LEFT_SHIFT, KC_LEFT_ALT,       // middle thumb keys

        KC_6, KC_7, KC_8, KC_9, KC_0, KC_EQUAL,       // row 0
        KC_P, KC_G, KC_O, KC_U, KC_DOT, KC_BACKSLASH,   // row 1
        KC_Y, KC_C, KC_A, KC_E, KC_I, KC_QUOTE, // row 2
        KC_QUOTE, KC_W, KC_BACKSLASH, KC_COLON, KC_COMMA, KC_F12, // row 3
        KC_SPACE, KC_RCMD, KC_LEFT_BRACKET, KC_RIGHT_BRACKET, // Extra keys in rows

        // Cluster
        KC_BACKSPACE, KC_R, // Top thumb buttons
        KC_ENTER, KC_RIGHT_CTRL, KC_TAB, NEXT_LAYER, KC_E // bottom thumb keys
    ),
    [_STURDY] = LAYOUT(
        KC_GRAVE, KC_1, KC_2, KC_3, KC_4, KC_5,       // row 0
        KC_HOME, KC_V, KC_M, KC_L, KC_C, KC_P,        // row 1
        KC_END, KC_S, KC_T, KC_R, KC_D, KC_Y,         // row 2
        KC_PGUP, KC_Z, KC_K, KC_Q, KC_G, KC_W,        // row 3
        KC_SPACE, KC_RCMD, KC_LEFT_BRACKET, KC_RIGHT_BRACKET, // Extra keys in rows

        // Cluster
        KC_BACKSPACE, KC_PDOT, // Top thumb buttons
        KC_NO, KC_NO, KC_ESC, KC_CAPS_LOCK, // bottom thumb keys
        KC_LEFT_SHIFT, KC_LEFT_ALT,       // middle thumb keys

        KC_6, KC_7, KC_8, KC_9, KC_0, KC_EQUAL,       // row 0
        KC_X, KC_F, KC_O, KC_U, KC_J, KC_BACKSLASH,   // row 1
        KC_DOT, KC_N, KC_A, KC_E, KC_I, KC_QUOTE, // row 2
        KC_B, KC_H, KC_BACKSLASH, KC_COLON, KC_COMMA, KC_F12, // row 3
        KC_SPACE, KC_RCMD, KC_LEFT_BRACKET, KC_RIGHT_BRACKET, // Extra keys in rows

        // Cluster
        KC_BACKSPACE, KC_KP_DOT, // Top thumb buttons
        KC_ENTER, KC_RIGHT_CTRL, KC_TAB, NEXT_LAYER, KC_E // bottom thumb keys
    )
};

// Process keycodes with custom behavior
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case NEXT_LAYER: {
                // Get the current highest active layer
                uint8_t current_layer = get_highest_layer(layer_state);

                // Cycle through the layers
                switch (current_layer) {
                    case _QWERTY:
                        layer_move(_NIGHT);
                        break;
                    case _NIGHT:
                        layer_move(_STURDY);
                        break;
                    case _STURDY:
                        layer_move(_QWERTY);
                        break;
                    default:
                        // Fallback to QWERTY if a different layer is active
                        layer_move(_QWERTY);
                        break;
                }
                return false; // Prevent the key from being sent to the host
            }
        }
    }
    return true; // Process all other keycodes normally
}
    // If console is enabled, it will print the matrix position and status of each key pressed
// #ifdef CONSOLE_ENABLE
//     uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n",
//             keycode, record->event.key.col, record->event.key.row, record->event.pressed,
//             record->event.time, record->tap.interrupted, record->tap.count);
// #endif
//     return true;
// }

void keyboard_post_init_user(void) {
    // Customise these values to desired behaviour
    debug_enable = true;
    debug_matrix = true;
    //debug_keyboard = true;
    //debug_mouse = true;
}
