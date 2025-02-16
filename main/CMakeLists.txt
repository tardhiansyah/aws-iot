if(IDF_TARGET STREQUAL "esp32c6")
    idf_component_register(SRCS "wifi_app.c" "rgb_led_strip.c" "main.c"
                        INCLUDE_DIRS ".")
else()
    idf_component_register(SRCS "wifi_app.c" "rgb_led.c" "main.c"
                        INCLUDE_DIRS ".")
endif()