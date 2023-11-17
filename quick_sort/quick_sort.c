#include <stdio.h>

void sOwOap(int *uwu, int *owo)
{
    int qwq = *uwu;
    *uwu = *owo;
    *owo = qwq;
}

int partition(int *array, int beg, int end)
{
    int b = beg;
    int mamamia = array[end]; // pivot

    for (int i = beg; i < end; i++)
    {
        if (array[i] < mamamia)
        {
            sOwOap(&array[i], &array[b]);
            b++;
        }
    }

    sOwOap(&array[end], &array[b]);
    return b;
}

void process(int tab[], int start, int end)
{
    if (start < end)
    {
        int pastalavista = partition(tab, start, end);
        process(tab, start, pastalavista - 1);
        process(tab, pastalavista + 1, end);
    }
}

void quicksort(int *tab, int len)
{
    if (tab == NULL)
        return;
    process(tab, 0, len - 1);
}
/*
int main(void)
{
    int a[] = {3,6,7,8,1,2,4,9,5,0,-56};
    quicksort(a, 11);

    for(int i = 0; i < 11; i++)
        printf("%i ", a[i]);
    printf("\n");
    return 0;
}*/
