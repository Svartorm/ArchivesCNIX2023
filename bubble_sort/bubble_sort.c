#include "bubble_sort.h"

#include <stddef.h>
#include <stdio.h>

void bubble_sort(int *array, size_t size)
{
    if (size == 0)
        return;

    for (size_t i = 0; i < size - 1; ++i)
    {
        for (size_t u = 0; u < size - i - 1; ++u)
        {
            if (array[u] > array[u + 1])
            {
                int uwu = array[u];
                array[u] = array[u + 1];
                array[u + 1] = uwu;
            }
        }
    }
}
