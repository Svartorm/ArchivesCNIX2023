#include <stdio.h>

int mod(int a, int b)
{
    return (a % b) >= 0 ? a % b : a % b + b;
}

int is_letter(char c)
{
    if (c >= 'A' && c <= 'Z')
        return 2;
    if (c >= 'a' && c <= 'z')
        return 1;
    return 0;
}

void rot_x(char *s, int x)
{
    if (s == NULL)
        return;

    while (*s)
    {
        if (is_letter(*s) == 2)
            *s = mod((*s - 'A') + x, 26) + 'A';
        if (is_letter(*s) == 1)
            *s = mod((*s - 'a') + x, 26) + 'a';
        s++;
    }
}
/*
int main(void)
{
    char in[] = "Shhh ShE is ZZZzZ059%";

    printf("In: %s\n", in);
    rot_x(in, 13);
    printf("Out: %s\n", in);

    return 0;
}
*/
