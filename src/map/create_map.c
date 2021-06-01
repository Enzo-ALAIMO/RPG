/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** create_map.c
*/

#include "rpg.h"
#include "parser.h"
#include "util.h"
#include "map.h"
#include "scene.h"

static int get_nb_hitbox(map_t *map)
{
    int cpt = 0;

    for (int i = 1; i < map->height - 1; ++i)
        for (int j = 1; j < map->width - 1; ++j) {
            if (map->grid[i][j] == FLOOR && (map->grid[i - 1][j] == WALL ||
                map->grid[i - 1][j] == VOID))
                ++cpt;
            if (map->grid[i][j] == FLOOR && (map->grid[i + 1][j] == WALL ||
                map->grid[i + 1][j] == VOID))
                ++cpt;
            if (map->grid[i][j] == FLOOR && (map->grid[i][j - 1] == WALL ||
                map->grid[i][j - 1] == VOID))
                ++cpt;
            if (map->grid[i][j] == FLOOR && (map->grid[i][j + 1] == WALL ||
                map->grid[i][j + 1] == VOID))
                ++cpt;
        }
    return (cpt);
}

static void create_hitboxes(map_t *map, int index)
{
    for (int i = 1; i < map->height - 1; ++i) {
        for (int j = 1; j < map->width - 1; ++j) {
            if (map->grid[i][j] == FLOOR && (map->grid[i - 1][j] == WALL ||
                map->grid[i - 1][j] == VOID))
                map->hitbox[index++] = create_hitbox((sfVector2f){j * 64,
                    (i - 1) * 64}, (sfVector2f){64, 64});
            if (map->grid[i][j] == FLOOR && (map->grid[i + 1][j] == WALL ||
                map->grid[i + 1][j] == VOID))
                map->hitbox[index++] = create_hitbox((sfVector2f){j * 64,
                    (i + 1) * 64}, (sfVector2f){64, 64});
            if (map->grid[i][j] == FLOOR && (map->grid[i][j - 1] == WALL ||
                map->grid[i][j - 1] == VOID))
                map->hitbox[index++] = create_hitbox((sfVector2f){(j - 1) * 64,
                    i * 64}, (sfVector2f){64, 64});
            if (map->grid[i][j] == FLOOR && (map->grid[i][j + 1] == WALL ||
                map->grid[i][j + 1] == VOID))
                map->hitbox[index++] = create_hitbox((sfVector2f){(j + 1) * 64,
                    i * 64}, (sfVector2f){64, 64});
        }
    }
}

map_t *create_map(void)
{
    map_t *map = malloc(sizeof(map_t));
    int index = 0;

    if (map == NULL)
        return (NULL);
    generate_map(map);
    map->nb_hitbox = get_nb_hitbox(map);
    map->hitbox = malloc(sizeof(*map->hitbox) * map->nb_hitbox);
    map->arr_sprites = malloc(sizeof(*map->arr_sprites) * NB_SPRITES);
    if (map->arr_sprites == NULL || map->hitbox == NULL)
        return (&(map_t){0});
    map->arr_sprites[S_FLOOR] = create_sprite("./assets/map/floor.png",
        (sfVector2f){0, 0}, (sfVector2f){1, 1});
    map->arr_sprites[S_WALL] = create_sprite("./assets/map/wall.png",
        (sfVector2f){0, 0}, (sfVector2f){1, 1});
    map->arr_sprites[S_VOID] = create_sprite("./assets/map/void.png",
        (sfVector2f){0, 0}, (sfVector2f){1, 1});
    create_hitboxes(map, index);
    return (map);
}