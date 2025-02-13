/**
 * @file rgb_led_strip.h
 * @author tardhiansyah (tardhians@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-02-13
 * 
 * 
 */

#ifndef MAIN_RGB_LED_STRIP_H_
#define MAIN_RGB_LED_STRIP_H_

#define LOG_TAG "RGB_LED"

#define LED_STRIP_GPIO_PIN  8
#define LED_STRIP_LED_COUNT 1
#define LED_STRIP_RMT_RES_HZ  (10 * 1000 * 1000)

#define RGB_LED_SET_MAGENTA() rgb_led_set_color(255, 102, 255)
#define RGB_LED_SET_YELLOW() rgb_led_set_color(204, 255, 51)
#define RGB_LED_SET_CYAN() rgb_led_set_color(0, 255, 153)

/**
 * @brief Color to indicate WiFi application has started
 * 
 */
void rgb_led_wifi_app_started(void);

/**
 * @brief Color to indicate HTTP server has started
 * 
 */
void rgb_led_http_server_started(void);

/**
 * @brief Color to indicate device is connected to access point
 * 
 */
void rgb_led_wifi_connected(void);

#endif /* MAIN_RGB_LED_H_ */