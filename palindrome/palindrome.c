#include "palindrome.h"

#include <stdio.h>

int palindrome(const char *s)
{
    if (!s)
        return 0;

    int len = 0;
    while (*(s + len) != 0)
        len++;

    int owo = len - 1;

    for (int uwu = 0; uwu < len; uwu++)
    {
        char c = s[uwu];
        if (c < 'a' || c > 'z')
        {
            if (c < 'A' || c > 'Z')
            {
                if (c < '0' || c > '9')
                {
                    continue;
                }
            }
        }

        char h = s[owo];
        if (h < 'a' || h > 'z')
        {
            if (h < 'A' || h > 'Z')
            {
                if (h < '0' || h > '9')
                {
                    uwu--;
                    owo--;
                    continue;
                }
            }
        }

        if (s[uwu] != s[owo])
            return 0;
        owo--;
    }

    return 1;
}
