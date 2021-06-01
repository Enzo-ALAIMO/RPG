/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-mydefender-enzo.alaimo
** File description:
** menu.c
*/

#include "rpg.h"
#include "event.h"

void return_to_menu(game_t *game, int scene_index)
{
    game->arr_scenes[game->scene_index].change = true;
    game->arr_scenes[game->scene_index].scene_change = scene_index;
}