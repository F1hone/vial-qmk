RGB_MATRIX_EFFECT(SOLID_COLOR_WHITE)

RGB_MATRIX_EFFECT(BREATHING_WHITE)

#    ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

bool SOLID_COLOR_WHITE(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        rgb_matrix_set_color(i, 0, 0, 0 ,255);
    }
    return rgb_matrix_check_finished_leds(led_max);
}

bool BREATHING_WHITE(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    // Create an HSV structure with hue=0 (not used), saturation=0 (no color), and maximum brightness
    HSV hsv  = {0, 0, 1};
    // Adjust the brightness over time to create a breathing effect
    uint16_t time = scale16by8(g_rgb_timer, rgb_matrix_config.speed / 8);
    hsv.v         = scale8(abs8(sin8(time) - 128) * 2, hsv.v);

    // Convert the HSV value to RGBW
    RGB rgb       = rgb_matrix_hsv_to_rgb(hsv);
    uint8_t white = hsv.v;  // Set W channel brightness based on the breathing effect

    // Apply the color to the LEDs
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        rgb_matrix_set_color(i, 0, 0, 0, white);  // Set only the W channel, RGB all off
    }

    return rgb_matrix_check_finished_leds(led_max);
}


#endif
