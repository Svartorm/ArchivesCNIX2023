#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "dlist.h"

int dlist_add_sort(struct dlist *list, int element)
{
    if (!list || element < 0)
        return -1;

    // Case first element
    if (list->size == 0 || list->head->data > element)
    {
        int ins = dlist_push_front(list, element);

        if (ins == 0)
            return -1;
        return 1;
    }

    struct dlist_item *pat = list->head;
    for (size_t i = 0; i < list->size; i++)
    {
        if (pat->data > element)
        {
            int ins = dlist_insert_at(list, element, i);

            return ins;
        }

        pat = pat->next;
    }

    int ins = dlist_push_back(list, element);

    if (ins == 0)
        return -1;
    return 1;
}

void dlist_sort(struct dlist *list)
{
    if (!list || list->size == 0)
        return;

    int *buffer = malloc(sizeof(int) * list->size);
    size_t len = list->size;

    for (size_t i = 0; i < list->size; i++)
        buffer[i] = dlist_get(list, i);

    dlist_clear(list);

    for (size_t i = 0; i < len; i++)
        dlist_add_sort(list, buffer[i]);

    free(buffer);
}
