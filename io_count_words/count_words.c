#include <stdio.h>

int count_words(const char *file_in)
{
    if (!file_in)
        return -1;

    FILE *in = fopen(file_in, "r");

    if (!in)
        return -1;

    int cpt = 0;
    char c = fgetc(in);
    int is_in_word = 1; // ! = Not in word, 0 = in file

    while (c != EOF)
    {
        if (c != ' ' && c != '\t' && c != '\n')
        {
            if (is_in_word == 1)
            {
                cpt++;
                is_in_word = 0;
            }
        }
        else
        {
            if (is_in_word == 0)
            {
                is_in_word = 1;
            }
        }

        c = fgetc(in);
    }

    return cpt;
}

/*
int main(void)
{
    printf("%i\n", count_words("empty.txt"));
    printf("%i\n", count_words("oneline.txt"));
    printf("%i\n", count_words("multline.txt"));
    printf("%i\n", count_words("noword.txt"));
    return 0;
}
*/
