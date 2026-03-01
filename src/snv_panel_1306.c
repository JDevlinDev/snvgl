#include <stdint.h>
#include <stdbool.h>

#include "driver/i2c_master.h"
#include "esp_lcd_types.h"
#include "esp_lcd_panel_ops.h"
#include "esp_lcd_panel_io.h"
#include "esp_lcd_panel_dev.h"

#include "esp_err.h"
#include "esp_log.h"

#include "snv_panel_1306.h"

// SSD1306 I2C MACROS
#define I2C_HW_ADDR           0x3C

// LCD MACROS
#define LCD_PIXEL_CLOCK_HZ    (400 * 1000)
#define LCD_CMD_BITS           8
#define LCD_PARAM_BITS         8
#define LCD_H_RES              128
#define LCD_V_RES              64

static const char *TAG = "snv_panel_1306";

static i2c_master_bus_handle_t i2c_bus_handle = NULL;
static const i2c_master_bus_config_t i2c_bus_config = {
    .clk_source = I2C_CLK_SRC_DEFAULT,
    .glitch_ignore_cnt = 7,
    .i2c_port = I2C_NUM_0,
    .sda_io_num = 8,
    .scl_io_num = 9,
    .flags.enable_internal_pullup = true
};

static esp_lcd_panel_io_handle_t io_handle = NULL;
static const esp_lcd_panel_io_i2c_config_t io_config = {
    .dev_addr = I2C_HW_ADDR,
    .scl_speed_hz = LCD_PIXEL_CLOCK_HZ,
    .control_phase_bytes = 1,
    .lcd_cmd_bits = LCD_CMD_BITS,
    .lcd_param_bits = LCD_CMD_BITS,
    .dc_bit_offset = 6
};

static const esp_lcd_panel_dev_config_t panel_config = {
        .bits_per_pixel = 1,
        .reset_gpio_num = -1,
};

esp_err_t snv_new_panel_1306(snv_panel_t *panel)
{
    esp_err_t err = i2c_new_master_bus(&i2c_bus_config, &i2c_bus_handle);
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "Failed to allocate an i2c master bus");
        return err;
    }

    err = esp_lcd_new_panel_io_i2c(i2c_bus_handle, &io_config, &io_handle);
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "Failed to create LCD panel IO handle");
        return err;
    }
    
    err = esp_lcd_new_panel_ssd1306(io_handle, &panel_config, panel);
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "Failed to create LCD panel for SSD1306");
        return err;
    }

    err = esp_lcd_panel_reset(panel);
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "Failed to reset the LCD panel");
        return err;
    }

    err = esp_lcd_panel_init(panel);
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "Failed to initialize the LCD panel");
        return err;
    }

    err = esp_lcd_panel_disp_on_off(panel, true);
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "Failed to to turn on the LCD panel");
        return err;
    }

    ESP_LOGI(TAG, "LCD panel successfully initialized");
    return err;
}

esp_err_t snv_panel_send_buffer(snv_panel_t *panel)
{
    esp_err_t err;
    err = esp_lcd_panel_draw_bitmap(panel, 0, 0, LCD_H_RES, LCD_V_RES, panel->frame_buffer);
    return err;
}