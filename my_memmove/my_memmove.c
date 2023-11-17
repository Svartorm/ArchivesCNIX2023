#include <errno.h>
#include <stddef.h>

void *my_memmove(void *dest, const void *src, size_t n)
{
    if (!dest || !src)
        return NULL;

    char *owo = dest;
    const char *uwu = src;

    if (owo == uwu)
    {
        return dest;
    }

    if (owo < uwu)
    {
        for (size_t i = 0; i < n; i++)
        {
            owo[i] = uwu[i];
        }

        return dest;
    }

    for (size_t i = n; i > 0; i--)
    {
        owo[i - 1] = uwu[i - 1];
    }
    return dest;
}
