#include <stdio.h>

unsigned char rol(unsigned char value, unsigned char roll)
{
    for (int i = 0; i < roll; i++)
    {
        // Get the leftmost bit
        unsigned leftmost = value & (1 << 7);
        // Shift by 1
        value = value << 1;
        // Set the first bit
        value = value | (leftmost >> 7);
    }

    return value;
}
