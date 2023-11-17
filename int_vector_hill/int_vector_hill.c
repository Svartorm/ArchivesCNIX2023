#include "int_vector_hill.h"

#include <stdio.h>

size_t get_top(int tab[], size_t len)
{
    size_t mini = 0;
    for (size_t i = 0; i < len; i++)
        if (tab[i] > tab[mini])
            mini = i;
    return mini;
}

int top_of_the_hill(int tab[], size_t len)
{
    if (len == 0)
        return -1;

    size_t owo = get_top(tab, len);
    int top = tab[owo];
    size_t i = 0;

    for (; i < owo; i++)
        if (tab[i] > tab[i + 1] || tab[i] < 0 || tab[i + 1] < 0)
            return -1;

    while (tab[i] == top)
        i++;

    for (; i < len - 1; i++)
        if (tab[i] < tab[i + 1] || tab[i] < 0 || tab[i + 1] < 0)
            return -1;

    return owo;
}

int int_vector_hill(struct int_vector vec)
{
    return top_of_the_hill(vec.data, vec.size);
}
