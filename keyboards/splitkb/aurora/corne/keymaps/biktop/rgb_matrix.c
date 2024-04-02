#include QMK_KEYBOARD_H
#include "./common.h"

// __attribute__ ((weak)) led_config_t g_led_config = {
//   {
//     { 24,23,22,21,20,19 },
//     { 25,18,17,16,15,14 },
//     { 26,13,12,11,10,9 },
//     { 8,7,6,NO_LED,NO_LED,NO_LED },
//     { 51,50,49,48,47,46 },
//     { 52,45,44,43,42,41 },
//     { 53,40,39,38,37,36 },
//     { 35,34,33,NO_LED,NO_LED,NO_LED },
//   },
//   { { 93,17 },{ 59,3 },{ 25,7 },{ 29,49 },{ 70,51 },{ 104,55 },{ 95,63 },{ 80,58 },{ 60,55 },{ 85,39 },{ 68,37 },{ 50,35 },{ 33,37 },{ 16,42 },{ 85,21 },{ 68,19 },{ 50,13 },{ 33,20 },{ 16,24 },{ 85,4 },{ 68,2 },{ 50,0 },{ 33,3 },{ 16,7 },{ 0,7 },{ 0,24 },{ 0,41 },{ 131,17 },{ 165,3 },{ 199,7 },{ 195,49 },{ 154,51 },{ 120,55 },{ 129,63 },{ 144,58 },{ 164,55 },{ 139,39 },{ 156,37 },{ 174,35 },{ 191,37 },{ 208,42 },{ 139,21 },{ 156,19 },{ 174,13 },{ 191,20 },{ 208,24 },{ 139,4 },{ 156,2 },{ 174,0 },{ 191,3 },{ 208,7 },{ 224,7 },{ 224,24 },{ 224,41 } },
//   { 2,2,2,2,2,2,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,2,2,2,2,2,2,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4 },
// };

#define LED111  54


#define MAC(\
    SW06L, SW05L, SW04L, SW03L, SW02L, SW01L,      SW01R, SW02R, SW03R, SW04R, SW05R, SW06R, \
    SW12L, SW11L, SW10L, SW09L, SW08L, SW07L,      SW07R, SW08R, SW09R, SW10R, SW11R, SW12R, \
    SW18L, SW17L, SW16L, SW15L, SW14L, SW13L,      SW13R, SW14R, SW15R, SW16R, SW17R, SW18R, \
    SW21L, SW20L, SW19L,                           SW19R, SW20R, SW21R) { \
    0, 0, 0, 0, 0, 0, \
    SW19L, SW20L, SW21L, SW13L, SW14L, SW15L, \
    SW16L, SW17L, SW07L, SW08L, SW09L, SW10L, \
    SW11L, SW01L, SW02L, SW03L, SW04L, SW05L, \
    SW06L, SW12L, SW18L, \
    0, 0, 0, 0, 0, 0, \
    SW19R, SW20R, SW21R, SW13R, SW14R, SW15R, \
    SW16R, SW17R, SW07R, SW08R, SW09R, SW10R, \
    SW11R, SW01R, SW02R, SW03R, SW04R, SW05R, \
    SW06R, SW12R, SW18R, \
}

const HSV palettes[] = {
    {HSV_OFF},
    {HSV_CORAL},
    {HSV_GREEN},
    {HSV_BLUE},
    {HSV_RED},
};

const uint8_t g_rgbmaps[][RGB_MATRIX_LED_COUNT] = {
    [_QWERTY] = MAC(
        3, 2, 2, 2, 2, 2,   2, 2, 2, 2, 2, 1,
        3, 2, 2, 2, 2, 2,   2, 2, 2, 2, 2, 2,
        3, 2, 2, 2, 2, 2,   2, 2, 2, 2, 2, 1,
                 3, 4, 3,   1, 4, 3
    ),
    [_LOWER] = MAC(
        1, 0, 0, 2, 0, 0,   0, 2, 2, 2, 0, 1,
        3, 0, 2, 2, 2, 0,   0, 2, 2, 2, 0, 0,
        3, 0, 0, 0, 0, 0,   2, 2, 2, 2, 0, 0,
                 3, 4, 3,   1, 4, 3
    ),
    [_SYMBOL] = MAC(
        0, 0, 0, 2, 0, 0,   0, 2, 2, 2, 0, 0,
        0, 0, 2, 2, 2, 0,   0, 2, 2, 2, 0, 0,
        0, 0, 0, 0, 0, 0,   2, 2, 2, 2, 0, 0,
                 3, 4, 3,   1, 4, 3
    ),
    [_ADJUST] = MAC(
        4, 1, 1, 0, 0, 0,   2, 2, 2, 1, 1, 1,
        4, 0, 0, 0, 0, 0,   1, 1, 1, 0, 0, 0,
        0, 0, 0, 0, 0, 0,   0, 0, 0, 0, 0, 0,
                 3, 4, 3,   1, 4, 3
    ),
    [_GAME_BASE] = MAC(
        3, 2, 4, 2, 2, 2,   2, 2, 2, 2, 2, 1,
        3, 4, 4, 4, 2, 2,   2, 2, 2, 2, 2, 2,
        3, 2, 2, 2, 2, 2,   2, 2, 2, 2, 2, 1,
                 3, 4, 3,   1, 4, 3
    ),
    [_GAME_BASE_EX] = MAC(
        3, 2, 4, 2, 2, 2,   4, 3, 3, 3, 3, 1,
        3, 4, 4, 4, 2, 2,   0, 3, 3, 3, 0, 0,
        3, 0, 2, 2, 2, 2,   0, 3, 3, 3, 0, 0,
                 3, 4, 3,   1, 4, 3
    ),
};

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    uint8_t mod_state = get_mods();
    uint8_t layer = get_highest_layer(layer_state|default_layer_state);

    if (layer <= _GAME_BASE_EX) {
        // rgb_matrix_set_color_all(0, 0, 0);

        for (int i = led_min; i < led_max; ++i) {
            HSV hsv = palettes[g_rgbmaps[layer][i]];

            if (mod_state & MOD_MASK_SHIFT && (i == 17 || i == 44)) {
                hsv = palettes[4];
            }
            else if (mod_state & MOD_MASK_CTRL && (i == 16 || i == 43)) {
                hsv = palettes[4];
            }
            else if (mod_state & MOD_MASK_ALT && (i == 15 || i == 42)) {
                hsv = palettes[4];
            }
            else if (mod_state & MOD_MASK_GUI && (i == 8 || i == 35)) {
                hsv = palettes[4];
            }

            #ifdef RGB_MATRIX_MAXIMUM_BRIGHTNESS
            hsv.v = hsv.v > RGB_MATRIX_MAXIMUM_BRIGHTNESS ? RGB_MATRIX_MAXIMUM_BRIGHTNESS : hsv.v;
            #endif

            RGB rgb = hsv_to_rgb(hsv);
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        }
    }
    return false;
}
