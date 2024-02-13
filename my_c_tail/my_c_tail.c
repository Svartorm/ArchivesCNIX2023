#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void shift_left(char **lines, size_t len)
{
    for (size_t i = 0; i < len - 1; i++)
        lines[i] = lines[i + 1];
}

int count_lines(const char *buffer, size_t total_size)
{
    int num_lines = 0;
    for (size_t i = 0; i < total_size; i++)
    {
        if (buffer[i] == '\n')
            num_lines++;
    }
    return num_lines;
}

char *read_input(size_t *total_size)
{
    // Allocate memory for the buffer
    size_t buffer_size = BUFFER_SIZE;
    char *buffer = malloc(buffer_size);
    if (buffer == NULL)
        return NULL;

    // Read input into buffer
    while (1)
    {
        // Resize buffer if necessary
        if (*total_size + buffer_size > *total_size)
        {
            buffer_size *= 2;
            buffer = realloc(buffer, buffer_size);
            if (buffer == NULL)
            {
                free(buffer);
                return NULL;
            }
        }

        // Read input into buffer
        int bytes_read =
            read(STDIN_FILENO, buffer + *total_size, buffer_size - *total_size);
        if (bytes_read == -1)
        {
            free(buffer);
            return NULL;
        }
        else if (bytes_read == 0)
            break;

        *total_size += bytes_read;
    }

    return buffer;
}

void stdintail(unsigned int n)
{
    // Read input
    size_t total_size = 0;
    char *buffer = read_input(&total_size);
    if (buffer == NULL)
        return;

    // Count lines
    size_t cpt = count_lines(buffer, total_size);

    // Save last n lines
    n = (n > cpt) ? cpt : n;
    char **lines = malloc(cpt * sizeof(char *));
    if (lines == NULL)
    {
        free(buffer);
        return;
    }
    // Allocate memory for each line
    for (size_t i = 0; i < cpt; i++)
        lines[i] = malloc(total_size * sizeof(char));

    // Fill lines
    size_t u = 0; // Line index
    size_t v = 0; // Char index
    for (size_t i = 0; i < total_size; i++)
    {
        lines[u][v] = buffer[i];

        if (buffer[i] == '\n')
        {
            v = 0;
            u++;
        }
        else
            v++;
    }

    // Write last n lines
    for (size_t i = cpt - n; i < cpt; i++)
    {
        // Get line size
        size_t line_size = 0;
        while (lines[i][line_size] != '\n')
            line_size++;

        write(STDOUT_FILENO, lines[i], line_size + 1);
    }

    // Free memory
    for (size_t i = 0; i < cpt; i++)
        free(lines[i]);
    free(lines);
    free(buffer);
}

/*
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <n>\n", argv[0]);
        return EXIT_FAILURE;
    }

    unsigned int n = atoi(argv[1]);
    stdintail(n);

    return EXIT_SUCCESS;
}
*/
