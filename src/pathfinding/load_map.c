/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** load_map.c
*/

#include "rpg.h"
#include "map.h"

static char **fill_map(char **grid, char **map, int height, int width)
{
    for (int i = 0; i < height; ++i)
        for (int j = 0; j < width; ++j)
            grid[i][j] = map[i][j];
    return (grid);
}

static char **init_grid(int height, int width, char **map)
{
    char **grid = malloc(sizeof(char *) * height);

    if (grid == NULL)
        return (NULL);
    for (int i = 0; i < height; i++) {
        grid[i] = malloc(sizeof(char) * width);
        if (grid[i] == NULL)
            return (NULL);
    }
    grid = fill_map(grid, map, height, width);
    return (grid);
}

void load_map(map_t *map, a_star_t *a_star)
{
    a_star->grid_height = map->height;
    a_star->grid_width = map->width;
    a_star->init_grid = init_grid(a_star->grid_height, a_star->grid_width,
        map->grid);
    a_star->grid = init_grid(a_star->grid_height, a_star->grid_width,
        map->grid);
}