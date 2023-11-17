#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>

void swap(char *uwu, char *owo)
{
    char qwq = *uwu;
    *uwu = *owo;
    *owo = qwq;
}

void str_revert(char str[])
{
    int len = 0;
    while (str[len] != 0)
        len++;

    int uwu = 0;
    int owo = len - 1;

    for (int i = 0; i < len / 2; i++)
    {
        swap(&str[uwu], &str[owo]);
        uwu++;
        owo--;
    }
}

char *my_itoa_base(int value, char *s, const char *base)
{
    if (value == 0)
    {
        *s = *base;
        *(s + 1) = 0;
        return s;
    }

    int len = 0;
    while (*(base + len) != 0)
        len++;

    int i = 0;
    int flag = 0;

    if (value < 0)
    {
        value *= -1;
        flag = 1;
    }

    while (value > 0)
    {
        *(s + i) = base[value % len];
        value /= len;
        i++;
    }

    if (flag == 1)
    {
        *(s + i) = '-';
        i++;
    }

    *(s + i) = 0;
    str_revert(s);

    return s;
}

Test(itoa_base, basic)
{
    char s[100] = { 0 };
    cr_expect_str_eq(my_itoa_base(42, s, "0123456789ABCDEF"), "2A",
                     "Expected '%s' but got '%s'.", "2A",
                     my_itoa_base(42, s, "123456789ABCDEF"));
}

Test(itoa_base, neg)
{
    char s[100];
    char *actual = my_itoa_base(32, s, "0123456789abcdef");
    char *expected = "20";
    cr_expect_str_eq(actual, expected, "Expected '%s' but got '%s'.", expected,
                     actual);
}

Test(itoa_base, bin)
{
    char s[100];
    char *actual = my_itoa_base(12, s, "01");
    char *expected = "1100";
    cr_expect_str_eq(actual, expected, "Expected '%s' but got '%s'.", expected,
                     actual);
}

Test(itoa_base, complex)
{
    char s[100];
    char *actual = my_itoa_base(80, s, "0123456");
    char *expected = "143";
    cr_expect_str_eq(actual, expected, "Expected '%s' but got '%s'.", expected,
                     actual);
}
