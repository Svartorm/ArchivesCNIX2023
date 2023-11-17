#include <stdio.h>
#include <stdlib.h>

void sieve(int n)
{
    if (n <= 2)
        return;

    int *sieve = calloc(n + 1, sizeof(int));

    for (int i = 2; i * i <= n; i++)
    {
        if (sieve[i] == 0)
            for (int u = i * i; u <= n; u += i)
                sieve[u] = 1;
    }

    int cpt = 0;
    for (int i = 2; i < n; i++)
        if (sieve[i] == 0)
            cpt++;

    printf("%i\n", cpt);
    free(sieve);
}
