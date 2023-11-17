#include "int_vector_print.h"

#include <stddef.h>
#include <stdio.h>

void int_vector_print(const struct int_vector vec)
{
    printf("%i", vec.data[0]);
    for (size_t i = 1; i < vec.size; i++)
        printf(" %i", vec.data[i]);
    printf("\n");
}
