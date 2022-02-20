#include "riscie.h"

uint32_t array[][2] = {
    { 100, 0xC0 },
    { 200, 0x3F },
    { 300, 0x0F },
};

int main(void)
{
    for (uint32_t i = 0; i < sizeof(array) / sizeof(uint32_t); i++)
        vram_write_8b(array[i][0], array[i][1]);

    return 0;
}
