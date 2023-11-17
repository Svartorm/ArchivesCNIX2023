#include "complex.h"

#include <stdio.h>

void print_complex(struct complex a)
{
    printf("complex(%.2f ", a.real);

    if (a.img < 0)
        printf("- %.2fi)\n", a.img * -1);
    else
        printf("+ %.2fi)\n", a.img);
}

struct complex neg_complex(struct complex a)
{
    struct complex neg;
    neg.real = a.real * -1;
    neg.img = a.img * -1;

    return neg;
}

struct complex add_complex(struct complex a, struct complex b)
{
    struct complex uwu;
    uwu.real = a.real + b.real;
    uwu.img = a.img + b.img;

    return uwu;
}

struct complex sub_complex(struct complex a, struct complex b)
{
    struct complex uwu;
    uwu.real = a.real - b.real;
    uwu.img = a.img - b.img;

    return uwu;
}

struct complex mul_complex(struct complex a, struct complex b)
{
    struct complex uwu;
    uwu.real = a.real * b.real - a.img * b.img;
    uwu.img = a.real * b.img + b.real * a.img;

    return uwu;
}

struct complex div_complex(struct complex a, struct complex b)
{
    struct complex uwu;
    uwu.real =
        (a.real * b.real + a.img * b.img) / (b.real * b.real + b.img * b.img);
    uwu.img =
        (a.img * b.real - a.real * b.img) / (b.real * b.real + b.img * b.img);

    return uwu;
}
