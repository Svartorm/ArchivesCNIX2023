#include <stdio.h>

void my_strlowcase(char *str)
{
    for (int i = 0; str[i] != 0; i++)
    {
        char c = str[i];
        if ('A' <= c && c <= 'Z')
        {
            str[i] += 32;
        }
    }
}
