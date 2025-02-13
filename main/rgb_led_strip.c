/**
 * @file rgb_led_strip.c
 * @author tardhiansyah (tardhians@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-02-13
 * 
 * 
 */

#include <stdbool.h>

#include "esp_log.h"
#include "led_strip.h"
#include "driver/gpio.h"
#include "rgb_led_strip.h"

// handle led strip
static led_strip_handle_t s_led_strip;

// handle RGB LED initialization
static bool s_rgb_led_initialized = false;

/**
 * @brief Configure the RGB LED strip
 * 
 * @return led_strip_handle_t object to handle the RGB LED strip
 */
static led_strip_handle_t configure_led(void) {
    ESP_LOGD(LOG_TAG, "Initializing RGB LED strip");

    led_strip_config_t strip_config = {
        .strip_gpio_num = LED_STRIP_GPIO_PIN,
        .max_leds = LED_STRIP_LED_COUNT,
        .led_model = LED_MODEL_WS2812,
        .color_component_format = LED_STRIP_COLOR_COMPONENT_FMT_GRB,
        .flags = {
            .invert_out = false,
        }
    };

    led_strip_rmt_config_t rmt_config = {
        .clk_src = RMT_CLK_SRC_DEFAULT,
        .resolution_hz = LED_STRIP_RMT_RES_HZ,
        .mem_block_symbols = 64,
        .flags.with_dma = false,
    };

    led_strip_handle_t led_strip;
    ESP_ERROR_CHECK(led_strip_new_rmt_device(&strip_config, &rmt_config, &led_strip));
    ESP_LOGD(LOG_TAG, "Created LED strip object with RMT backend");

    return led_strip;
}

/**
 * @brief Initialize the RGB LED strip
 * 
 */
static void rgb_led_strip_init(void) {
    s_led_strip = configure_led();
    s_rgb_led_initialized = true;
    ESP_LOGD(LOG_TAG, "RGB LED strip initialized");
}

/**
 * @brief Set the RGB LED color
 * 
 * @param red Red color value (0-255)
 * @param green Green color value (0-255)
 * @param blue Blue color value (0-255)
 */
static void rgb_led_set_color(uint8_t red, uint8_t green, uint8_t blue) {
    for (int i = 0; i < LED_STRIP_LED_COUNT; i++) {
        ESP_ERROR_CHECK(led_strip_set_pixel(s_led_strip, i, red, green, blue));
    }
    ESP_ERROR_CHECK(led_strip_refresh(s_led_strip));
}

void rgb_led_wifi_app_started(void) {
    if (!s_rgb_led_initialized) {
        rgb_led_strip_init();
    }

    RGB_LED_SET_MAGENTA();
    ESP_LOGD(LOG_TAG, "Setting RGB LED color to indicate WiFi application has started");
}

void rgb_led_http_server_started(void) {
    if (!s_rgb_led_initialized) {
        rgb_led_strip_init();
    }

    RGB_LED_SET_YELLOW();
    ESP_LOGD(LOG_TAG, "Setting RGB LED color to indicate HTTP server has started");
}

void rgb_led_wifi_connected(void) {
    if (!s_rgb_led_initialized) {
        rgb_led_strip_init();
    }

    RGB_LED_SET_CYAN();
    ESP_LOGD(LOG_TAG, "Setting RGB LED color to indicate device is connected to access point");
}