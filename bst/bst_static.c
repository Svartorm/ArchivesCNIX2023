#include "bst_static.h"

#include <stddef.h>
#include <stdlib.h>

struct bst *init(size_t capacity)
{
    struct bst *tree = calloc(1, sizeof(struct bst));
    if (tree == NULL)
        return NULL;

    tree->capacity = capacity;
    tree->size = 0;
    tree->data = calloc(capacity, sizeof(struct value *));

    if (tree->data == NULL)
    {
        free(tree);
        return NULL;
    }

    return tree;
}

void add(struct bst *tree, int value)
{
    if (tree == NULL)
        return;

    if (tree->size >= tree->capacity)
    {
        size_t qwq = tree->capacity * 2;

        // Create new data
        struct value **new = realloc(tree->data, qwq * sizeof(struct value *));
        if (new == NULL)
            return;

        // Fill the new data array with NULL
        for (size_t i = tree->capacity; i < qwq; i++)
            tree->data[i] = NULL;

        tree->data = new;
        tree->capacity = qwq;
    }

    struct value *val = malloc(sizeof(struct value));

    val->val = value;

    size_t root = 0;
    size_t left = 2 * root + 1;
    size_t right = 2 * root + 2;

    while (root <= tree->capacity)
    {
        if (!tree->data[root])
        {
            tree->data[root] = val;
            return;
        }

        if (tree->data[root]->val < value)
        {
            root = left;
            continue;
        }

        root = right;
    }

    free(val);
    return;
}

int search(struct bst *tree, int value)
{
    if (tree == NULL)
        return -1;

    for (size_t i = 0; i < tree->capacity; i++)
        if (tree->data[i] && tree->data[i]->val == value)
            return i;

    return -1;
}

void bst_free(struct bst *tree)
{
    if (tree == NULL)
        return;

    for (size_t i = 0; i < tree->capacity; i++)
        free(tree->data[i]);

    free(tree->data);
    free(tree);
}
