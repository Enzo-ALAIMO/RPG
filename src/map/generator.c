/*
** EPITECH PROJECT, 2020
** Projects
** File description:
** generator.c
*/

#include "rpg.h"
#include "my.h"
#include "util.h"
#include "map.h"

static void init_grid(map_t *map)
{
    map->grid = malloc(sizeof(char *) * map->height);
    if (map->grid == NULL)
        return;
    for (int i = 0; i < map->height; ++i) {
        map->grid[i] = malloc(sizeof(char) * (map->width + 1));
        if (map->grid[i] == NULL)
            return;
        for (int j = 0; j < map->width; ++j)
            map->grid[i][j] = VOID;
        map->grid[i][map->width] = '\0';
    }
}

static sfVector2i get_direction(int direction, sfVector2i check_dir)
{
    switch (direction) {
        case 0:
            check_dir.x = 1;
            check_dir.y = 0;
            break;
        case 1:
            check_dir.x = 0;
            check_dir.y = -1;
            break;
        case 2:
            check_dir.x = -1;
            check_dir.y = 0;
            break;
        case 3:
            check_dir.x = 0;
            check_dir.y = 1;
            break;
    }
    return (check_dir);
}

static char **add_walls(map_t *map)
{
    for (int i = 0; i < MAP_HEIGHT; ++i)
        for (int j = 0; j < MAP_WIDTH; ++j)
            if (map->grid[i][j] == FLOOR && (map->grid[i - 1][j] == VOID))
                map->grid[i - 1][j] = WALL;
    return (map->grid);
}

static char **generation_iteration(map_t *map, int direction,
    sfVector2i check_dir, sfVector2i controller)
{
    for (int i = 0; i < LOOP; ++i) {
        map->grid[controller.y][controller.x] = FLOOR;
        if (get_random_int(1) == 1)
            direction = get_random_int(3);
        check_dir = get_direction(direction, check_dir);
        controller.x += check_dir.x;
        controller.y += check_dir.y;
        if (controller.x < 2 || controller.x >= map->width - 2)
            controller.x += -check_dir.x * 2;
        if (controller.y < 2 || controller.y >= map->height - 2)
            controller.y += -check_dir.y * 2;
    }
    map->grid = add_walls(map);
    return (map->grid);
}

void generate_map(map_t *map)
{
    int direction = 0;
    sfVector2i check_dir = {0, 0};
    sfVector2i controller = {MAP_WIDTH / 2, MAP_HEIGHT / 2};

    direction = get_random_int(3);
    map->width = MAP_WIDTH;
    map->height = MAP_HEIGHT;
    init_grid(map);
    map->grid = generation_iteration(map, direction, check_dir, controller);
}

