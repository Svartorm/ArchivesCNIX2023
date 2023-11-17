#include <ctype.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    // Check args
    if (argc != 2)
    {
        write(2, "Invalid number of arguments\n", 28);
        return 1;
    }

    // Open the file
    int fd = open(argv[1], O_RDONLY);

    if (fd == -1)
    {
        write(2, "Could not open file\n", 20);
        return 1;
    }

    // We go to the end of our file
    size_t cursor = lseek(fd, 0, SEEK_END);

    if (cursor <= 1)
    {
        write(2, "File is not long enough\n", 24);
        return 1;
    }

    cursor = lseek(fd, -1, SEEK_CUR);

    // Vars
    char c;
    char stamp[3];
    int i = 0;

    while (cursor > 0 && i < 2)
    {
        // Read the file
        int r = read(fd, &c, 1);
        if (r == -1)
            return 2;

        if (isspace(c) == 0) // c is not a space character
        {
            stamp[-1 * (i - 1)] = c; // Put at stamp[1] if i = 0, stamp[0] else
            i++;
        }

        cursor = lseek(fd, -2, SEEK_CUR);
    }

    if (i != 2 && cursor == 0)
    {
        write(2, "File is not long enough\n", 24);
        return 1;
    }

    stamp[2] = '\n';
    write(1, stamp, 3);

    return 0;
}
