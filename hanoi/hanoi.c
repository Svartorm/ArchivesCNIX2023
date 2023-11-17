#include <stdio.h>

void process(unsigned n, int uwu, int owo, int qwq)
{
    if (n > 0)
    {
        process(n - 1, uwu, qwq, owo);
        printf("%i->%i\n", uwu, owo);
        process(n - 1, qwq, owo, uwu);
    }
}

void hanoi(unsigned n)
{
    process(n, 1, 3, 2);
}
