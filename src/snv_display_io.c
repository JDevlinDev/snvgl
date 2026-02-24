#include "snv_display_io.h"

// SSD1306 I2C MACROS
#define I2C_HW_ADDR           0x3C

// LCD MACROS
#define LCD_PIXEL_CLOCK_HZ    (400 * 1000)
#define LCD_CMD_BITS           8
#define LCD_PARAM_BITS         8

// SSD1306 COMMANDS
#define CMD_SET_MEMORY_ADDR_MODE  0x20
#define CMD_SET_COLUMN_RANGE      0x21
#define CMD_SET_PAGE_RANGE        0x22
#define CMD_SET_CHARGE_PUMP       0x8D
#define CMD_CHARGE_PUMP_ON        0x14
#define CMD_CHARGE_PUMP_OFF       0x10
#define CMD_MIRROR_X_OFF          0xA0
#define CMD_MIRROR_X_ON           0xA1
#define CMD_INVERT_OFF            0xA6
#define CMD_INVERT_ON             0xA7
#define CMD_SET_MULTIPLEX         0xA8
#define CMD_DISP_OFF              0xAE
#define CMD_DISP_ON               0xAF
#define CMD_MIRROR_Y_OFF          0xC0
#define CMD_MIRROR_Y_ON           0xC8
#define CMD_SET_COMPINS           0xDA
#define CMD_ALL_PIXELS_ON         0xA5
#define CMD_ALL_PIXELS_RAM        0xA4

esp_err_t ssd1306_init(esp_lcd_panel_handle_t *ret_panel);
esp_err_t ssd1306_del(esp_lcd_panel_handle_t panel);
esp_err_t ssd1306_flush_buffer(esp_lcd_panel_handle_t panel, uint8_t *buf);