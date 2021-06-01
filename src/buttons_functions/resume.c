/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-mydefender-enzo.alaimo
** File description:
** pause.c
*/

#include "rpg.h"
#include "event.h"

void resume_game(game_t *game)
{
    reset_event_pause(game);
    sfClock_restart(game->arr_scenes[game->scene_index].clock_dt);
}