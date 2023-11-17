#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void *my_calloc(size_t n, size_t size)
{
    char *uwu = malloc(n * size);

    if (uwu)
    {
        for (size_t i = 0; i < n * size; i++)
            *(uwu + i) = 0;
    }

    return uwu;
}
