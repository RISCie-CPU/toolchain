#include "riscie.h"

uint32_t glob_address = 0x900;

int main(void)
{
    uint32_t address = glob_address;
    uint8_t data     = 0xFF;
    vram_write_8b(address, data);
}
