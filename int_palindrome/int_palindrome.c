#include <stdio.h>

int int_palindrome(int n)
{
    int uwu = n;
    int owo = 0;
    int r;

    while (n != 0)
    {
        r = n % 10;
        owo = owo * 10 + r;
        n /= 10;
    }

    if (uwu == owo)
        return 1;
    return 0;
}
