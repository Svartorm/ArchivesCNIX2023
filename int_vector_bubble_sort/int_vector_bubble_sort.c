#include "int_vector_bubble_sort.h"

#include <stddef.h>
#include <stdio.h>

static struct int_vector swap(struct int_vector vec, size_t i, size_t j)
{
    int qwq = vec.data[i];
    vec.data[i] = vec.data[j];
    vec.data[j] = qwq;

    return vec;
}

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

struct int_vector int_vector_bubble_sort(struct int_vector vec)
{
    bubble_sort(vec.data, vec.size);

    struct int_vector lol = { .size = 5, .data = { 6, 7, 12, 2, 8 } };

    lol = swap(lol, 0, 1);

    return vec;
}
