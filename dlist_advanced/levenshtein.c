#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "dlist.h"

int min(int a, int b, int c)
{
    return a < b ? a < c ? a : c : b < c ? b : c;
}

unsigned int dlist_levenshtein(struct dlist *list1, struct dlist *list2)
{
    size_t l1len = list1->size;
    size_t l2len = list2->size;

    // Init mat
    size_t **mat = malloc((l1len + 1) * sizeof(size_t *));
    for (size_t i = 0; i <= l1len; i++)
        mat[i] = malloc((l2len + 1) * sizeof(size_t));

    // Fill s1 index
    for (size_t i = 0; i <= l1len; i++)
        mat[i][0] = i;

    // Fill s2 indec
    for (size_t u = 0; u <= l2len; u++)
        mat[0][u] = u;

    size_t subcost;
    for (size_t i = 1; i <= l1len; i++)
    {
        for (size_t u = 1; u <= l2len; u++)
        {
            subcost =
                dlist_get(list1, i - 1) == dlist_get(list2, u - 1) ? 0 : 1;
            size_t del = mat[(i - 1)][u] + 1;
            size_t ins = mat[i][(u - 1)] + 1;
            size_t sub = mat[(i - 1)][(u - 1)] + subcost;

            mat[i][u] = min(del, ins, sub);
        }
    }

    size_t res = mat[l1len][l2len];
    for (size_t i = 0; i <= l1len; i++)
        free(mat[i]);
    free(mat);

    return res;
}
