#include <stddef.h>
#include <stdlib.h>

void reverse_array(const char **array)
{
    // Reverse the array
    const char **end = array;
    while (*end != NULL)
        end++;
    end--;

    while (array < end)
    {
        const char *qwq = *array;
        *array = *end;
        *end = qwq;
        array++;
        end--;
    }
}

void reverse_matrix(const char ***matrix)
{
    // Reverse every array in the matrix
    const char ***qwq = matrix;
    while (*qwq != NULL)
    {
        reverse_array(*qwq);
        qwq++;
    }

    // Reverse the matrix
    const char ***start = matrix;
    const char ***end = matrix;
    while (*end != NULL)
        end++;
    end--;

    while (start < end)
    {
        const char **qwq = *start;
        *start = *end;
        *end = qwq;
        start++;
        end--;
    }
}

/*
int main(void)
{
    const char ***matrix = malloc(3 * sizeof(char **));
    matrix[0] = malloc(4 * sizeof(char *));
    matrix[0][0] = "Hello";
    matrix[0][1] = "World";
    matrix[0][2] = "!";
    matrix[0][3] = NULL;
    matrix[1] = malloc(3 * sizeof(char *));
    matrix[1][0] = "Goodbye";
    matrix[1][1] = "World";
    matrix[1][2] = NULL;
    matrix[2] = NULL;

    reverse_matrix(matrix);

    // Free
    free(matrix[0]);
    free(matrix[1]);
    free(matrix);

    return 0;
}*/
