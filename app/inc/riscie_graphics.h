#pragma once

#include "riscie.h"
#include "riscie_math.h"

#define FRAC_BITS 8

void set_pixel(int x, int y, uint8_t color);
void draw_line_dda(int x1, int y1, int x2, int y2, uint8_t color);
void draw_circle_mp(int x, int y, int radius, uint8_t color);
