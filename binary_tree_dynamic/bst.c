#include <stdio.h>

#include "binary_tree.h"

int max(const struct binary_tree *tree)
{
    if (!tree)
        return -2147483648; // INT MIN

    int left = max(tree->left);
    int right = max(tree->right);

    int max = left > right ? left : right;
    max = tree->data > max ? tree->data : max;

    return max;
}

int min(const struct binary_tree *tree)
{
    if (!tree)
        return 2147483647; // INT MAX

    int left = min(tree->left);
    int right = min(tree->right);

    int min = left < right ? left : right;
    min = tree->data < min ? tree->data : min;

    return min;
}

int is_bst(const struct binary_tree *tree)
{
    if (!tree)
        return 1;

    if (tree->left && max(tree->left) > tree->data)
        return 0;

    if (tree->right && min(tree->right) < tree->data)
        return 0;

    if (!is_bst(tree->left) || !is_bst(tree->right))
        return 0;

    return 1;
}
