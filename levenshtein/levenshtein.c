#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int min(int a, int b, int c)
{
    return a < b ? a < c ? a : c : b < c ? b : c;
}

size_t lenght(const char *s)
{
    size_t len = 0;
    while (*s++)
        len++;
    return len;
}

size_t levenshtein(const char *s1, const char *s2)
{
    size_t s1len = lenght(s1);
    size_t s2len = lenght(s2);

    // Init mat
    size_t **mat = malloc((s1len + 1) * sizeof(size_t *));
    for (size_t i = 0; i <= s1len; i++)
        mat[i] = malloc((s2len + 1) * sizeof(size_t));

    // Fill s1 index
    for (size_t i = 0; i <= s1len; i++)
        mat[i][0] = i;

    // Fill s2 indec
    for (size_t u = 0; u <= s2len; u++)
        mat[0][u] = u;

    size_t subcost;
    for (size_t i = 1; i <= s1len; i++)
    {
        for (size_t u = 1; u <= s2len; u++)
        {
            subcost = s1[i - 1] == s2[u - 1] ? 0 : 1;
            size_t del = mat[(i - 1)][u] + 1;
            size_t ins = mat[i][(u - 1)] + 1;
            size_t sub = mat[(i - 1)][(u - 1)] + subcost;

            mat[i][u] = min(del, ins, sub);
        }
    }

    // DEBUG : Print mat
    /*
    for (size_t i = 0; i <= s1len; i++)
    {
        for ( size_t u = 0; u <= s2len; u ++)
            printf("%zu | ", mat[i][u]);
        printf("\n");
    }*/

    size_t res = mat[s1len][s2len];
    for (size_t i = 0; i <= s1len; i++)
        free(mat[i]);
    free(mat);

    return res;
}

/*
int main(void)
{
    printf("%zu\n", levenshtein("doom", "tools"));
    return 0;
}
*/
