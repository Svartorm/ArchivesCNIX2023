#include "insertion_sort.h"

#include <stdio.h>

void insertion_sort(void **array, f_cmp comp)
{
    int len = 0;
    while (*(array + len))
        len++;

    for (int i = 1; i < len; i++)
    {
        void *uwu = *(array + i);
        int u = i - 1;
        void *owo = *(array + u);
        while (comp(uwu, owo) > 0 && u >= 0)
        {
            *(array + u + 1) = owo;
            --u;
        }
        *(array + u + 1) = uwu;
    }
}
