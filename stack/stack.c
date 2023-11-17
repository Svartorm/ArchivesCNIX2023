#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

struct stack *stack_push(struct stack *s, int e)
{
    struct stack *new = malloc(sizeof(struct stack));
    new->data = e;
    new->next = s;

    return new;
}

struct stack *stack_pop(struct stack *s)
{
    if (s == NULL)
        return NULL;

    struct stack *head = s->next;
    free(s);

    return head;
}

int stack_peek(struct stack *s)
{
    return s->data;
}
