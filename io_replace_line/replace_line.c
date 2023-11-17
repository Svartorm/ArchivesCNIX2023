#define _POSIX_C_SOURCE 200809L

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

// Push a line from in into out
// Return 1 if success, -1 else
int pushline(FILE *in, FILE *out, int should_push)
{
    char *line;
    size_t len = 0;

    int res_code = getline(&line, &len, in);
    if (res_code == -1)
    {
        free(line);
        return -1;
    }

    if (should_push == 1)
        fputs(line, out);

    free(line);

    return 1;
}

// Push the content of the string into out
// Return the number of line transfered
int pushcontent(const char *content, FILE *out)
{
    fputs(content, out);

    // Count number of line
    int feed = 0;
    while (*content != 0)
    {
        if (*content == '\n')
        {
            feed++;
        }

        content++;
    }

    return feed;
}

int replace_line(const char *file_in, const char *file_out, const char *content,
                 int n)
{
    if (!file_in || !file_out)
        return -1;

    FILE *in = fopen(file_in, "r");
    FILE *out = fopen(file_out, "w");

    if (!in || !out)
        return -1;

    int feed = 0;
    int has_put_content_in = 1;
    int res = 1;

    while (res == 1)
    {
        if (feed == n)
        {
            pushcontent(content, out);
            res = pushline(in, out, 0);
            has_put_content_in = 0;
            feed++;
            continue;
        }

        // Else copie file_in
        res = pushline(in, out, 1);
        feed++;
    }

    fclose(in);
    fclose(out);

    return has_put_content_in;
}

int main(void)
{
    return 0;
}
