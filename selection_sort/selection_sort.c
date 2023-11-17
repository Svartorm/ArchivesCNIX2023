#include <stdio.h>

void swap(int *a, int *b)
{
    int uwu = *a;
    *a = *b;
    *b = uwu;
}

unsigned array_min(const int arr[], unsigned start, unsigned size)
{
    int mini = start;

    for (unsigned i = start + 1; i < size; i++)
        if (arr[i] < arr[mini])
            mini = i;

    return mini;
}

void selection_sort(int arr[], unsigned size)
{
    if (size == 0)
        return;

    for (unsigned i = 0; i < size - 1; i++)
    {
        unsigned mini = array_min(arr, i, size);

        if (mini != i)
            swap(&arr[mini], &arr[i]);
    }
}
