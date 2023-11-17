#include <stdio.h>

void apply_lut(unsigned char mat[4][4], const unsigned char lut[256])
{
    for (int i = 0; i < 4; i++)
    {
        for (int u = 0; u < 4; u++)
        {
            mat[i][u] = lut[mat[i][u]];
        }
    }
}
