#include "riscie_graphics.h"

void draw_line_dda(int x1, int y1, int x2, int y2, uint8_t color)
{
    if (x1 == x2 && y1 == y2)
    {
        return;
    }

    int dx = x2 - x1;
    int dy = y2 - y1;

    int tmp;
    uint8_t has_swapped = 0;

    if (abs(dy) > abs(dx))
    {
        tmp = x1;
        x1  = y1;
        y1  = tmp;

        tmp = x2;
        x2  = y2;
        y2  = tmp;

        dx = x2 - x1;
        dy = y2 - y1;

        has_swapped = 1;
    }

    if (x1 > x2)
    {
        tmp = x2;
        x2  = x1;
        x1  = tmp;

        tmp = y2;
        y2  = y1;
        y1  = tmp;
    }

    int y = y1 << FRAC_BITS;
    int k = (dy << FRAC_BITS) / dx;

    // TODO: Improve speed (if statement in for loop)
    for (int x = x1; x <= x2; ++x)
    {
        if (has_swapped)
        {
            set_pixel(y >> FRAC_BITS, x, color);
        }
        else
        {
            set_pixel(x, y >> FRAC_BITS, color);
        }
        y += k;
    }
} /* draw_line_DDA */

void set_pixel(int x, int y, uint8_t color)
{
    vram_write_8b(x + (512 * y), color);
}

void draw_circle_mp(int x, int y, int radius, uint8_t color)
{
    int local_x = radius;
    int local_y = 0;

    int P  = 1 - radius;
    int X2 = 2 - 2 * radius;
    int Y2 = 3;

    while (local_x >= local_y)
    {
        set_pixel(x + local_x, y + local_y, color);
        set_pixel(x - local_x, y - local_y, color);
        set_pixel(x - local_x, y + local_y, color);
        set_pixel(x + local_x, y - local_y, color);

        set_pixel(x + local_y, y + local_x, color);
        set_pixel(x - local_y, y - local_x, color);
        set_pixel(x + local_y, y - local_x, color);
        set_pixel(x - local_y, y + local_x, color);

        if (P >= local_y)
        {
            P  += X2;
            X2 += 2;
            --local_x;
        }

        P  += Y2;
        Y2 += 2;
        ++local_y;
    }

    //     put8PixelsOfCircle(x, y, s1, s2, color);
} /* draw_circle_MP */
