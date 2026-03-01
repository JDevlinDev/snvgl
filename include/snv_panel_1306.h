/**
 * @author Jason Sherrick
 * @date 02/23/2026
 * 
 * License: Apache-2.0
 */
#pragma once

#include <stdint.h>
#include "esp_lcd_types.h"
#include "esp_err.h"

typedef struct {
    esp_lcd_panel_handle_t oled_panel;
    uint8_t *frame_buffer;
} snv_panel_t;

/**
 * @brief Create panel for OLED connected to model SSD1306
 * 
 * @param[in] display OLED panel handle
 * 
 * @return
 *  - ESP_OK    on success
 *  - anything else, not okay
 */
esp_err_t snv_new_panel_1306(snv_panel_t *display);