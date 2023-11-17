#include <stdio.h>

char *my_strcpy(char *dest, const char *source)
{
    int i = 0;
    while (*(source + i) != 0)
    {
        *(dest + i) = *(source + i);
        i++;
    }
    dest[i] = 0;

    return dest;
}
