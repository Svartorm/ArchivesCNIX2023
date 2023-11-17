#include "my_strspn.h"

#include <stddef.h>

size_t my_strspn(const char *s, const char *accept)
{
    unsigned char uwu[32] = { 0 };

    size_t i;

    for (i = 0; accept[i]; ++i)
        uwu[accept[i] >> 3] |= 0x1 << (accept[i] % 8);
    for (i = 0; ((uwu[s[i] >> 3] >> (s[i] % 8)) & 0x1); ++i)
        continue;
    return i;
}
