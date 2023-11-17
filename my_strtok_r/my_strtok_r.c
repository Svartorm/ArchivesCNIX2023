#include <stdio.h>

static int is_delim(char c, const char *delim)
{
    while (*delim != 0)
        if (c == *delim)
            return 1;
        else
            delim++;
    return 0;
}

char *my_strtok_r(char *str, const char *delim, char **saveptr)
{
    if (delim == NULL)
        return NULL;

    // If not the first call -> use saveptr instead
    if (str == NULL)
        str = *saveptr;

    // Skip starting delims
    while (*str != 0 && is_delim(*str, delim) == 1)
        str++;

    if (*str == 0)
    {
        *saveptr = str;
        return NULL;
    }

    char *head = str; // Start of our token
    while (*str != 0 && is_delim(*str, delim) == 0)
        str++;

    // Set the end of our token
    if (*str == 0)
        *saveptr = str;
    else
    {
        *str = 0;
        str++;
        *saveptr = str;
    }

    str = NULL;

    return head;
}

/*
// Init our token
char *head = NULL;

// Run through our string
int i = 0;
for (; str[i] != 0; i++)
{
    // int dflag = 0;

    // Check for delimiters
    for (int u = 0; delim[u] != 0; u++)
    {
        if (str[i] == delim[u]) // We found a delimiter
        {
            // dflag = 1;

            if (head == NULL) // No token before -> continue to check
                continue;

            // Save and terminate
            *saveptr = str + i + 1; // Save the rest of the string
            *(head + i) = 0; // Terminate our token
            str = NULL; // Reset our str
            return head; // Return token
        }
    }

    // If we found a token char
    if (dflag == 0 && head == NULL) // And our token is not init
        head = str + i; // Init token
}
}
int main(void)
{
    char str[] = "        Fox    william";
    char *delim = " ";
    char *save;

    printf("Got: %s", my_strtok_r(str, delim, &save));

    return 0;
}
*/
