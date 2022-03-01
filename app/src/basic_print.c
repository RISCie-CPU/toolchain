#include "basic_print.h"

struct {
    uint32_t x;
    uint32_t y;
} static volatile cursor;

void set_cursor(uint32_t x, uint32_t y)
{
    cursor.x = x;
    cursor.y = y;
}

void basic_print(char *str)
{
    for (uint32_t i = 0; str[i]; i++)
    {
        for (int32_t y = 0; y < CHAR_Y_SIZE; y++)
        {
            for (int32_t x = 0; x < CHAR_X_SIZE; x++)
            {
                uint32_t address =                                            \
                  (x + (cursor.x * CHAR_X_SIZE))                              \
                  + ((y + (cursor.y * CHAR_Y_SIZE)) * SCREEN_PX_WIDTH);
                uint8_t value = (
                    ASCII[(uint8_t) str[i]][y] & (1 << x)
                  ) ? 0xFF : 0x00;
                vram_write_8b(address, value);
            }
        }
        if (++cursor.x > SCREEN_CHAR_WIDTH)
        {
            cursor.x = 0;
            if (++cursor.y > SCREEN_CHAR_HEIGHT)
            {
                cursor.y = 0;
            }
        }
    }
}
