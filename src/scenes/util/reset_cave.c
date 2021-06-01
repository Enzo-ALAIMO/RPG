/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** reset_cave.c
*/

#include "rpg.h"
#include "free.h"
#include "map.h"
#include "pathfinding.h"
#include "enemy.h"

static void reset_map(scene_t *scene)
{
    free_map(scene->map);
    scene->map = create_map();
}

static void reset_pathfinding(scene_t *scene)
{
    free_a_star(&scene->in_game->a_star);
    scene->in_game->a_star = init_a_star(NULL, scene->map);
}

static void reset_enemies(scene_t *scene)
{
    for (int i = 0; i < NB_ENEMY; ++i)
        sfRectangleShape_destroy(scene->in_game->arr_enemies[i].hitbox);
    free(scene->in_game->arr_enemies);
    scene->in_game->arr_enemies = create_arr_enemies(scene->map);
}

void reset_cave(game_t *game)
{
    scene_t *scene = &game->arr_scenes[game->scene_index];

    reset_map(scene);
    reset_pathfinding(scene);
    reset_enemies(scene);
}