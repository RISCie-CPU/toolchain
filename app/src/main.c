#include "riscie.h"
#include "basic_print.h"


int main(void)
{
    basic_print("1\n");
    basic_print("12\n");
    basic_print("123\n");
    basic_print("1234\n");
    basic_print("12345\n");
    basic_print("123456\n");
    basic_print("1234567\n");
    basic_print("12345678\n");
    basic_print("123456789\n");
    basic_print("1234567890\n");

    set_cursor(0, 20);
    while (1)
    {
        basic_print("\rGlory to Ukraine !!!  ");
        basic_print("\rPutin is a psychopath.");
    }
}
