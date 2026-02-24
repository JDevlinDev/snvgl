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
} snv_display_t;

esp_err_t snv_init(snv_display_t *display);
esp_err_t snv_free(snv_display_t *display);
esp_err_t snv_send_buffer(snv_display_t *display);