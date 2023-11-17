#include <stdio.h>

void swap(char *uwu, char *owo)
{
    char qwq = *uwu;
    *uwu = *owo;
    *owo = qwq;
}

void str_revert(char str[])
{
    int len = 0;
    while (str[len] != 0)
        len++;

    int uwu = 0;
    int owo = len - 1;

    for (int i = 0; i < len / 2; i++)
    {
        swap(&str[uwu], &str[owo]);
        uwu++;
        owo--;
    }
}

char *my_itoa(int value, char *s)
{
    if (value == 0)
    {
        *s = '0';
        *(s + 1) = 0;
        return s;
    }

    int i = 0;
    int flag = 0;

    if (value < 0)
    {
        value *= -1;
        flag = 1;
    }

    while (value > 0)
    {
        *(s + i) = value % 10 + '0';
        value /= 10;
        i++;
    }

    if (flag == 1)
    {
        *(s + i) = '-';
        i++;
    }

    *(s + i) = 0;
    str_revert(s);

    return s;
}
