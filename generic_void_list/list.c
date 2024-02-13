#include "list.h"

#include <stdlib.h>
#include <string.h>

struct list *list_prepend(struct list *list, const void *value,
                          size_t data_size)
{
    struct list *new = malloc(sizeof(struct list));
    if (new == NULL)
    {
        return NULL;
    }
    new->data = malloc(data_size);
    if (new->data == NULL)
    {
        free(new);
        return NULL;
    }

    memcpy(new->data, value, data_size);
    new->next = list;

    return new;
}

size_t list_length(struct list *list)
{
    size_t len = 0;
    while (list != NULL)
    {
        list = list->next;
        len++;
    }
    return len;
}

void list_destroy(struct list *list)
{
    while (list != NULL)
    {
        struct list *tail = list->next;
        free(list->data);
        free(list);
        list = tail;
    }
}
