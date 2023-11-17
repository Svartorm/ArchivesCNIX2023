#include <stdio.h>

int my_pow(int a, int b)
{
    if (b == 0)
        return 1;

    if (b % 2 == 1)
        return a * my_pow(a, b / 2) * my_pow(a, b / 2);

    return my_pow(a, b / 2) * my_pow(a, b / 2);
}
