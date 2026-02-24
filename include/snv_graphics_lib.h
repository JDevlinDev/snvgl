/**
 * @author Jason Sherrick
 * @date 02/23/2026
 * 
 * License: Apache-2.0
 * 
 *  SNVGL graphics library for drawing to the frame buffer
 */
#pragma once

#include <stdint.h>
#include <stdbool.h>

#include "snv_graphics_types.h"

/**
 * @brief Draws a point to the frame buffer
 * 
 * @param[in] buf Pointer to the frame buffer
 * @param[in] point The snv_point containing valid x,y coordinates
 * @param[in] state Indicate whether PIXEL_ON or PIXEL_OFF for this draw operation
 */
void snv_draw_point(uint8_t *buf, snv_point point, snv_pixel_state px_state);

/**
 * @brief Draws a point to the frame buffer
 * 
 * @param[in] buf Pointer to the frame buffer
 * @param[in] line The snv_point containing valid x,y coordinates
 * @param[in] state Indicate whether PIXEL_ON or PIXEL_OFF for this draw operation
 */
void snv_draw_line(uint8_t *buf, snv_line line, snv_pixel_state px_state);

/**
 * @brief Draws a rectangle to the frame buffer
 * 
 * @param[in] buf Pointer to the frame buffer
 * @param[in] rect The snv_rect to draw to the buffer
 * @param[in] state Indicate whether PIXEL_ON or PIXEL_OFF for this draw operation
 */
void snv_draw_rect(uint8_t *buf, snv_rect rect, snv_pixel_state px_state);


/**
 * @brief Clears the buffer i.e. resets the memory to all 0's
 * 
 * @param[in] buf Pointer to the frame buffer to clear
 */
void snv_buffer_clear(uint8_t *buf);