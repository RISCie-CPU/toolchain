#include <stdlib.h>
#include "riscie_graphics.h"

Matrix_1x3 *matrix_multiply_1x3(Matrix_1x3 *m1, Matrix_3x3 *m2)
{
    Matrix_1x3 *out = (Matrix_1x3 *)malloc(sizeof(Matrix_1x3));

    // u = u*0 + v*3 + w*6
    (*out)[0][0] = ((*m1)[0][0] * (*m2)[0][0] + (*m1)[0][1] * (*m2)[1][0] + (*m1)[0][2] * (*m2)[2][0]) >> FIXED_BITS;
    // v = u*1 + v*4 + w*7
    (*out)[0][1] = ((*m1)[0][0] * (*m2)[0][1] + (*m1)[0][1] * (*m2)[1][1] + (*m1)[0][2] * (*m2)[2][1]) >> FIXED_BITS;
    // w = u*2 + v*5 + w*8
    (*out)[0][2] = ((*m1)[0][0] * (*m2)[0][2] + (*m1)[0][1] * (*m2)[1][2] + (*m1)[0][2] * (*m2)[2][2]) >> FIXED_BITS;

    return out;
}

Matrix_3x1 *matrix_multiply_3x1(Matrix_3x3 *m1, Matrix_3x1 *m2)
{
    Matrix_3x1 *out = (Matrix_3x1 *)malloc(sizeof(Matrix_3x1));

    // u = u*0 + v*3 + w*6
    (*out)[0][0] = ((*m1)[0][0] * (*m2)[0][0] + (*m1)[0][1] * (*m2)[1][0] + (*m1)[0][2] * (*m2)[2][0]) >> FIXED_BITS;
    // v = u*1 + v*4 + w*7
    (*out)[1][0] = ((*m1)[1][0] * (*m2)[0][0] + (*m1)[1][1] * (*m2)[1][0] + (*m1)[1][2] * (*m2)[2][0]) >> FIXED_BITS;
    // w = u*2 + v*5 + w*8
    (*out)[2][0] = ((*m1)[2][0] * (*m2)[0][0] + (*m1)[2][1] * (*m2)[1][0] + (*m1)[2][2] * (*m2)[2][0]) >> FIXED_BITS;

    return out;
}

void draw_object_2D(Point *vertices, int verices_size, Matrix_3x3 *matrix)
{
    // Point current_point = vertices[0];
    Point current_point = vertices[0];
    Point next_point;

    // __asm__("nop");
    
    // // Když odeberu tuto matici, která se nikde nevolá, tak to "funguje"
    // Matrix_3x3 TADY = {{1, 0, 30},
    //                    {0, 1, 30},
    //                    {0, 0, 1}};
    // __asm__("nop");
    // __asm__("nop");

    // Matrix_3x1 *mult = matrix_multiply_3x1(matrix, &current_point);
    // current_point.x = (*mult)[0][0];
    // current_point.y = (*mult)[1][0];
    // free(mult);

    // Matrix_3x1 point_2 = {{INT2FIXED(10)}, {INT2FIXED(10)}, {INT2FIXED(1)}};
    // Matrix_3x1 *out_2 = matrix_multiply_3x1(matrix, &point_2);
    // // current_point.x = (*out_2)[0][0];
    // // current_point.y = (*out_2)[1][0];
    // free(out_2);

    for (int vertex = 0; vertex < verices_size - 1; vertex++)
    {
        next_point = vertices[vertex + 1];
        draw_line(current_point, next_point, 255);

        current_point = next_point;
    }
}

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
        x1 = y1;
        y1 = tmp;

        tmp = x2;
        x2 = y2;
        y2 = tmp;

        dx = x2 - x1;
        dy = y2 - y1;

        has_swapped = 1;
    }

    if (x1 > x2)
    {
        tmp = x2;
        x2 = x1;
        x1 = tmp;

        tmp = y2;
        y2 = y1;
        y1 = tmp;
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

    int P = 1 - radius;
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
            P += X2;
            X2 += 2;
            --local_x;
        }

        P += Y2;
        Y2 += 2;
        ++local_y;
    }

    //     put8PixelsOfCircle(x, y, s1, s2, color);
} /* draw_circle_MP */

void draw_point(Point p, uint8_t color)
{
    set_pixel((p.x >> 5) + X_SCREEN_CENTER, Y_SCREEN_CENTER - (p.y >> 5), color);
}

void draw_line(Point p1, Point p2, uint8_t color)
{
    draw_line_dda((p1.x >> 5) + X_SCREEN_CENTER, Y_SCREEN_CENTER - (p1.y >> 5), (p2.x >> 5) + X_SCREEN_CENTER, Y_SCREEN_CENTER - (p2.y >> 5), color);
}