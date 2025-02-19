/**
 * @file rgb_led.c
 * @author tardhiansyah
 * @brief 
 * @version 0.1
 * @date 2025-02-13
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <stdbool.h>

#include "driver/ledc.h"
#include "rgb_led.h"

ledc_info_t ledc_ch[RGB_LED_CHANNEL_NUM];

// handle RGB LED initialization
static bool s_rgb_led_initialized = false;

/**
 * @brief Initiialize the RGB LED settings per channel, including
 * the GPIO for each color, mode, and timer configuration
 * 
 */
static void rgb_led_pwm_init(void) {
    // Red
    ledc_ch[RGB_LED_RED].channel     = LEDC_CHANNEL_0;
    ledc_ch[RGB_LED_RED].gpio        = RGB_LED_RED_GPIO;
    ledc_ch[RGB_LED_RED].mode        = LEDC_LOW_SPEED_MODE;
    ledc_ch[RGB_LED_RED].timer_index = LEDC_TIMER_0;

    // Green
    ledc_ch[RGB_LED_GREEN].channel     = LEDC_CHANNEL_1;
    ledc_ch[RGB_LED_GREEN].gpio        = RGB_LED_GREEN_GPIO;
    ledc_ch[RGB_LED_GREEN].mode        = LEDC_LOW_SPEED_MODE;
    ledc_ch[RGB_LED_GREEN].timer_index = LEDC_TIMER_0;

    // Blue
    ledc_ch[RGB_LED_BLUE].channel     = LEDC_CHANNEL_2;
    ledc_ch[RGB_LED_BLUE].gpio        = RGB_LED_BLUE_GPIO;
    ledc_ch[RGB_LED_BLUE].mode        = LEDC_LOW_SPEED_MODE;
    ledc_ch[RGB_LED_BLUE].timer_index = LEDC_TIMER_0;

    // Configure timer zero
    ledc_timer_config_t ledc_timer = {
        .duty_resolution = LEDC_TIMER_8_BIT,
        .freq_hz = 100,
        .speed_mode = LEDC_LOW_SPEED_MODE,
        .timer_num = LEDC_TIMER_0
    };
    ledc_timer_config(&ledc_timer);

    // Configure each channel
    for (int rgb_ch = 0; rgb_ch < RGB_LED_CHANNEL_NUM; rgb_ch++) {
        ledc_channel_config_t ledc_channel = {
            .channel = ledc_ch[rgb_ch].channel,
            .duty = 0,
            .hpoint = 0,
            .gpio_num = ledc_ch[rgb_ch].gpio,  
            .intr_type = LEDC_INTR_DISABLE,
            .speed_mode = ledc_ch[rgb_ch].mode,
            .timer_sel = ledc_ch[rgb_ch].timer_index,
        };
        ledc_channel_config(&ledc_channel);
    }

    s_rgb_led_initialized = true;
}

/**
 * @brief Sets the RGB LED color based on the given RGB values
 * 
 */
static void rgb_led_set_color(uint8_t red, uint8_t green, uint8_t blue) {
    // Value range is 0-255

    // Red channel
    ledc_set_duty(ledc_ch[RGB_LED_RED].mode, ledc_ch[RGB_LED_RED].channel, red);
    ledc_update_duty(ledc_ch[RGB_LED_RED].mode, ledc_ch[RGB_LED_RED].channel);

    // Green channel
    ledc_set_duty(ledc_ch[RGB_LED_GREEN].mode, ledc_ch[RGB_LED_GREEN].channel, red);
    ledc_update_duty(ledc_ch[RGB_LED_GREEN].mode, ledc_ch[RGB_LED_GREEN].channel);

    // Blue channel
    ledc_set_duty(ledc_ch[RGB_LED_BLUE].mode, ledc_ch[RGB_LED_BLUE].channel, red);
    ledc_update_duty(ledc_ch[RGB_LED_BLUE].mode, ledc_ch[RGB_LED_BLUE].channel);
}

void rgb_led_wifi_app_started(void) {
    if (!s_rgb_led_initialized) {
        rgb_led_pwm_init();
    }

    RGB_LED_SET_MAGENTA();
}

void rgb_led_http_server_started(void) {
    if (!s_rgb_led_initialized) {
        rgb_led_pwm_init();
    }

    RGB_LED_SET_YELLOW();
}

void rgb_led_wifi_connected(void) {
    if (!s_rgb_led_initialized) {
        rgb_led_pwm_init();
    }

    RGB_LED_SET_CYAN();
}