#include <stdio.h>
#include <stdlib.h>

void swim(char **map, int i, int u, char **visited)
{
    visited[i][u] = 1;
    if (map[i - 1][u] == '.' && visited[(i - 1)][u] == 0)
        swim(map, i - 1, u, visited);
    if (map[i + 1][u] == '.' && visited[(i + 1)][u] == 0)
        swim(map, i + 1, u, visited);
    if (map[i][u - 1] == '.' && visited[i][u - 1] == 0)
        swim(map, i, u - 1, visited);
    if (map[i][u + 1] == '.' && visited[i][u + 1] == 0)
        swim(map, i, u + 1, visited);
}

int lakes(char **map, int width, int height)
{
    int lake = 0;
    char **visited = malloc(height * sizeof(char *));
    for (int i = 0; i < height; i++)
    {
        visited[i] = malloc(width * sizeof(char));
        for (int u = 0; u < width; u++)
            visited[i][u] = 0;
    }

    for (int i = 1; i < height - 1; i++)
    {
        for (int u = 1; u < width - 1; u++)
        {
            if (map[i][u] == '.' && visited[i][u] == 0)
            {
                swim(map, i, u, visited);
                lake++;
            }
        }
    }

    for (int i = 0; i < height; i++)
        free(visited[i]);
    free(visited);
    return lake;
}
/*
static inline void free_all(char **map, int index)
{
    for (int i = 0; i < index; i++)
        free(map[i]);

    free(map);
}

int main(int argc, char **argv)
{
    char **map;
    FILE *f;
    int x;
    int y;

    printf("checking args file");

    if (argc != 2)
        return 1;

    printf("openning file");

    f = fopen(argv[1], "r");
    fscanf(f, "%d %d\n", &x, &y);
    map = malloc(sizeof(char *) * y);
    if (!map)
        return 1;

    for (int i = 0; i < y; i++)
    {
        map[i] = malloc(sizeof(char) * x);
        if (!map[i])
        {
            free_all(map, i);
            return 1;
        }
        for (int j = 0; j < x; j++)
            map[i][j] = fgetc(f);
        fgetc(f);
    }
    printf("%d\n", lakes(map, x, y));
    free_all(map, y);
    fclose(f);
    return 0;
}
*/
// when you find new water cell
// |--> visit all adj water cell
// |--> add 1 to lake_count
