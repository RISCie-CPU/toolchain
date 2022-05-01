#include <stdio.h>
#include <stdlib.h>

#include "riscie.h"
#include "basic_print.h"
#include "riscie_graphics.h"
#include "riscie_math.h"

int SIN_TABLE[36] = {0b000000, 0b000100, 0b001010, 0b010000, 0b010100, 0b011000, 0b011010, 0b011110, 0b011110, 0b100000, 0b011110, 0b011110, 0b011010, 0b011000, 0b010100, 0b010000, 0b001010, 0b000100, 0b000000, -0b000100, -0b001010, -0b010000, -0b010100, -0b011000, -0b011010, -0b011110, -0b011110, -0b100000, -0b011110, -0b011110, -0b011010, -0b011000, -0b010100, -0b010000, -0b001010, -0b000100};
int COS_TABLE[36] = {0b100000, 0b011110, 0b011110, 0b011010, 0b011000, 0b010100, 0b010000, 0b001010, 0b000100, 0b000000, -0b000100, -0b001010, -0b010000, -0b010100, -0b011000, -0b011010, -0b011110, -0b011110, -0b100000, -0b011110, -0b011110, -0b011010, -0b011000, -0b010100, -0b010000, -0b001010, -0b000100, 0b000000, 0b000100, 0b001010, 0b010000, 0b010100, 0b011000, 0b011010, 0b011110, 0b011110};

// A=(-50,0) B=(100,0) C=(-50,100)
Point triangle_vertex[] = {{INT2FIXED(0), INT2FIXED(0), INT2FIXED(1)}, {INT2FIXED(100), INT2FIXED(0), INT2FIXED(1)}, {INT2FIXED(0), INT2FIXED(100), INT2FIXED(1)}, {INT2FIXED(0), INT2FIXED(0), INT2FIXED(1)}};

int main(void)
{
    Matrix_3x3 MATRIX_NORMALX = {{1, 0, 0},
                                 {0, 1, 0},
                                 {0, 0, 1}};


    int vertex_len = sizeof(triangle_vertex)/sizeof(triangle_vertex[0]);
    draw_object_2D(triangle_vertex, vertex_len, &MATRIX_NORMALX);

    Matrix_3x3 MY_matrix =      {{1, 0, 0},
                                 {0, 1, 0},
                                 {0, 0, 1}};

    // PROBLEMATIC :
    Matrix_3x1 point_2 = {{INT2FIXED(10)}, {INT2FIXED(10)}, {INT2FIXED(1)}};
    Matrix_3x1 *out_2 = matrix_multiply_3x1(&MY_matrix, &point_2);
    free(out_2);
    
    
    
    // current_point.x = (*out_2)[0][0];
    // current_point.y = (*out_2)[1][0];
    
    // for (int idx = 0; idx < 3; idx++)
    // {
    //     Point current_point = triangle_vertex[idx];
    //     Point next_point = triangle_vertex[idx + 1];
    //     draw_line(current_point, next_point, 255);

    // }



    // for (int z = 0; z < 40; z++)
    // {
    //     for (int i = 0; i < 36; i++)
    //     {

    //         Point p1;
    //         p1.x = INT2FIXED(0);
    //         p1.y = INT2FIXED(0);
    //         p1.z = INT2FIXED(1);

    //         Point p2;
    //         p2.x = INT2FIXED(50);
    //         p2.y = INT2FIXED(0);
    //         p2.z = INT2FIXED(1);

    //         Point p3;
    //         p3.x = INT2FIXED(50);
    //         p3.y = INT2FIXED(50);
    //         p3.z = INT2FIXED(1);

    //         draw_point(p1, 255);

    //         Matrix_3x3 x = {
    //             {COS_TABLE[i], -SIN_TABLE[i], INT2FIXED(20)},
    //             {SIN_TABLE[i], COS_TABLE[i], INT2FIXED(20)},
    //             {INT2FIXED(0), INT2FIXED(0), INT2FIXED(1)}};

    //         Matrix_3x1 point_1 = {{p1.x}, {p1.y}, {p1.z}};
    //         Matrix_3x1 *out_1 = matrix_multiply_3x1(&x, &point_1);
    //         p1.x = (*out_1)[0][0];
    //         p1.y = (*out_1)[1][0];
    //         free(out_1);

    //         Matrix_3x1 point_2 = {{p2.x}, {p2.y}, {p2.z}};
    //         Matrix_3x1 *out_2 = matrix_multiply_3x1(&x, &point_2);
    //         p2.x = (*out_2)[0][0];
    //         p2.y = (*out_2)[1][0];
    //         free(out_2);

    //         Matrix_3x1 point_3 = {{p3.x}, {p3.y}, {p3.z}};
    //         Matrix_3x1 *out_3 = matrix_multiply_3x1(&x, &point_3);
    //         p3.x = (*out_3)[0][0];
    //         p3.y = (*out_3)[1][0];
    //         free(out_3);

    //         draw_line(p1, p2, 0xAf);
    //         draw_line(p2, p3, 0xAf);
    //         draw_line(p3, p1, 0xAf);

    //         for (int x = 0; x < 1000; x++)
    //         {
    //             /* code */
    //         }

    //         draw_line(p1, p2, 0x0);
    //         draw_line(p2, p3, 0x0);
    //         draw_line(p3, p1, 0x0);
    //     }
    // }

    while (1)
        ;
}
