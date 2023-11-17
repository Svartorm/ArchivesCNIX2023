#include <stdio.h>

double process(int n, int i)
{
    if (n <= 0)
        return 1;
    double uwu = process(n - 1, i + 1);
    return 1.0 + i / (i * 2.0 + 1.0) * uwu;
}

double pi_generator(int precision)
{
    return 2 * process(precision, 1);
}

/*
int main(void)
{
    printf("%f\n", pi_generator(100));
    return 0;
}
*/

// 1 + i / (i * 2 + 1)
