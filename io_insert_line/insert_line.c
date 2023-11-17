#define _POSIX_C_SOURCE 200809L

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

// Push a line from in into out
// Return 1 if success, -1 else
int pushline(FILE *in, FILE *out)
{
    char *line;
    size_t len = 0;

    int res_code = getline(&line, &len, in);
    if (res_code == -1)
    {
        free(line);
        return -1;
    }

    fputs(line, out);

    free(line);

    return 1;
}

// Push the content of the string into out
// Return the number of line transfered
int pushcontent(const char *content, FILE *out, int *trailling)
{
    fputs(content, out);

    // Count number of line
    int feed = 0;
    while (*content != 0)
    {
        if (*content == '\n')
        {
            feed++;

            if (*(content + 1) == 0)
                *trailling = 1;
        }

        content++;
    }

    return feed;
}

int insert_line(const char *file_in, const char *file_out, const char *content,
                size_t n)
{
    if (!file_in || !file_out)
        return -1;

    FILE *in = fopen(file_in, "r");
    FILE *out = fopen(file_out, "w");

    if (!in || !out)
        return -1;

    size_t feed = 0;

    // Transfer before content
    while (feed < n)
    {
        int res = pushline(in, out);
        if (res == -1) // No more line to read
            fputs("\n", out);
        feed++;
    }

    // Transfer content
    int trail = 0; // 1 if there is a trailling backspace, 0 else
    feed += pushcontent(content, out, &trail);

    // Transfer after content
    int after = pushline(in, out);

    if (after == -1 && trail == 0)
        feed++;

    if (after != -1) // If nothing after, DO NOT count the trailling backspace
    {
        feed++;
        while ((after = pushline(in, out)) != -1)
            feed++;
    }

    fclose(in);
    fclose(out);

    return feed;
}
/*
int main(void)
{
    printf("Number of line: %i\n",
           insert_line("file_in", "file_out",
                       "The quick white fox jump over the lazy fox\n", 0));
    printf("Number of line: %i\n",
           insert_line("file_in", "file_out2", "Line 1\n", 1));
    printf("Number of line: %i\n",
           insert_line("file_in", "file_out3", "Last line\n", 3));
    printf("Number of line: %i\n",
           insert_line("file_in2", "file_out4", "Nolinefeedlololololololol",
2)); return 0;
}*/
