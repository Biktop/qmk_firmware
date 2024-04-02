#include QMK_KEYBOARD_H
#include "./common.h"


// Tap Dance declarations

#ifdef TAP_DANCE_ENABLE

enum {
    TD_BSPC_OBSPC,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_BSPC_OBSPC] = ACTION_TAP_DANCE_DOUBLE(KC_BSPC, LOPT(KC_BSPC))
};

#endif //TAP_DANCE_ENABLE

// #define COMBO_COUNT 2

const uint16_t PROGMEM combo_mute[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM combo_esc_right[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM combo_esc_left[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM combo_caps[] = {KC_Z, KC_X, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo_mute, KC_MUTE),
    COMBO(combo_esc_left, KC_ESC),
    COMBO(combo_esc_right, KC_ESC),
    COMBO(combo_caps, KC_CAPS),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTY] = LAYOUT_split_3x6_3(
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,                             KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
        KC_GRV, KC_A, LSFT_T(KC_S), LCTL_T(KC_D), LALT_T(KC_F), KC_G,     KC_H, RALT_T(KC_J), RCTL_T(KC_K), RSFT_T(KC_L), KC_SCLN, KC_QUOT,
        KC_HYPR, KC_Z, KC_X, KC_C, KC_V, KC_B,                            KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ESC,
        KC_LEFT_GUI, MO(_LOWER), KC_SPC,                                       KC_ENT, MO(_SYMBOL), KC_RIGHT_GUI
    ),
	[_LOWER] = LAYOUT_split_3x6_3(
        KC_TRNS, KC_NO, LGUI(KC_LEFT), KC_UP, LGUI(KC_RIGHT), KC_PGUP,    KC_NO, KC_7, KC_8, KC_9, KC_NO, KC_TRNS,
        KC_TRNS, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,               KC_NO, KC_4, KC_5, KC_6, KC_NO, KC_NO,
        KC_TRNS, KC_NO, LALT(KC_LEFT), KC_NO, KC_F18, KC_F19,             KC_0, KC_1, KC_2, KC_3, KC_NO, KC_NO,
        KC_TRNS, KC_TRNS, KC_TRNS,                                         KC_TRNS, MO(_ADJUST), KC_TRNS
    ),
    [_SYMBOL] = LAYOUT_split_3x6_3(
        KC_TRNS, KC_QUOT, KC_LT, KC_GT, KC_DQUO, KC_GRV,            KC_AMPR, KC_SCLN, KC_LBRC, KC_RBRC, KC_PERC, KC_TRNS,
        KC_TRNS, KC_EXLM, KC_MINS, KC_PLUS, KC_EQL, KC_HASH,        KC_PIPE, KC_COLN, KC_LPRN, KC_RPRN, KC_QUES, KC_NO,
        KC_TRNS, KC_CIRC, KC_SLSH, KC_ASTR, KC_BSLS, KC_UNDS,       KC_TILD, KC_DLR, KC_LCBR, KC_RCBR, KC_AT, KC_TRNS,
        KC_TRNS, MO(_ADJUST), KC_TRNS,                                     KC_TRNS, KC_TRNS, KC_TRNS
    ),
	[_ADJUST] = LAYOUT_split_3x6_3(
        QK_BOOT, KC_BRID, KC_BRIU, KC_NO, KC_NO, DF(_GAME_BASE),    KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU,
        RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, KC_NO, KC_NO,           LSFT(LCMD(KC_4)), LCTL(LSFT(LCMD(KC_4))), LSFT(LCMD(KC_5)), KC_NO, KC_NO, KC_NO,
        RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, KC_NO, KC_NO,           KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_TRNS, KC_TRNS, KC_TRNS,                                   KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [_GAME_BASE] = LAYOUT_split_3x6_3(
        KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T,                             KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
        KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_G,                             KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
        KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B,                            KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ESC,
        KC_LALT, MO(_GAME_BASE_EX), KC_SPC,                                       KC_ENT, MO(_GAME_BASE_EX), KC_RIGHT_GUI
    ),
    [_GAME_BASE_EX] = LAYOUT_split_3x6_3(
        KC_TRNS, KC_0, KC_TRNS, KC_1, KC_2, KC_3,                    DF(_QWERTY), KC_F7, KC_F8, KC_F9, KC_F10, KC_TRNS,
        KC_TAB, KC_TRNS, KC_TRNS, KC_TRNS, KC_4, KC_5,               KC_TRNS, KC_F4, KC_F5, KC_F6, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_6, KC_7, KC_8, KC_9,                    KC_TRNS, KC_F1, KC_F2, KC_F3, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_SPC,                                    KC_TRNS, KC_TRNS, KC_TRNS
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
     static uint16_t _timer;
     uint8_t mod_state = get_mods();

    switch (keycode) {
        case KC_V:
            if (mod_state & MOD_MASK_GUI) {
                if(record->event.pressed) {
                    _timer = timer_read();
                }
                else {
                    tap_code16(timer_elapsed(_timer) > 200 ? LSG(KC_V) : G(KC_V));
                }
                return false;
            }
            return true;

        case KC_BSPC:
            if (mod_state & MOD_MASK_CTRL ) {
                if (record->event.pressed) {
                    del_mods(MOD_MASK_CTRL);
                    register_code(KC_DEL);
                    set_mods(mod_state);
                }
                else {
                    unregister_code(KC_DEL);
                }
                return false;
            }
            return true;
    }
    return true;
}

// const uint16_t PROGMEM test_combo1[] = {KC_A, KC_B, COMBO_END};
// const uint16_t PROGMEM test_combo2[] = {KC_C, KC_D, COMBO_END};
// combo_t key_combos[COMBO_COUNT] = {
//     COMBO(test_combo1, KC_ESC),
//    // COMBO(test_combo2, LCTL(KC_Z)), // keycodes with modifiers are possible too!
// };

// layer_state_t layer_state_set_user(layer_state_t state) {
//     switch (get_highest_layer(state)) {
//     case 1:
//         rgb_matrix_set_color_all (0x00,  0x00, 0xFF);
//         break;
//     case 2:
//         rgb_matrix_set_color_all (0xFF,  0x00, 0x00);
//         break;
//     case 3:
//         rgb_matrix_set_color_all (0x00,  0xFF, 0x00);
//         break;
//     case 4:
//         rgb_matrix_set_color_all (0x7A,  0x00, 0xFF);
//         break;
//     default: //  for any other layers, or the default layer
//         rgb_matrix_set_color_all (0x00,  0xFF, 0xFF);
//         break;
//     }
//   return state;
// }


// // // Add tap dance item to your keymap in place of a keycode
// // const uint16_t `[][MATRIX_ROWS][MATRIX_COLS] = {
// //     TD(TD_M_MUTE)
// // };

// const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {6, 4, HSV_RED},       // Light 4 LEDs, starting with LED 6
//     {12, 4, HSV_RED}       // Light 4 LEDs, starting with LED 12
// );
// // Light LEDs 9 & 10 in cyan when keyboard layer 1 is active
// const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {9, 2, HSV_CYAN}
// );
// // Light LEDs 11 & 12 in purple when keyboard layer 2 is active
// const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {11, 2, HSV_PURPLE}
// );
// // Light LEDs 13 & 14 in green when keyboard layer 3 is active
// const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {13, 2, HSV_GREEN}
// );
// // etc

// // Now define the array of layers. Later layers take precedence
// const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
//     my_capslock_layer,
//     my_layer1_layer,    // Overrides caps lock layer
//     my_layer2_layer,    // Overrides other layers
//     my_layer3_layer     // Overrides other layers
// );



void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgb_matrix_set_color_all(0, 0, 0);
}

bool isBarking  = false;
bool isSneaking = false;
uint8_t mod_state;

// bool rgb_matrix_indicators_user(void) {
//     rgb_matrix_set_color_all(0, 0, 0);

//     uint8_t layer = get_highest_layer(layer_state);

//     if (layer == _QWERTY) {
//         rgb_matrix_set_color(0, 255, 0, 0);
//     }
//     else if (layer == _LOWER) {
//         rgb_matrix_set_color(0, 0, 255, 0);
//     }
//     else if (layer == _RAISE) {
//         rgb_matrix_set_color(0, 0, 0, 255);
//     }
//     else if (layer == _ADJUST) {
//         rgb_matrix_set_color(0, 255, 0, 255);
//     }



//     // rgb_matrix_set_color(0, 255, 0, 0);         // Activate cyan layer
//     // rgb_matrix_set_color(6, 255, 255, 255);         // Activate cyan layer

//     // rgb_matrix_set_color(13, 23, 181, 255);         // Activate cyan layer
//     // rgb_matrix_set_color(40, 255, 33, 0);           // Activate orange layer
//     // rgb_matrix_set_color(50, 0, 33, 255);           // Numpad *
//     // rgb_matrix_set_color(14, 0, 255, 0);            // Green layer active
//     return false;
// }


// layer_state_t layer_state_set_user(layer_state_t state) {
//     // Both layers will light up if both kb layers are active
//     rgblight_set_layer_state(0, layer_state_cmp(state, 0));
//     rgblight_set_layer_state(1, layer_state_cmp(state, 1));
//     rgblight_set_layer_state(2, layer_state_cmp(state, 2));
//     rgblight_set_layer_state(3, layer_state_cmp(state, 3));
//     rgblight_set_layer_state(4, layer_state_cmp(state, 4));
//     rgblight_set_layer_state(5, layer_state_cmp(state, 5));
//     rgblight_set_layer_state(6, layer_state_cmp(state, 6));
//     rgblight_set_layer_state(7, layer_state_cmp(state, 7));
//     return state;
// }

// bool led_update_user(led_t led_state) {
//     rgblight_set_layer_state(0, true);
//     return true;
// }
