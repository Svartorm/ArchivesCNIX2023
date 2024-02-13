#include <stddef.h>

void *my_memset(void *s, int c, size_t n)
{
    unsigned char *p = s;
    unsigned char uc = c;

    while (n-- > 0)
        *p++ = uc;

    return s;
}
