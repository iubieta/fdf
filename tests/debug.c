#include "include/fdf.h"

void print_z_values(t_map *map)
{
    for (int y = 0; y < map->height; y++)
    {
        for (int x = 0; x < map->width; x++)
        {
            printf("%d ", map->array[y][x].z);
        }
        printf("\n");
    }
}
