#include <stddef.h>

void *my_memcpy(void *dest, const void *source, size_t num)
{
    unsigned char *pdest = dest;
    const unsigned char *psource = source;

    while (num-- > 0)
        *pdest++ = *psource++;

    return dest;
}
