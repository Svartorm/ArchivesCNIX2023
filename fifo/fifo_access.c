#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "fifo.h"

/*
    • The case where the pointer to the queue is NULL will not be tested.
    • If malloc fails: the function must not behave as expected
        (e.g. no modification like size increase). If the function
        should have returned a pointer, NULL must be returned instead.
    • Note that the type in the fifo structure is size_t. This type can be
        found in the stddef.h header file
*/

struct fifo *fifo_init(void)
{
    struct fifo *fifox = malloc(sizeof(struct fifo));
    fifox->head = NULL;
    fifox->tail = NULL;
    fifox->size = 0;

    return fifox;
}

size_t fifo_size(struct fifo *fifox)
{
    return fifox->size;
}

void fifo_push(struct fifo *fifox, int elt)
{
    // Create new element
    struct list *new = malloc(sizeof(struct list));
    if (!new)
        return;
    new->data = elt;
    new->next = NULL;

    // Add it to the end of the queue
    if (fifox->tail)
        fifox->tail->next = new;
    fifox->tail = new;
    fifox->size++;

    // If the queue was empty before move the head to the new element
    if (!fifox->head)
        fifox->head = fifox->tail;
}

int fifo_head(struct fifo *fifox)
{
    return fifox->head->data;
}

void fifo_pop(struct fifo *fifox)
{
    // If the queue is empty, do nothing
    if (!fifox->head)
        return;

    // Remove the head and adjust the queue
    struct list *trash = fifox->head;

    fifox->head = fifox->head->next;
    fifox->size--;

    // Free the trash left
    free(trash);
}
