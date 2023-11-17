#include <stdio.h>

int my_atoi(const char *str)
{
    int i = 0;
    while (str[i] == ' ')
        i++;

    int sign = 1;
    if (str[i] == '-' || str[i] == '+')
    {
        sign = 1 - 2 * (str[i++] == '-');
    }

    int uwu = 0;
    while (*(str + i))
    {
        if (*(str + i) < '0' || *(str + i) > '9')
            return 0;

        uwu = 10 * uwu + (str[i++] - '0');
    }

    return uwu * sign;
}
