#include <stddef.h>
#include <stdio.h>

void mat_mult(int **mat1, int **mat2, size_t *matrices_size, int **out)
{
    for (size_t i = 0; i < matrices_size[0]; i++)
    {
        for (size_t u = 0; u < matrices_size[2]; u++)
        {
            int cell = 0;
            for (size_t k = 0; k < matrices_size[1]; k++)
            {
                cell += mat1[i][k] * mat2[k][u];
            }
            out[i][u] = cell;
        }
    }
}
