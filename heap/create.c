#include <stdio.h>
#include <stdlib.h>

#include "heap.h"

struct heap *create_heap(void)
{
    struct heap *uwu = malloc(sizeof(struct heap));
    if (!uwu)
        return NULL;

    uwu->size = 0;
    uwu->array = calloc(8, sizeof(int));
    if (!uwu->array)
    {
        free(uwu);
        return NULL;
    }
    uwu->capacity = 8;

    return uwu;
}
