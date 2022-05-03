#include <stdio.h>
#include <stdlib.h>


#include "riscie.h"
#include "basic_print.h"
#include "riscie_graphics.h"
#include "riscie_math.h"

int SIN_TABLE[36] = {0b000000, 0b000100, 0b001010, 0b010000, 0b010100, 0b011000, 0b011010, 0b011110, 0b011110, 0b100000, 0b011110, 0b011110, 0b011010, 0b011000, 0b010100, 0b010000, 0b001010, 0b000100, 0b000000, -0b000100, -0b001010, -0b010000, -0b010100, -0b011000, -0b011010, -0b011110, -0b011110, -0b100000, -0b011110, -0b011110, -0b011010, -0b011000, -0b010100, -0b010000, -0b001010, -0b000100};
int COS_TABLE[36] = {0b100000, 0b011110, 0b011110, 0b011010, 0b011000, 0b010100, 0b010000, 0b001010, 0b000100, 0b000000, -0b000100, -0b001010, -0b010000, -0b010100, -0b011000, -0b011010, -0b011110, -0b011110, -0b100000, -0b011110, -0b011110, -0b011010, -0b011000, -0b010100, -0b010000, -0b001010, -0b000100, 0b000000, 0b000100, 0b001010, 0b010000, 0b010100, 0b011000, 0b011010, 0b011110, 0b011110};

int main(void)
{
    for (int i = 0; i < 36; i++)
    {
        Matrix_4x4 ROT_Y = {{COS_TABLE[i], INT2FIXED(0), -SIN_TABLE[i], INT2FIXED(0)},
                            {INT2FIXED(0), INT2FIXED(1),  INT2FIXED(0), INT2FIXED(0)},
                            {SIN_TABLE[i], INT2FIXED(0),  COS_TABLE[i], INT2FIXED(0)},
                            {INT2FIXED(0), INT2FIXED(0),  INT2FIXED(0), INT2FIXED(1)}};

        Matrix_4x4 ROT_X = {{INT2FIXED(1), INT2FIXED(0),  INT2FIXED(0), INT2FIXED(0)},
                            {INT2FIXED(0), COS_TABLE[i], -SIN_TABLE[i], INT2FIXED(0)},
                            {INT2FIXED(0), SIN_TABLE[i],  COS_TABLE[i], INT2FIXED(0)},
                            {INT2FIXED(0), INT2FIXED(0),  INT2FIXED(0), INT2FIXED(1)}};

        Matrix_4x4 MATRIX_NORMAL4;
        matrix_multiply_4x4(&MATRIX_NORMAL4, &ROT_Y, &ROT_X);

        vec4 cube[] =  {{INT2FIXED(-50),INT2FIXED( 50), INT2FIXED( 50), INT2FIXED(1)},
                        {INT2FIXED( 50),INT2FIXED( 50), INT2FIXED( 50), INT2FIXED(1)},
                        {INT2FIXED( 50),INT2FIXED(-50), INT2FIXED( 50), INT2FIXED(1)},
                        {INT2FIXED(-50),INT2FIXED(-50), INT2FIXED( 50), INT2FIXED(1)},
                        {INT2FIXED(-50),INT2FIXED( 50), INT2FIXED( 50), INT2FIXED(1)},
                        {INT2FIXED(-50),INT2FIXED( 50), INT2FIXED(-50), INT2FIXED(1)},
                        {INT2FIXED( 50),INT2FIXED( 50), INT2FIXED(-50), INT2FIXED(1)},
                        {INT2FIXED( 50),INT2FIXED( 50), INT2FIXED( 50), INT2FIXED(1)},
                        {INT2FIXED( 50),INT2FIXED( 50), INT2FIXED(-50), INT2FIXED(1)},
                        {INT2FIXED( 50),INT2FIXED(-50), INT2FIXED(-50), INT2FIXED(1)},
                        {INT2FIXED( 50),INT2FIXED(-50), INT2FIXED( 50), INT2FIXED(1)},
                        {INT2FIXED( 50),INT2FIXED(-50), INT2FIXED(-50), INT2FIXED(1)},
                        {INT2FIXED(-50),INT2FIXED(-50), INT2FIXED(-50), INT2FIXED(1)},
                        {INT2FIXED(-50),INT2FIXED(-50), INT2FIXED( 50), INT2FIXED(1)},
                        {INT2FIXED(-50),INT2FIXED(-50), INT2FIXED(-50), INT2FIXED(1)},
                        {INT2FIXED(-50),INT2FIXED( 50), INT2FIXED(-50), INT2FIXED(1)}};

        int vertex_len = sizeof(cube) / sizeof(cube[0]);
        draw_object_3D(cube, vertex_len, &MATRIX_NORMAL4, 255);

        int delay;
        for (int d = 0; d < 500000; d++)
        {
            delay++;
        }
        
        draw_object_3D(cube, vertex_len, &MATRIX_NORMAL4, 0);
    }
}