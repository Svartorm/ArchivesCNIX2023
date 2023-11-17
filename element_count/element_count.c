#include <stddef.h>
#include <stdio.h>

size_t element_count(int *begin, int *end)
{
    int *head = begin;
    size_t uwu = 0;
    while (head++ != end)
        uwu++;
    return uwu;
}
