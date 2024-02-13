#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "dlist.h"

void dlist_map_square(struct dlist *list)
{
    if (!list->head)
        return;

    struct dlist_item *pat = list->head;
    for (size_t i = 0; i < list->size; i++)
    {
        pat->data *= pat->data;
        pat = pat->next;
    }
}

void dlist_reverse(struct dlist *list)
{
    // Check list is not empty
    if (!list->head)
        return;

    // Set head to tail
    list->head = list->tail;

    // Swap every node
    while (list->tail->prev)
    {
        void *tmp = list->tail->prev;
        list->tail->prev = list->tail->next;
        list->tail->next = tmp;

        // Go next node
        list->tail = list->tail->next;
    }

    // Handle the tail
    list->tail->prev = list->tail->next;
    list->tail->next = NULL;
}

struct dlist *dlist_split_at(struct dlist *list, size_t index)
{
    if (index >= list->size)
        return NULL;

    // init second list
    struct dlist *second = dlist_init();

    // Empty list connot be split
    if (list->size == 0)
        return second;

    // go to index
    struct dlist_item *pat = list->head;
    for (size_t i = 0; i < index; i++)
        pat = pat->next;

    // Cut the list in two
    struct dlist_item *prepat = pat->prev;

    //      Setup second
    second->head = pat;
    pat->prev = NULL;

    second->tail = list->tail;

    second->size = list->size - index;

    //      Setup list
    list->tail = prepat;
    if (prepat)
        prepat->next = NULL;
    else
        list->head = NULL;

    list->size = index;

    // Return second list
    return second;
}

void dlist_concat(struct dlist *list1, struct dlist *list2)
{
    if (list2->size == 0)
        return;

    if (list1->size == 0)
    {
        list1->head = list2->head;
        list1->tail = list2->tail;
        list1->size += list2->size;
    }
    else
    {
        // Attach the two list
        list1->tail->next = list2->head;
        list2->head->prev = list1->tail;

        // List1 absorb list2
        list1->tail = list2->tail;
        list1->size += list2->size;
    }

    // Reset list2
    list2->size = 0;
    list2->head = NULL;
    list2->tail = NULL;
}
