#include "int_vector_insert_sort.h"

#include <stddef.h>
#include <stdio.h>

struct int_vector int_vector_insert_sort(struct int_vector vec)
{
    for (size_t i = 1; i < vec.size; i++)
    {
        int uwu = vec.data[i];

        int u = i - 1;
        while (uwu < vec.data[u] && u >= 0)
        {
            vec.data[u + 1] = vec.data[u];
            --u;
        }
        vec.data[u + 1] = uwu;
    }

    return vec;
}
