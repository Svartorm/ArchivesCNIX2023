#include "bst_static.h"

#include <stddef.h>
#include <stdio.h>
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

void increase_capacity(struct bst *tree)
{
    size_t new_capacity = tree->capacity * 2;
    struct value **new_data =
        realloc(tree->data, new_capacity * sizeof(struct value *));
    if (new_data == NULL)
        return;

    // Set new data to NULL
    for (size_t i = tree->capacity; i < new_capacity; i++)
        new_data[i] = NULL;

    tree->data = new_data;
    tree->capacity = new_capacity;
}

void add(struct bst *tree, int value)
{
    // Add a new value to the tree
    if (tree == NULL)
        return;

    // Check if value already exists
    if (search(tree, value) != -1)
        return;

    // Check if tree is full
    if (tree->size >= tree->capacity)
    {
        // Double the capacity of the tree
        increase_capacity(tree);
    }

    // Create new value
    struct value *new = calloc(1, sizeof(struct value));
    if (new == NULL)
        return;

    new->val = value;

    // Add new value to bst
    size_t i = 0;
    while (tree->data[i] != NULL)
    {
        if (value < tree->data[i]->val)
            i = 2 * i + 1;
        else
            i = 2 * i + 2;

        if (i >= tree->capacity)
            increase_capacity(tree);
    }
    tree->data[i] = new;
    tree->size++;
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

/*
// Mqin to test bst add

int main(void)
{
    struct bst *tree = init(10);

    add(tree, 1);
    add(tree, 2);
    add(tree, 3);
    add(tree, 4);
    add(tree, 5);
    add(tree, 6);
    add(tree, 7);

    for (size_t i = 0; i < tree->capacity; i++)
        if (tree->data[i])
            printf("%d\n", tree->data[i]->val);

    bst_free(tree);
    return 0;
}
*/
