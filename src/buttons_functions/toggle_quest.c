/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** toggle_quest.c
*/

#include "rpg.h"
#include "scene.h"

void toggle_quest(game_t *game)
{
    game->quest.open = !game->quest.open;
    game->arr_scenes[game->scene_index].arr_texts[T_BANDITS].draw =
        !game->arr_scenes[game->scene_index].arr_texts[T_BANDITS].draw;
    game->arr_scenes[game->scene_index].arr_texts[T_SKELETONS].draw =
        !game->arr_scenes[game->scene_index].arr_texts[T_SKELETONS].draw;
    game->arr_scenes[game->scene_index].arr_texts[T_BOSS].draw =
        !game->arr_scenes[game->scene_index].arr_texts[T_BOSS].draw;
    game->arr_scenes[game->scene_index].arr_texts[T_END].draw =
        !game->arr_scenes[game->scene_index].arr_texts[T_END].draw;
}