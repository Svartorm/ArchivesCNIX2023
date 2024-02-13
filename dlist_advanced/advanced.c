#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "dlist.h"

void dlist_shift(struct dlist *list, int offset)
{
    if (!list || list->size == 0)
        return;

    int left = 0;

    if (offset < 0)
    {
        offset *= -1;
        left = 1;
    }

    for (int i = 0; i < offset; i++)
    {
        if (left == 0)
        {
            int val = dlist_remove_at(list, list->size - 1);
            dlist_push_front(list, val);
        }
        else
        {
            int val = dlist_remove_at(list, 0);
            dlist_push_back(list, val);
        }
    }
}

int dlist_remove_eq(struct dlist *list, int element)
{
    if (!list || list->size == 0)
        return 0;

    struct dlist_item *pat = list->head;
    for (size_t i = 0; i < list->size; i++)
    {
        if (pat->data == element)
        {
            int rm = dlist_remove_at(list, i);
            if (rm == -1)
                return 0;
            return 1;
        }

        pat = pat->next;
    }

    return 0;
}

struct dlist *dlist_copy(const struct dlist *list)
{
    if (!list)
        return NULL;

    struct dlist *copy = dlist_init();
    for (size_t i = 0; i < list->size; i++)
    {
        int val = dlist_get(list, i);

        if (val == -1)
        {
            dlist_clear(copy);
            free(copy);
            return NULL;
        }

        int ins = dlist_insert_at(copy, val, i);
        if (ins == -1)
        {
            dlist_clear(copy);
            free(copy);
            return NULL;
        }
    }

    return copy;
}

void dlist_merge(struct dlist *list1, struct dlist *list2)
{
    if (!list1 || !list2 || list2->size == 0)
        return;

    dlist_concat(list1, list2);

    dlist_sort(list1);
}
