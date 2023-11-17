#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "heap.h"

void print_node(const struct heap *heap, int i, int is_right_wing)
{
    // Get children indexes
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;

    // Test if is the very far right node
    if (right >= heap->size && is_right_wing == 1)
    {
        if (left < heap->size)
        {
            printf("%i ", heap->array[i]);
            printf("%i\n", heap->array[left]);
            return;
        }
        printf("%i\n", heap->array[i]);
        return;
    }

    // Print the root
    printf("%i ", heap->array[i]);

    // Test Left child
    if (left < heap->size)
        print_node(heap, left, 0);

    // Test Right child
    if (right < heap->size)
        print_node(heap, right, is_right_wing == 1 ? 1 : 0);
}

void print_heap(const struct heap *heap)
{
    if (!heap)
        return;

    print_node(heap, 0, 1);
}
