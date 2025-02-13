/**
 * @file rgb_led.h
 * @author tardhiansyah (tardhians@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-02-13
 * 
 * 
 */

#ifndef MAIN_RGB_LED_H_
#define MAIN_RGB_LED_H_

#define RGB_LED_SET_MAGENTA() rgb_led_set_color(255, 102, 255)
#define RGB_LED_SET_YELLOW() rgb_led_set_color(204, 255, 51)
#define RGB_LED_SET_CYAN() rgb_led_set_color(0, 255, 153)

// RGB LED GPIOs
#define RGB_LED_RED_GPIO        12
#define RGB_LED_GREEN_GPIO      13
#define RGB_LED_BLUE_GPIO       14

// RGB LED color channels
#define RGB_LED_CHANNEL_NUM     3

// RGB LED colors enum
typedef enum {
    RGB_LED_RED = 0,
    RGB_LED_GREEN,
    RGB_LED_BLUE
} rgb_led_color_e;

// RGB LED configuration
typedef struct {
    int channel;
    int gpio;
    int mode;
    int timer_index;
} ledc_info_t;

// Extern variables declaration
// RGB LED color channels
extern ledc_info_t ledc_ch[RGB_LED_CHANNEL_NUM];

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