#include "my_strlen.h"

size_t my_strlen(const char *s)
{
    size_t len = 0;

    for (; *s != 0; s++)
        len++;

    return len;
}
