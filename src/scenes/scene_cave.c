/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** scene_cave.c
*/

#include "rpg.h"
#include "event.h"
#include "update.h"
#include "draw.h"
#include "parser.h"
#include "util.h"
#include "map.h"
#include "scene.h"
#include "pathfinding.h"
#include "enemy.h"

static in_game_t *create_in_game(map_t *map)
{
    in_game_t *in_game = malloc(sizeof(in_game_t));

    if (in_game == NULL)
        return (NULL);
    in_game->a_star = init_a_star(NULL, map);
    in_game->arr_enemies = create_arr_enemies(map);
    return (in_game);
}

scene_t create_scene_cave(void)
{
    scene_t scene = {0};

    scene.arr_buttons = create_button_parser("buttons_cave.txt");
    scene.arr_texts = create_text_parser("texts.txt");
    scene.spr_pause = create_sprite("./assets/in_game/pause.png",
        (sfVector2f){0, 0}, (sfVector2f){1, 1});
    scene.map = create_map();
    scene.in_game = create_in_game(scene.map);
    scene.clock_dt = sfClock_create();
    scene.event = &event_cave;
    scene.update = &update_cave;
    scene.draw = &draw_cave;
    return (scene);
}