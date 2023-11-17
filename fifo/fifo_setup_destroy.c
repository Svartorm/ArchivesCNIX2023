#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "fifo.h"

void fifo_clear(struct fifo *fifox)
{
    while (fifox->head)
        fifo_pop(fifox);
}

void fifo_destroy(struct fifo *fifox)
{
    fifo_clear(fifox);
    free(fifox);
}

void fifo_print(const struct fifo *fifox)
{
    for (struct list *pat = fifox->head; pat; pat = pat->next)
    {
        printf("%i\n", pat->data);
    }
}
