#include "bst.h"

#include <stddef.h>
#include <stdlib.h>

struct bst_node *create_node(int value)
{
    struct bst_node *node = malloc(sizeof(struct bst_node));
    if (node == NULL)
    {
        return NULL;
    }
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct bst_node *add_node(struct bst_node *tree, int value)
{
    if (tree == NULL)
        return create_node(value);

    if (value < tree->data)
    {
        tree->left = add_node(tree->left, value);
        return tree;
    }

    if (value > tree->data)
    {
        tree->right = add_node(tree->right, value);
    }
    return tree;
}

struct bst_node *delete_node(struct bst_node *tree, int value)
{
    // Stopping cases
    //  Leaf node
    if (tree == NULL)
    {
        return NULL;
    }

    // Value is less than current node
    if (value < tree->data)
    {
        tree->left = delete_node(tree->left, value);
        return tree;
    }

    // Value is greater than current node
    if (value > tree->data)
    {
        tree->right = delete_node(tree->right, value);
        return tree;
    }

    // WE FOUND OUR NODE

    // Left child or right child is NULL
    // We return the non-NULL child
    if (tree->left == NULL)
    {
        struct bst_node *qwq = tree->right;
        free(tree);
        return qwq;
    }
    if (tree->right == NULL)
    {
        struct bst_node *qwq = tree->left;
        free(tree);
        return qwq;
    }

    // Both children are not NULL
    // We find the smallest value in the right subtree
    // and replace the current node with that value
    struct bst_node *qwq = tree->left;
    while (qwq->right != NULL)
    {
        qwq = qwq->right;
    }
    tree->data = qwq->data;
    tree->left = delete_node(tree->left, qwq->data);
    return tree;
}

const struct bst_node *find(const struct bst_node *tree, int value)
{
    if (tree == NULL)
        return NULL;

    if (tree->data == value)
        return tree;

    if (value > tree->data)
        return find(tree->right, value);

    // value < tree->data
    return find(tree->left, value);
}

void free_bst(struct bst_node *tree)
{
    if (tree == NULL)
        return;
    free_bst(tree->left);
    free_bst(tree->right);
    free(tree);
}
