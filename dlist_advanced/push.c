#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "dlist.h"

struct dlist *dlist_init(void)
{
    struct dlist *list = malloc(sizeof(struct dlist));
    if (!list)
        return NULL;

    list->size = 0;
    list->head = NULL;
    list->tail = NULL;

    return list;
}

int dlist_push_front(struct dlist *list, int element)
{
    if (element < 0)
        return 0;

    // Create new element
    struct dlist_item *new = malloc(sizeof(struct dlist_item));
    if (!new)
        return 0;

    new->data = element;

    // Add it to the front of the list
    new->prev = NULL;
    new->next = list->head;
    if (list->head)
        list->head->prev = new;
    list->head = new;
    list->size++;

    // Update tail is the list was empty
    if (!list->tail)
        list->tail = new;

    return 1;
}

void dlist_print(const struct dlist *list)
{
    // Pat goes from head to tail (UwU)
    struct dlist_item *pat = list->head;
    while (pat)
    {
        printf("%i\n", pat->data);
        pat = pat->next;
    }
}

int dlist_push_back(struct dlist *list, int element)
{
    if (element < 0)
        return 0;

    // Create new element
    struct dlist_item *new = malloc(sizeof(struct dlist_item));
    if (!new)
        return 0;

    new->data = element;

    // Add it to the back of the list

    // If list is empty
    if (!list->tail)
    {
        new->next = NULL;
        new->prev = NULL;
        list->head = new;
        list->tail = new;

        list->size++;

        return 1;
    }
    // if there is at least 1 element in list
    list->tail->next = new;
    new->prev = list->tail;
    list->tail = new;
    list->tail->next = NULL;

    list->size++;

    return 1;
}

size_t dlist_size(const struct dlist *list)
{
    return list->size;
}
