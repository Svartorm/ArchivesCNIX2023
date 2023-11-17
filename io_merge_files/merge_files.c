#include <stdio.h>

int merge_files(const char *file_1, const char *file_2)
{
    FILE *dest = fopen(file_1, "r+");
    FILE *src = fopen(file_2, "r");

    if (!dest || !src)
        return -1;

    int seek = fseek(dest, 0, SEEK_END);
    if (seek == -1)
        return -1;

    char c = fgetc(src);
    while (c != EOF)
    {
        fputc(c, dest);
        c = fgetc(src);
    }

    fclose(dest);
    fclose(src);
    return 0;
}

int main(void)
{
    merge_files("noexist", "noexist");
    return 0;
}
