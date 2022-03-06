#include "riscie.h"
#include "basic_print.h"
#include "graphics.h"
#include "math.h"

int main(void)
{

    int x_center = 160;
    int y_center = 120;

    draw_line_DDA(x_center, y_center, x_center + 100, y_center, 0xFF);
    draw_line_DDA(x_center, y_center, x_center + 100, y_center + 100, 0xFF);
    draw_line_DDA(x_center, y_center, x_center + 100, y_center - 100, 0xFF);

    draw_line_DDA(x_center, y_center, x_center - 100, y_center, 0xFF);
    draw_line_DDA(x_center, y_center, x_center - 100, y_center - 100, 0xFF);
    draw_line_DDA(x_center, y_center, x_center - 100, y_center + 100, 0xFF);

    draw_line_DDA(x_center, y_center, x_center, y_center + 100, 0xFF);
    draw_line_DDA(x_center, y_center, x_center, y_center - 100, 0xFF);

    draw_circle_MP(x_center, y_center, 100, 0xFF);

    while (1)
    {
    }
}
