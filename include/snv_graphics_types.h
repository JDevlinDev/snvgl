/**
 * @author Jason Sherrick
 * @date 02/23/2026
 * 
 * License: Apache-2.0
 */
#pragma once

#include <stdint.h>
#include <stdbool.h>

typedef struct {
    uint8_t x;
    uint8_t y;
} snv_point;

typedef struct {
    snv_point p0;
    snv_point p1;
} snv_line;

typedef struct {
    snv_line top;
    snv_line botton;
    snv_line right;
    snv_line left;
    bool has_fill;
} snv_rect;

typedef struct {
    snv_point center;
    uint8_t radius;
    bool has_fill;
} snv_circle;

typedef enum {
    PIXEL_OFF = 0,
    PIXEL_ON
} snv_pixel_state;

typedef snv_char snv_char; // TODO: Make an snv_char
typedef snv_text snv_text; // TODO: Make a type to for a string of text
// More TODO: Characters/fonts?