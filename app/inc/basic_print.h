#pragma once

#include "ascii.h"
#include "riscie.h"

#define SCREEN_CHAR_WIDTH 40
#define SCREEN_CHAR_HEIGHT 20

void set_cursor(uint32_t x, uint32_t y);
void basic_print(char *str);
