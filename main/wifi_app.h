/**
 * @file wifi_app.h
 * @author tardhiansyah (tardhians@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-02-14
 * 
 * 
 */

#ifndef MAIN_WIFI_APP_H_
#define MAIN_WIFI_APP_H_

#include "esp_netif.h"
#include "esp_wifi.h"

// WiFi application settings
#define WIFI_AP_SSID                "ESP32_AP"      // AP name
#define WIFI_AP_PASSWORD            "12345678"      // AP password
#define WIFI_AP_CHANNEL             1               // AP channel
#define WIFI_AP_SSID_HIDDEN         0               // AP visibility
#define WIFI_AP_MAX_CONNECTIONS     4               // AP maxconnections
#define WIFI_AP_BEACON_INTERVAL     100             // AP Beacon interval
#define WIFI_AP_IP_ADDRESS          "192.168.0.1"   // AP IP address
#define WIFI_AP_IP_GATEWAY          "192.168.0.1"   // AP IP gateway (same as IP address)
#define WIFI_AP_IP_NETMASK          "255.255.255.0" // AP IP netmask
#define WIFI_AP_BANDWIDTH           WIFI_BW_HT20    // AP bandwidth (20 MHz)
#define WIFI_STA_POWER_SAVE         WIFI_PS_NONE    // STA power save mode not used
#define MAX_SSID_LENGTH             32              // IEEE 802.11 SSID length
#define MAX_PASSWORD_LENGTH         64              // IEEE 802.11 password length
#define MAX_CONNECTION_RETRIES      5               // Maximum number of retries on disconnection

// Network interface object for station and access point
extern esp_netif_t *esp_netif_sta;
extern esp_netif_t *esp_netif_ap;

/**
 * @brief Message IDs for the WiFi application task
 * @note Expand this list based on the requirements
 * 
 */
typedef enum wifi_ap_message {
    WIFI_APP_MSG_START_HTTP_SERVER = 0,
    WIFI_APP_MSG_CONNECTING_FROM_HTTP_SERVER,
    WIFI_APP_MSG_STA_CONNECTED_GOT_IP,
} wifi_ap_message_e;

/**
 * @brief Structure for the message queue of the WiFi application task
 * @note Expand this structure based on the requirements
 * 
 */
typedef struct wifi_ap_queue_message {
    wifi_ap_message_e message_id;
} wifi_ap_queue_message_t;

/**
 * @brief Send a message to the queue
 * @param message_id Message ID from the wifi_ap_message_e enumeration
 * @return pdTRUE if the message is successfully sent, otherwise pdFALSE
 * @note Expand this function based on the requirements e.g. how you've implemented the message queue
 * 
 */
BaseType_t wifi_ap_send_message(wifi_ap_message_e message_id);

/**
 * @brief Starts the WiFi application task
 * 
 */
void wifi_app_start(void);

#endif /* MAIN_WIFI_APP_H_ */