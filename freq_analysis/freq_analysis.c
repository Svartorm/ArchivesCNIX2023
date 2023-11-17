#include <stdio.h>

int get_max_index(int array[], int size)
{
    int maxi = 0;
    for (int i = 1; i < size; i++)
        if (array[i] > array[maxi])
            maxi = i;
    return maxi;
}

void freq_analysis(const char text[], const char table[])
{
    // Histogram
    int histo[26] = { 0 };
    for (int i = 0; text[i] != 0; i++)
        histo[text[i] - 'A']++;

    // Sort using table
    // histo[histo_index] = - (table_index + 1)
    for (int i = 0; table[i] != 0; i++)
    {
        int histo_index = get_max_index(histo, 26);

        histo[histo_index] = -(i + 1);
    }

    // Output alphabetical order
    for (int i = 0; i < 26; i++)
    {
        printf("histo[%i] = %i\n", i, histo[i]);
        if (histo[i] >= 0)
            continue;

        char text_char = i + 'A';
        char table_char = table[-(histo[i] + 1)];
        printf("%c %c\n", text_char, table_char);
    }
}
int main(void)
{
    freq_analysis("CAABB", "XYZ");
    return 0;
}
