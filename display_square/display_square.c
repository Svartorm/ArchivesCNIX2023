#include <stdio.h>

void display_square(int width)
{
    if (width <= 0)
        return;

    if (width % 2 == 0)
        width++;

    int height = (width + 1) / 2;
    for (int h = 0; h < height; h++)
    {
        if (h == 0 || h == height - 1)
            for (int w = 0; w < width; w++)
                putchar('*');
        else
            for (int w = 0; w < width; w++)
            {
                if (w == 0 || w == width - 1)
                    putchar('*');
                else
                    putchar(' ');
            }
        putchar('\n');
    }
}
/*
int main(void)
{
    display_square(6);
    display_square(11);
    return 0;
}
*/
