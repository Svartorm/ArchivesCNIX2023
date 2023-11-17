#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 300

int mod(int a, int b)
{
    const int result = a % b;
    return result >= 0 ? result : result + b;
}

void rot(char *buf, int key)
{
    while (*buf)
    {
        // Lower case check
        if (*buf >= 'a' && *buf <= 'z')
            *buf = mod(((*buf - 'a') + key), 26) + 'a';

        // Upper case check
        if (*buf >= 'A' && *buf <= 'Z')
            *buf = mod(((*buf - 'A') + key), 26) + 'A';

        // Number check
        if (*buf >= '0' && *buf <= '9')
            *buf = mod(((*buf - '0') + key), 10) + '0';

        buf++;
    }
}

int main(int argc, char **argv)
{
    // Checking errors
    if (argc != 2)
        return 0; // Do nothing

    // Vars
    char buffer[BUFFER_SIZE + 1];
    int cursor;
    int key = atoi(argv[1]);

    // Read bytes
    cursor = -1;
    while (cursor != 0) // Different from EOF
    {
        cursor = read(0, buffer, BUFFER_SIZE);

        if (cursor == -1) // If read error
            return 1;

        buffer[cursor] = 0;

        rot(buffer, key); // write the rotation on the stdout

        // Write on stdout
        if (write(1, buffer, cursor) == -1)
            return 1;
    }

    return 0;
}
