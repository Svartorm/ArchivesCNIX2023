#include "insertion_sort.h"

#include <stdio.h>

void insertion_sort(void **array, f_cmp comp)
{
    int len = 0;
    while (array[len] != NULL)
        len++;

    for (int i = 1; i < len; i++)
    {
        void *uwu = array[i];
        int u = i - 1;
        while (u >= 0 && comp(array[u], uwu) > 0)
        {
            array[u + 1] = array[u];
            u--;
        }
        array[u + 1] = uwu;
    }
}
