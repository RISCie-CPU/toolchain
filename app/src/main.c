#include "riscie.h"

int main(void)
{
    uint8_t address = 0;
    uint8_t data    = 0xFF;
    while (1)
    {
        vram_write_8b(address, data);
        if (address++ == 0xFF)
            data = ~data;
    }
}
