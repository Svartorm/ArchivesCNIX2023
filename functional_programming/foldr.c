#include <stdio.h>

#include "functional_programming.h"

int foldr(int *array, size_t len, int (*func)(int, int))
{
    if (len <= 1)
        return func(*array, 0);
    return func(*array, foldr(array + 1, len - 1, func));
}
