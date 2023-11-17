#define _POSIX_C_SOURCE 200809L

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int reverse_content(const char *file_in, const char *file_out)
{
    if (!file_in || !file_out)
        return -1;

    FILE *in = fopen(file_in, "r");
    FILE *out = fopen(file_out, "w");

    if (!in || !out)
        return -1;

    int seek = fseek(in, 0, SEEK_END);
    if (seek == -1)
        return -1;

    seek = fseek(in, -1, SEEK_CUR);
    while (seek == 0)
    {
        // Get char
        char c = fgetc(in);
        if (c == -1)
            return -1;

        fputc(c, out);

        // Move back
        seek = fseek(in, -2, SEEK_CUR);
    }

    fclose(in);
    fclose(out);

    return 0;
}
