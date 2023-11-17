#include <stdio.h>

int pine(unsigned n)
{
    if (n < 3)
        return 1;

    // Get max width
    int maxw = 1;
    int trunc_len = n / 2;

    // Print leaves
    int u = n - 1;
    while (u >= 0)
    {
        for (int i = 0; i < u; i++)
            putchar(' ');

        for (int i = 0; i < maxw; i++)
            putchar('*');

        putchar('\n');
        u--;
        maxw += 2;
    }

    // Print trunc
    maxw -= 2;

    while (trunc_len > 0)
    {
        for (int i = 0; i < (maxw / 2); i++)
            putchar(' ');
        putchar('*');
        putchar('\n');
        trunc_len--;
    }

    return 0;
}
