#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "dlist.h"

int dlist_get(const struct dlist *list, size_t index)
{
    // Check if element exist
    if (index >= list->size)
        return -1;

    // Go to the element
    struct dlist_item *pat = list->head;
    for (size_t i = 0; i < index; i++)
        pat = pat->next;

    // Return its value
    return pat->data;
}

int dlist_insert_at(struct dlist *list, int element, size_t index)
{
    // Check if index is within bound. index included
    if (index > list->size || element < 0)
        return -1;

    // If index = 0, we just push front
    if (index == 0)
    {
        if (dlist_push_front(list, element) == 0)
            return -1;
        return 1;
    }

    // If index = size, we just push back our element
    if (index == list->size)
    {
        if (dlist_push_back(list, element) == 0)
            return -1;
        return 1;
    }

    // Go to the index
    struct dlist_item *pat = list->head;
    for (size_t i = 0; i < index; i++)
        pat = pat->next;

    // Create new element
    struct dlist_item *new = malloc(sizeof(struct dlist_item));
    if (!new)
        return -1;

    new->data = element;

    // Insert new element in the list
    // pat HAS a prev and next != NULL
    struct dlist_item *prepat = pat->prev;

    prepat->next = new;
    new->prev = prepat;

    pat->prev = new;
    new->next = pat;

    list->size++;

    return 1;
}

int dlist_find(const struct dlist *list, int element)
{
    // We go throught our list
    struct dlist_item *pat = list->head;
    for (size_t i = 0; i < list->size; i++)
    {
        // If we found our element
        if (pat->data == element)
            return i;

        // Else go to next node
        pat = pat->next;
    }

    return -1;
}

int dlist_remove_at(struct dlist *list, size_t index)
{
    // Check if index is within bound. index not included
    if (index >= list->size)
        return -1;

    // Go to the index
    struct dlist_item *pat = list->head;
    for (size_t i = 0; i < index; i++)
        pat = pat->next;

    // Delete pat
    struct dlist_item *prepat = pat->prev;
    struct dlist_item *postpat = pat->next;

    if (prepat)
        prepat->next = postpat;
    else // We try to remove the head
        list->head = postpat;

    if (postpat)
        postpat->prev = prepat;
    else // We try to remove the tail
        list->tail = prepat;

    list->size--;

    // Free pat
    int val = pat->data;
    free(pat);

    return val;
}

void dlist_clear(struct dlist *list)
{
    // Free every element
    struct dlist_item *pat;
    while (list->tail != list->head)
    {
        pat = list->tail;
        list->tail = list->tail->prev;
        free(pat);
    }

    free(list->tail);

    // Reset the list
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
}
