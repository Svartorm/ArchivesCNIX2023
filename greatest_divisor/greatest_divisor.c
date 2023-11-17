#include <stdio.h>

unsigned int greatest_divisor(unsigned int n)
{
    unsigned int great = 1;

    for (unsigned int i = 2; i < n; i++)
        if (n % i == 0)
            great = i;

    return great;
}
