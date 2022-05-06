#include <stdlib.h>
#include "riscie_graphics.h"

void matrix_multiply_3x1(Matrix_3x1 *out, Matrix_3x3 *m1, Matrix_3x1 *m2)
{
    (*out)[0][0] = ((*m1)[0][0] * (*m2)[0][0] + (*m1)[0][1] * (*m2)[1][0] + (*m1)[0][2] * (*m2)[2][0]) >> FIXED_BITS;
    (*out)[1][0] = ((*m1)[1][0] * (*m2)[0][0] + (*m1)[1][1] * (*m2)[1][0] + (*m1)[1][2] * (*m2)[2][0]) >> FIXED_BITS;
    (*out)[2][0] = ((*m1)[2][0] * (*m2)[0][0] + (*m1)[2][1] * (*m2)[1][0] + (*m1)[2][2] * (*m2)[2][0]) >> FIXED_BITS;
}

void matrix_multiply_4x1(Matrix_4x1 *out, Matrix_4x4 *m1, Matrix_4x1 *m2)
{
    (*out)[0][0] = ((*m1)[0][0] * (*m2)[0][0] + (*m1)[0][1] * (*m2)[1][0] + (*m1)[0][2] * (*m2)[2][0] + (*m1)[0][3] * (*m2)[3][0]) >> FIXED_BITS;
    (*out)[1][0] = ((*m1)[1][0] * (*m2)[0][0] + (*m1)[1][1] * (*m2)[1][0] + (*m1)[1][2] * (*m2)[2][0] + (*m1)[1][3] * (*m2)[3][0]) >> FIXED_BITS;
    (*out)[2][0] = ((*m1)[2][0] * (*m2)[0][0] + (*m1)[2][1] * (*m2)[1][0] + (*m1)[2][2] * (*m2)[2][0] + (*m1)[2][3] * (*m2)[3][0]) >> FIXED_BITS;
    (*out)[3][0] = ((*m1)[3][0] * (*m2)[0][0] + (*m1)[3][1] * (*m2)[1][0] + (*m1)[3][2] * (*m2)[2][0] + (*m1)[3][3] * (*m2)[3][0]) >> FIXED_BITS;
}

void matrix_multiply_4x4(Matrix_4x4 *out, Matrix_4x4 *m1, Matrix_4x4 *m2)
{
    for (int y = 0; y < 4; y++)
    {
        for (int x = 0; x < 4; x++)
        {
            (*out)[y][x] = ((*m1)[y][0] * (*m2)[0][x] + (*m1)[y][1] * (*m2)[1][x] + (*m1)[y][2] * (*m2)[2][x]+ (*m1)[y][3] * (*m2)[3][x]) >> FIXED_BITS;
        }
    }
}


void draw_object_2D(Point *vertices, int verices_size, Matrix_3x3 *matrix, uint8_t color)
{
    Point current_point = vertices[0];
    Point next_point;
    
    Matrix_3x1 f_point;
    matrix_multiply_3x1(&f_point, matrix, &current_point);
    current_point.x = f_point[0][0];
    current_point.y = f_point[1][0];

    
    for (int vertex = 0; vertex < verices_size - 1; vertex++)
    {

        next_point = vertices[vertex + 1];
        
        Matrix_3x1 n_point;
        matrix_multiply_3x1(&n_point, matrix, &next_point);
        next_point.x = n_point[0][0];
        next_point.y = n_point[1][0];
        
        draw_line(current_point, next_point, color);

        current_point = next_point;
    }
}

void draw_object_3D(vec4 *vertices, int verices_size, Matrix_4x4 *matrix, uint8_t color)
{
    vec4 current_point = vertices[0];
    vec4 next_point;

    Matrix_4x1 f_point;
    matrix_multiply_4x1(&f_point, matrix, &current_point);
    current_point.x = f_point[0][0];
    current_point.y = f_point[1][0];
    current_point.z = f_point[2][0];

    int linePass = 4;
    for (int vertex = 0; vertex < verices_size - 1; vertex++)
    {
        next_point = vertices[vertex + 1];
        
        Matrix_4x1 n_point;
        matrix_multiply_4x1(&n_point, matrix, &next_point);
        next_point.x = n_point[0][0];
        next_point.y = n_point[1][0];
        next_point.z = n_point[2][0];
        
        Point p1 = {current_point.x, current_point.y, 1};
        Point p2 = {next_point.x, next_point.y, 1};

        if (linePass == 0 || color == 0)
        {
            draw_line(p1, p2, color);
        }
        else
        {
            draw_line(p1, p2, 0b11100000);
            linePass--;
        }
        current_point = next_point;
    }

}

void pinedaTriangle(Point v1, Point v2, Point v3, int base_color)
{
    int min_y = MIN(MIN(v1.y, v2.y), v3.y);
    int min_x = MIN(MIN(v1.x, v2.x), v3.x);

    int max_y = MAX(MAX(v1.y, v2.y), v3.y);
    int max_x = MAX(MAX(v1.x, v2.x), v3.x);

    min_x = MAX(0, min_x);
    max_x = MIN(X_SCREEN_WIDTH - 1, max_x);

    min_y = MAX(0, min_y);
    max_y = MIN(Y_SCREEN_HEIGHT - 1, max_y);

    int deltaX1 = v2.x - v1.x;
    int deltaX2 = v3.x - v2.x;
    int deltaX3 = v1.x - v3.x;

    int deltaY1 = v2.y - v1.y;
    int deltaY2 = v3.y - v2.y;
    int deltaY3 = v1.y - v3.y;

    int edgeF1 = (min_y - v1.y) * deltaX1 - (min_x - v1.x) * deltaY1;
    int edgeF2 = (min_y - v2.y) * deltaX2 - (min_x - v2.x) * deltaY2;
    int edgeF3 = (min_y - v3.y) * deltaX3 - (min_x - v3.x) * deltaY3;



    for (int y = min_y; y <= max_y; y++) {
        int t1 = edgeF1;
        int t2 = edgeF2;
        int t3 = edgeF3;
        for (int x = min_x; x <= max_x; ++x) {
            if (t1 >= 0 && t2 >= 0 && t3 >= 0) {
                set_pixel(x, y, base_color % 255);
            }

            t1 -= deltaY1;
        	t2 -= deltaY2;
            t3 -= deltaY3;
        }
        edgeF1 += deltaX1;
        edgeF2 += deltaX2;
        edgeF3 += deltaX3;

        base_color++;
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
    set_pixel((p.x >> FIXED_BITS) + X_SCREEN_CENTER, Y_SCREEN_CENTER - (p.y >> FIXED_BITS), color);
}

void draw_line(Point p1, Point p2, uint8_t color)
{
    draw_line_dda((p1.x >> FIXED_BITS) + X_SCREEN_CENTER, Y_SCREEN_CENTER - (p1.y >> FIXED_BITS), (p2.x >> FIXED_BITS) + X_SCREEN_CENTER, Y_SCREEN_CENTER - (p2.y >> FIXED_BITS), color);
}