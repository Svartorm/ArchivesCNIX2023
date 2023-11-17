#include <stdio.h>

void init(unsigned char *lights)
{
    for (int i = 0; i < 4; i++)
        *lights &= ~(1 << i);
}

void turn_on(unsigned char *lights, unsigned char light_num)
{
    *lights |= 1 << (light_num - 1);
}

void turn_off(unsigned char *lights, unsigned char light_num)
{
    *lights &= ~(1 << (light_num - 1));
}

void next_step(unsigned char *lights)
{
    // Get the leftmost bit
    unsigned leftmost = *lights & (1 << 3);
    // Shift by 1
    *lights <<= 1;
    // Set the first bit=4
    *lights |= (leftmost >> 3);
}

void reverse(unsigned char *lights)
{
    *lights = ~*lights;
}

void swap(unsigned char *lights_1, unsigned char *lights_2)
{
    unsigned char tmp = *lights_1;
    *lights_1 = *lights_2;
    *lights_2 = tmp;
}
