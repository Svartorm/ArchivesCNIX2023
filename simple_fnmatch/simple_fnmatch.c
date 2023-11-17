#include "simple_fnmatch.h"

#include <stdio.h>

int simple_fnmatch(const char *pattern, const char *string)
{
    while (*pattern)
    {
        switch (*pattern)
        {
        case '?':
            if (*string == 0)
                return FNM_NOMATCH;
            pattern++;
            string++;
            break;

        case '*':
            while (*(pattern + 1) == '*')
                pattern++;

            if (*(pattern + 1) == 0)
                return 0;
            pattern++;

            while (*string)
            {
                if (simple_fnmatch(pattern, string) == 0)
                    return 0;
                string++;
            }

            return FNM_NOMATCH;

        case '\\':
            pattern++;

        /* FALLTHROUGH */
        default:
            if (*pattern != *string)
                return FNM_NOMATCH;
            pattern++;
            string++;
            break;
        }
    }

    if (*string)
        return FNM_NOMATCH;
    return 0;
}
/*
int main(void)
{
    char *pat = "file*.*";
    char *str = "file.txt";
    int res = simple_fnmatch(pat, str);
    printf("Result of %s, <=> %s | %i\n", pat, str, res);

    return 0;
}
*/
