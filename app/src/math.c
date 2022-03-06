#include "math.h"

int abs(int number)
{
    if (number < 0)
    {
        return number * -1;
    }
    else
    {
        return number;
    }
}