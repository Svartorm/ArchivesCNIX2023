#include <stddef.h>
#include <stdio.h>

int my_memcmp(const void *s1, const void *s2, size_t num)
{
    const unsigned char *p1 = s1;
    const unsigned char *p2 = s2;
    int res = 0;
    for (size_t i = 0; i < num && res == 0; i++)
    {
        res = p1[i] - p2[i];
    }
    return res;
}
