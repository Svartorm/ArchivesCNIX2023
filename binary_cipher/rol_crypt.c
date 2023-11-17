#include <stdio.h>

#include "binary_cipher.h"

/*
** Rotate byte by byte the data of size data_len with the key of size
** key_len.
** Rotating a byte by another means adding them together with potential
** overflow.
*/
void my_rol_crypt(void *data, size_t data_len, const void *key, size_t key_len)
{
    unsigned char *d = data;
    const unsigned char *k = key;
    unsigned char curr_bytes;
    unsigned char curr_key;

    for (size_t i = 0; i < data_len; i++)
    {
        curr_bytes = d[i];
        curr_key = k[i % key_len];

        d[i] = curr_bytes + curr_key;
    }
}
