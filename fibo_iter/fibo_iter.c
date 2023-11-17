#include <stdio.h>

unsigned long fibo_iter(unsigned long n)
{
    unsigned long uwu = 0;
    unsigned long owo = 1;
    unsigned long qwq = 0;
    unsigned long cpt = 0;

    while (cpt <= n)
    {
        if (cpt < 2)
        {
            qwq = cpt;
        }
        else
        {
            qwq = uwu + owo;
            uwu = owo;
            owo = qwq;
        }
        cpt++;
    }
    return qwq;
}
