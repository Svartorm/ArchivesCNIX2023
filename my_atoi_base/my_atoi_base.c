#include <stdio.h>

int power(int a, int exp)
{
    int uwu = 1;
    for (; exp > 0; exp--)
    {
        uwu *= a;
    }
    return uwu;
}

int is_in_base(char c, const char *base)
{
    int i = 0;
    while (*(base + i) != 0)
    {
        if (*(base + i) == c)
            return i;
        i++;
    }
    return -1;
}

int my_atoi_base(const char *str, const char *base)
{
    int len = 0;
    while (*(base + len) != 0)
        len++;

    // printf("Base len = %i\n", len);

    int str_len = 0;
    while (*(str + str_len) != 0)
        str_len++;

    // printf("STR len = %i\n", str_len);

    int i = 0;
    while (str[i] == ' ')
        i++;

    int sign = 1;
    if (str[i] == '-' || str[i] == '+')
    {
        sign = 1 - 2 * (str[i++] == '-');
    }

    // printf("sign = %i\n", sign);

    int uwu = 0;
    while (*(str + i))
    {
        // printf("|->\n");
        int u = is_in_base(*(str + i), base);
        // printf("\tu = %i\n", u);
        if (u == -1)
            return 0;

        // printf("\tu * 2 ^ (str_len - 1 - i) = %i\n", u * power(len, (str_len
        // - 1 - i)));
        uwu += u * power(len, (str_len - 1 - i));
        // printf("\tUwU = %i\n", uwu);
        i++;
    }

    return uwu * sign;
}

/*
** int main(void)
** {
**     printf("--- Test ---\n");
**     printf("Res = %i\n", my_atoi_base("  -!!!@$$$!#","!@#$"));
** }
*/
