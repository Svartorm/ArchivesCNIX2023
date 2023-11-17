#include <stdio.h>

char to_upper(char c)
{
    if (c >= 'a' && c <= 'z')
        return c - 32;
    else
        return c;
}

int my_strcasecmp(const char *s1, const char *s2)
{
    while (*s1)
    {
        char uwu = to_upper(*s1);
        char owo = to_upper(*s2);

        if (uwu != owo)
            break;
        s1++;
        s2++;
    }

    return to_upper(*s1) - to_upper(*s2);
}

int main(void)
{
    const char *a = "ABCD";
    const char *b = "abcda";
    printf("%i\n", my_strcasecmp(a, b));
}
