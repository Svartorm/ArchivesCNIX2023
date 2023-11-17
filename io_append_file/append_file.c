#include <stdio.h>

int append_file(const char *file_in, const char *content)
{
    FILE *dest = fopen(file_in, "a");

    if (!dest)
        return -1;

    fprintf(dest, "%s", content);

    fclose(dest);
    return 0;
}

int main(void)
{
    return 0;
}
