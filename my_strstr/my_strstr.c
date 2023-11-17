#include <stdio.h>

int my_strstr(const char *haystack, const char *needle)
{
    if (needle == NULL || needle[0] == 0)
        return 0;

    int i = 0;
    int ni = 0;
    int res = -1;

    while (haystack[i] != 0)
    {
        if (needle[ni] == 0)
            return res;
        if (haystack[i] == needle[ni])
        {
            if (ni == 0)
                res = i;
            ni++;
        }
        else
        {
            if (ni != 0)
            {
                i -= ni - 1;
                ni = 0;
                continue;
            }
        }
        i++;
    }

    if (needle[ni] != 0)
        return -1;
    return res;
}

/*
int main(void)
{
    printf("%i\n", my_strstr("You are so frfrfraish", "frfrais"));
    return 0;
}
*/
