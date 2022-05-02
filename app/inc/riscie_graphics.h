#pragma once

#include "riscie.h"
#include "riscie_math.h"

#define FRAC_BITS 5
#define X_SCREEN_CENTER 160
#define Y_SCREEN_CENTER 120

typedef struct{
    int x, y, z;
} Point;

typedef struct{
    int x, y, z, w;
} vec4;

typedef int Matrix_3x1[3][1];
typedef int Matrix_3x3[3][3];

typedef int Matrix_4x1[4][1];
typedef int Matrix_4x4[4][4];

typedef int Fixed;
#define FIXED_BITS 5
#define INT2FIXED(x) ((x) << FIXED_BITS)

void set_pixel(int x, int y, uint8_t color);
void draw_line_dda(int x1, int y1, int x2, int y2, uint8_t color);
void draw_circle_mp(int x, int y, int radius, uint8_t color);

void draw_point(Point p, uint8_t color);
void draw_line(Point p1, Point p2, uint8_t color);

void *matrix_multiply_3x1(Matrix_3x1 *out, Matrix_3x3 *m1, Matrix_3x1 *m2);
void draw_object_2D(Point *vertices, int verices_size, Matrix_3x3 *matrix, uint8_t color);
void draw_object_3D(vec4 *vertices, int verices_size, Matrix_4x4 *matrix, uint8_t color);