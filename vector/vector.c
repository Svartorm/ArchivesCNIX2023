<<<<<<< Updated upstream
#include <stdio.h>
#include <stdlib.h>
=======
>>>>>>> Stashed changes
#include "vector.h"

#include <stdio.h>

struct vector *vector_init(size_t n)
{
    struct vector *v = calloc(1, sizeof(struct vector));
    if (!v)
        return NULL;

    v->size = 0;
    v->capacity = n;
    v->data = calloc(n, sizeof(int));
    if (!v->data)
    {
        free(v);
        return NULL;
    }

    return v;
}

void vector_destroy(struct vector *v)
{
    if (!v)
        return;

    free(v->data);
    free(v);
}

struct vector *vector_resize(struct vector *v, size_t n)
{
    if (!v)
        return NULL;

    if (n == v->size)
        return v;

    if (n < v->capacity)
    {
        for (size_t i = v->size; i > n; i++)
        {
            v->size--;
            if (v->size < v->capacity / 2)
            {
                int *qwq = realloc(v->data, v->capacity / 2 * sizeof(int));
                if (!qwq)
                    return NULL;

                v->capacity /= 2;
                v->data = qwq;
            }
        }

        v->size = n;

        return v;
    }

    int *qwq = realloc(v->data, v->size * 2 * sizeof(int));
    if (!qwq)
        return NULL;

    v->capacity *= 2;
    v->data = qwq;

    return v;
}

struct vector *vector_append(struct vector *v, int elt)
{
    v = vector_resize(v, v->size + 1);
    if (!v)
        return NULL;

    v->data[v->size - 1] = elt;
    return v;
}

void vector_print(const struct vector *v)
{
    if (!v)
    {
        printf("\n");
        return;
    }

    printf("%i", v->data[0]);
    for (size_t i = 1; i < v->size; i++)
        printf(",%i", v->data[i]);

    printf("\n");
}

struct vector *vector_reset(struct vector *v, size_t n)
{
    if (!v)
        return NULL;

    free(v->data);
    v->size = 0;
    v->capacity = n;
    v->data = calloc(n, sizeof(int));

    if (!v->data)
        return NULL;

    return v;
}

struct vector *vector_insert(struct vector *v, size_t i, int elt)
{
    if (!v || i > v->size)
        return NULL;

    vector_resize(v, v->size + 1);

    for (size_t j = v->size - 1; j > i; j--)
        v->data[j] = v->data[j - 1];

    v->data[i] = elt;

    return v;
}

struct vector *vector_remove(struct vector *v, size_t i)
{
    if (!v || i >= v->size)
        return NULL;

    for (size_t j = i; j < v->size - 1; j++)
        v->data[j] = v->data[j + 1];

    vector_resize(v, v->size - 1);

    return v;
}
