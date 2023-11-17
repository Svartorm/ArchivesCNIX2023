#include <stdio.h>

int binary_search(const int vec[], int size, int elt)
{
    int beg = 0;
    int end = size - 1;
    while (beg <= end)
    {
        int mid = beg + (end - beg) / 2;

        if (elt == vec[mid])
            return mid;

        if (elt > vec[mid])
            beg = mid + 1;

        if (elt < vec[mid])
            end = mid - 1;
    }
    return -1;
}
