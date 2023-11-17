#include <stdio.h>

#include "binary_tree.h"

int size(const struct binary_tree *tree)
{
    if (!tree)
        return 0;

    return 1 + size(tree->left) + size(tree->right);
}

int height(const struct binary_tree *tree)
{
    if (!tree)
        return -1;

    return 1
        + (height(tree->left) > height(tree->right) ? height(tree->left)
                                                    : height(tree->right));
}

int power(int a, int b)
{
    int res = 1;
    for (; b > 0; b--)
        res *= a;
    return res;
}

int is_perfect(const struct binary_tree *tree)
{
    if (!tree)
        return 1;

    int depth = height(tree);

    return size(tree) == power(2, depth + 1) - 1 ? 1 : 0;
}

int check_complete(const struct binary_tree *tree, int n, int total_node)
{
    if (!tree)
        return 1;

    if (n > total_node)
        return 0;

    return check_complete(tree->left, 2 * n + 1, total_node)
        && check_complete(tree->right, 2 * n + 2, total_node);
}

int is_complete(const struct binary_tree *tree)
{
    return check_complete(tree, 0, size(tree) - 1);
}

int is_degenerate(const struct binary_tree *tree)
{
    if (!tree)
        return 1;

    if (tree->left && tree->right)
        return 0;

    return tree->right ? is_degenerate(tree->right) : is_degenerate(tree->left);
}

int is_full(const struct binary_tree *tree)
{
    if (!tree)
        return 1;

    if (tree->left && tree->right)
        return is_full(tree->left) && is_full(tree->right);

    return !tree->left && !tree->right;
}
