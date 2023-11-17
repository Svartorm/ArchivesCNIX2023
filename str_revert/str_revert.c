#include "str_revert.h"

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
