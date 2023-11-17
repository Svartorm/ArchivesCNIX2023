#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "heap.h"

void swap(int *uwu, int *owo)
{
    int qwq = *uwu;
    *uwu = *owo;
    *owo = qwq;
}

void heapify(struct heap *heap, size_t root)
{
    size_t max = root;
    size_t left = 2 * root + 1;
    size_t right = 2 * root + 2;

    // Find max inbetween root, left child and right child
    if (left < heap->size && heap->array[left] > heap->array[max])
        max = left;
    if (right < heap->size && heap->array[right] > heap->array[max])
        max = right;

    if (max != root)
    {
        // We need to swap the value to maintain the heap rules
        swap(&heap->array[root], &heap->array[max]);
        root = max;

        // We do the same for the (now) children
        heapify(heap, root);
    }
}

int pop(struct heap *heap)
{
    assert(heap->size > 0);

    // Get the value of the element to remove
    int res = heap->array[0];

    // Replace root with the last element of the heap
    // If there is only one element left put zero instead
    heap->array[0] = heap->size == 1 ? 0 : heap->array[heap->size - 1];

    // We delete the last element of our heap
    heap->size--;

    // Check if we have to adjust our heap size
    if (heap->capacity > heap->size * 2 && heap->capacity > 8)
    {
        int *tmp = realloc(heap->array, sizeof(int) * (heap->capacity / 2));
        assert(tmp);
        heap->array = tmp;
        heap->capacity /= 2;
    }

    // We heapify our heap to be sure it stays legit
    heapify(heap, 0);

    return res;
}
