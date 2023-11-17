#include <stdio.h>
#include <stdlib.h>

#include "heap.h"

void swap_add(int *uwu, int *owo)
{
    int qwq = *uwu;
    *uwu = *owo;
    *owo = qwq;
}

void heapify_add(struct heap *heap, int i)
{
    // Get parent node
    int p = (i - 1) / 2;

    // if i is greater than its parent, we swap them
    while (heap->array[i] > heap->array[p])
    {
        swap_add(&heap->array[i], &heap->array[p]);
        i = p;
        p = (i - 1) / 2;
    }
}

void add(struct heap *heap, int val)
{
    if (!heap)
        return;

    // Adjust buffer
    if (heap->size + 1 >= heap->capacity)
    {
        void *tmp = realloc(heap->array, heap->capacity * 2 * sizeof(int));
        if (!tmp)
            return;

        heap->array = tmp;
        heap->capacity *= 2;
    }

    // Increase size
    heap->size++;

    // Add new element at the bottom of our heap
    heap->array[heap->size - 1] = val;

    // Heapify our heap to make sure it stays legit
    heapify_add(heap, heap->size - 1);
}
