#include <stdio.h>

#include "functional_programming.h"

int foldl(int *array, size_t len, int (*func)(int, int))
{
    if (len <= 1)
        return func(0, *array);
    return func(foldl(array, len - 1, func), *(array + len - 1));
}
