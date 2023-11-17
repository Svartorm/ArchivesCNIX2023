#include <stdio.h>

int mod(int a, int b)
{
    int result = a % b;
    return result >= 0 ? result : result + b;
}

char to_upper(char c)
{
    if (c >= 'a' && c <= 'z')
        return c - 32;
    return c;
}

void cipher(const char *key, const char *msg, char *res)
{
    int k = 0;
    while (*(key + k) != 0)
        k++;

    int i = 0;
    int u = 0;
    for (; msg[i] != 0; i++)
    {
        char c = to_upper(msg[i]);
        char kee = to_upper(key[u % k]);

        if (c >= 'A' && c <= 'Z')
        {
            res[i] = mod(c + kee, 26) + 'A';
            u++;
            continue;
        }

        res[i] = c;
    }

    res[i] = 0;
}

void decipher(const char *key, const char *msg, char *res)
{
    int k = 0;
    while (*(key + k) != 0)
        k++;

    int i = 0;
    int u = 0;
    for (; msg[i] != 0; i++)
    {
        char c = to_upper(msg[i]);
        char kee = to_upper(key[u % k]);

        if (c >= 'A' && c <= 'Z')
        {
            res[i] = mod(c - kee, 26) + 'A';
            u++;
        }
        else
            res[i] = c;
    }
    res[i] = 0;
}

// PB:
//  - CIPHER:
//      -> str did not change. EX: "HELLO WORLD!"
//
//  - DECIPHER:
//      -> "Memory errors" <- Whatever that means
//

/*
int main(void)
{
    char *s = "HELLO WORLD!";
    char *key = "UWU";
    char ciph[300];
    char dec[300];

    cipher(key, s, ciph);

    printf("Cipher: %s\n", ciph);

    decipher(key, ciph, dec);

    printf("Decipher: %s\n", dec);

    return 0;
}
*/
