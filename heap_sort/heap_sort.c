#include <stddef.h>
#include <stdio.h>

void swap(int *uwu, int *owo)
{
    int qwq = *uwu;
    *uwu = *owo;
    *owo = qwq;
}

void heapify(int *array, size_t size)
{
    size_t root = 0;
    size_t left = 2 * root + 1;
    size_t right = 2 * root + 2;

    int i = size - 1;
    for (; i >= 0; i--)
    {
        root = i;
        left = 2 * root + 1;
        right = 2 * root + 2;

        while (1)
        {
            size_t max = root;

            if (left < size && array[left] > array[max])
                max = left;
            if (right < size && array[right] > array[max])
                max = right;

            if (max == root)
                break;

            swap(&array[root], &array[max]);

            root = max;
            left = 2 * root + 1;
            right = 2 * root + 2;
        }
    }
}

void heap_sort(int *array, size_t size)
{
    heapify(array, size);

    for (size_t i = 0; i < size; i++)
    {
        swap(array, array + (size - 1 - i));
        heapify(array, size - 1 - i);
    }
}
