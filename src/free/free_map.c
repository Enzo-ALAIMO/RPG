/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** free_map.c
*/

#include <stdlib.h>
#include "rpg.h"
#include "scene.h"

void free_map(map_t *map)
{
    for (int i = 0; i < map->nb_hitbox; ++i)
        sfRectangleShape_destroy(map->hitbox[i]);
    free(map->hitbox);
    for (int i = 0; i < NB_SPRITES; ++i)
        sfSprite_destroy(map->arr_sprites[i]);
    free(map->arr_sprites);
    for (int i = 0; i < map->height; ++i)
        free(map->grid[i]);
    free(map->grid);
    free(map);
}