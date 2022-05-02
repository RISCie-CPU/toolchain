#include <stdio.h>
#include <stdlib.h>

#include "riscie.h"
#include "basic_print.h"
#include "riscie_graphics.h"
#include "riscie_math.h"

int SIN_TABLE[36] = {0b000000, 0b000100, 0b001010, 0b010000, 0b010100, 0b011000, 0b011010, 0b011110, 0b011110, 0b100000, 0b011110, 0b011110, 0b011010, 0b011000, 0b010100, 0b010000, 0b001010, 0b000100, 0b000000, -0b000100, -0b001010, -0b010000, -0b010100, -0b011000, -0b011010, -0b011110, -0b011110, -0b100000, -0b011110, -0b011110, -0b011010, -0b011000, -0b010100, -0b010000, -0b001010, -0b000100};
int COS_TABLE[36] = {0b100000, 0b011110, 0b011110, 0b011010, 0b011000, 0b010100, 0b010000, 0b001010, 0b000100, 0b000000, -0b000100, -0b001010, -0b010000, -0b010100, -0b011000, -0b011010, -0b011110, -0b011110, -0b100000, -0b011110, -0b011110, -0b011010, -0b011000, -0b010100, -0b010000, -0b001010, -0b000100, 0b000000, 0b000100, 0b001010, 0b010000, 0b010100, 0b011000, 0b011010, 0b011110, 0b011110};

// int SIN_TABLE[36] = {0b000000000, 0b000101100, 0b001010110, 0b010000000, 0b010100100, 0b011000100, 0b011011100, 0b011110000, 0b011111100, 0b100000000, 0b011111100, 0b011110000, 0b011011100, 0b011000100, 0b010100100, 0b010000000, 0b001010110, 0b000101100, 0b000000000, -0b000101100, -0b001010110, -0b010000000, -0b010100100, -0b011000100, -0b011011100, -0b011110000, -0b011111100, -0b100000000, -0b011111100, -0b011110000, -0b011011100, -0b011000100, -0b010100100, -0b010000000, -0b001010110, -0b000101100};
// int COS_TABLE[36] = {0b100000000, 0b011111100, 0b011110000, 0b011011100, 0b011000100, 0b010100100, 0b010000000, 0b001010110, 0b000101100, 0b000000000, -0b000101100, -0b001010110, -0b010000000, -0b010100100, -0b011000100, -0b011011100, -0b011110000, -0b011111100, -0b100000000, -0b011111100, -0b011110000, -0b011011100, -0b011000100, -0b010100100, -0b010000000, -0b001010110, -0b000101100, 0b000000000, 0b000101100, 0b001010110, 0b010000000, 0b010100100, 0b011000100, 0b011011100, 0b011110000, 0b011111100};

// A=(-50,0) B=(100,0) C=(-50,100)
// Point triangle_vertex[] = {{INT2FIXED(50), INT2FIXED(-50), INT2FIXED(1)}, {INT2FIXED(50), INT2FIXED(50), INT2FIXED(1)}, {INT2FIXED(-50), INT2FIXED(50), INT2FIXED(1)}, {INT2FIXED(-50), INT2FIXED(-50), INT2FIXED(1)}, {INT2FIXED(50), INT2FIXED(-50), INT2FIXED(1)}, {INT2FIXED(25), INT2FIXED(-90), INT2FIXED(1)}, {INT2FIXED(-50), INT2FIXED(-50), INT2FIXED(1)}};

int main(void)
{
    // while (1)
    // {
    //     for (int x = 0; x < 36; x++)
    //     {

    //         Matrix_3x3 MATRIX_NORMALX = {{COS_TABLE[x], -SIN_TABLE[x], INT2FIXED(0)},
    //                                      {SIN_TABLE[x], COS_TABLE[x], INT2FIXED(0)},
    //                                      {INT2FIXED(0), INT2FIXED(0), INT2FIXED(1)}};

    //         int vertex_len = sizeof(triangle_vertex) / sizeof(triangle_vertex[0]);
    //         draw_object_2D(triangle_vertex, vertex_len, &MATRIX_NORMALX, 255);
    //         draw_object_2D(triangle_vertex, vertex_len, &MATRIX_NORMALX, 0);
    //     }
    // }

    // Matrix_4x4 MATRIX_NORMAL4 = {{INT2FIXED(1), INT2FIXED(0), INT2FIXED(0), INT2FIXED(0)},
    //                              {INT2FIXED(0), INT2FIXED(1), INT2FIXED(0), INT2FIXED(0)},
    //                              {INT2FIXED(0), INT2FIXED(0), INT2FIXED(1), INT2FIXED(0)},
    //                              {INT2FIXED(0), INT2FIXED(0), INT2FIXED(0), INT2FIXED(1)}};

    for (int i = 0; i < 36; i++)
    {
        Matrix_4x4 MATRIX_NORMAL4 = {{COS_TABLE[i], INT2FIXED(0), -SIN_TABLE[i], INT2FIXED(0)},
                                    {INT2FIXED(0), COS_TABLE[i], -SIN_TABLE[i], INT2FIXED(0)},
                                    {SIN_TABLE[i], SIN_TABLE[i], COS_TABLE[i], INT2FIXED(0)},
                                    {INT2FIXED(0), INT2FIXED(0), INT2FIXED(0), INT2FIXED(1)}};

        vec4 cube[] =  {{INT2FIXED(-50), INT2FIXED(50), INT2FIXED(50), INT2FIXED(1)},
                        {INT2FIXED(50), INT2FIXED(50), INT2FIXED(50), INT2FIXED(1)},
                        {INT2FIXED(50), INT2FIXED(-50), INT2FIXED(50), INT2FIXED(1)},
                        {INT2FIXED(-50), INT2FIXED(-50), INT2FIXED(50), INT2FIXED(1)},
                        {INT2FIXED(-50), INT2FIXED(50), INT2FIXED(50), INT2FIXED(1)},
                        {INT2FIXED(-50), INT2FIXED(50), INT2FIXED(-50), INT2FIXED(1)},
                        {INT2FIXED(50), INT2FIXED(50), INT2FIXED(-50), INT2FIXED(1)},
                        {INT2FIXED(50), INT2FIXED(50), INT2FIXED(50), INT2FIXED(1)},
                        {INT2FIXED(50), INT2FIXED(50), INT2FIXED(-50), INT2FIXED(1)},
                        {INT2FIXED(50), INT2FIXED(-50), INT2FIXED(-50), INT2FIXED(1)},
                        {INT2FIXED(50), INT2FIXED(-50), INT2FIXED(50), INT2FIXED(1)},
                        {INT2FIXED(50), INT2FIXED(-50), INT2FIXED(-50), INT2FIXED(1)},
                        {INT2FIXED(-50), INT2FIXED(-50), INT2FIXED(-50), INT2FIXED(1)},
                        {INT2FIXED(-50), INT2FIXED(-50), INT2FIXED(50), INT2FIXED(1)},
                        {INT2FIXED(-50), INT2FIXED(-50), INT2FIXED(-50), INT2FIXED(1)},
                        {INT2FIXED(-50), INT2FIXED(50), INT2FIXED(-50), INT2FIXED(1)}};

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