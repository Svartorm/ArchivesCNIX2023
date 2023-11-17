#include "is_set.h"

#include <stdio.h>

unsigned int is_set(unsigned int value, unsigned char n)
{
    return (value & (1 << (n - 1))) >> (n - 1);
}
