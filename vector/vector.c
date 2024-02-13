#include "vector.h"

#include <stdio.h>
#include <stdlib.h>

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

    if (n == 0)
        return v;

    size_t kapa = v->capacity;

    if (n <= v->capacity)
    {
        if (n < v->size)
            v->size = n;

        // Resize the vector
        while (kapa > n)
            kapa /= 2;

        int *qwq = realloc(v->data, kapa * sizeof(int));
        if (!qwq)
            return NULL;

        v->data = qwq;
        v->capacity = kapa;

        return v;
    }

    while (kapa < n)
        kapa *= 2;

    int *qwq = realloc(v->data, kapa * sizeof(int));
    if (!qwq)
        return NULL;

    v->data = qwq;
    v->capacity = kapa;

    return v;
}

struct vector *vector_append(struct vector *v, int elt)
{
    if (!v)
        return NULL;

    if (v->size == v->capacity)
    {
        struct vector *qwq = vector_resize(v, v->capacity * 2);
        if (!qwq)
            return NULL;
        v = qwq;
    }

    v->data[v->size++] = elt;

    return v;
}

void vector_print(const struct vector *v)
{
    if (!v || v->size == 0)
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

    if (v->size == v->capacity)
    {
        size_t kapa = v->capacity * 2;
        int *qwq = realloc(v->data, kapa * sizeof(int));
        if (!qwq)
            return NULL;
        v->data = qwq;
        v->capacity = kapa;
    }

    for (size_t u = v->size; u > i; u--)
        v->data[u] = v->data[u - 1];

    v->data[i] = elt;
    v->size++;

    return v;
}

struct vector *vector_remove(struct vector *v, size_t i)
{
    if (!v || i >= v->size)
        return NULL;

    for (size_t u = i; u < v->size - 1; u++)
        v->data[u] = v->data[u + 1];

    v->size--;

    // If too small, skrink the vector
    if (v->size < v->capacity / 2)
    {
        size_t kapa = v->capacity / 2;
        if (kapa < 1)
            kapa = 1;

        int *qwq = realloc(v->data, kapa * sizeof(int));
        if (!qwq)
            return NULL;

        v->data = qwq;
        v->capacity = kapa;
    }

    return v;
}

/*
int main(void)
{
    // test resize
    struct vector *v = vector_init(1);
    if (!v)
        return 1;

    for (size_t i = 0; i < 10; i++)
    {
        struct vector *qwq = vector_append(v, i);
        if (!qwq)
            return 1;
        v = qwq;

        // Print vector capacity
        printf("Capacity: %zu\n", v->capacity);
    }

    vector_print(v);

    for (size_t i = 10; i > 0; i--)
    {
        struct vector *qwq = vector_remove(v, i-1);
        if (!qwq)
            return 1;
        v = qwq;

        // Print vector size
        printf("Size: %zu\n", v->size);
        // Print vector capacity
        printf("Capacity: %zu\n", v->capacity);
    }

    vector_print(v);

    // Free vector
    vector_destroy(v);
    return 0;
}
*/
