#include "int_vector_vice_max.h"

#include <stddef.h>
#include <stdio.h>

int int_vector_vice_max(const struct int_vector vec)
{
    int max = vec.data[0] > vec.data[1] ? vec.data[0] : vec.data[1];
    int vmax = vec.data[0] > vec.data[1] ? vec.data[1] : vec.data[0];

    for (size_t i = 2; i < vec.size; i++)
    {
        if (vec.data[i] > max)
        {
            vmax = max;
            max = vec.data[i];
        }
        else
        {
            if (vec.data[i] > vmax)
                vmax = vec.data[i];
        }
    }

    return vmax;
}
