#include <stdio.h>

int check_alphabet(const char *str, const char *alphabet)
{
    if (alphabet == NULL || alphabet[0] == 0)
        return 1;

    for (int i = 0; alphabet[i] != 0; i++)
    {
        int flag = 0;
        for (int u = 0; str[u] != 0; u++)
        {
            if (str[u] == alphabet[i])
            {
                flag = 1;
                break;
            }
        }

        if (flag == 0)
            return 0;
    }

    return 1;
}

/*
int main(void)
{
    printf("%d\n", check_alphabet("toto", NULL));
    printf("%d\n", check_alphabet("", "t"));
    printf("%d\n", check_alphabet("toto asticot", "otaisc k"));
    printf("%d\n", check_alphabet("toto asticot", "ot"));
    return 0;
}
*/
