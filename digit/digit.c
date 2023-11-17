#include <stdio.h>

unsigned int digit(int n, int k)
{
    if (n <= 0 || k <= 0)
        return 0;

    int digit = 0;

    for (int i = 0; i < k; i++)
    {
        digit = n % 10;
        n /= 10;
    }

    return digit;
}
