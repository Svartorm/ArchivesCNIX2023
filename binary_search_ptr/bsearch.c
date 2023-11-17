#include <assert.h>
#include <stdio.h>

int *binary_search(int *begin, int *end, int elt)
{
    while (end - begin > 0)
    {
        int *mid = begin + (end - begin) / 2;

        if (elt == *mid)
            return mid;

        if (elt < *mid)
            end = mid;

        else
            begin = mid + 1;
    }

    return end;
}
int main(void)
{
    int a[] = { 0, 1, 4, 5, 9, 10, 18, 22, 42, 51, 69 };

    assert(binary_search(a, a + 11, 5) == a + 3);

    assert(binary_search(a, a + 11, 0) == a);

    assert(binary_search(a, a + 11, -1) == a);

    assert(binary_search(a, a + 11, 99) == a + 11);

    assert(binary_search(a, a + 11, 68) == a + 10);

    assert(binary_search(a, a, 5) == a);
}
