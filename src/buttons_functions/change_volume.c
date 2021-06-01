/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-mydefender-enzo.alaimo
** File description:
** change_volume.c
*/

#include "rpg.h"
#include "sound.h"

void change_volume(game_t *game, int value)
{
    if (value == 0 && game->volume >= 20)
        game->volume -= 20;
    else if (value == 1 && game->volume <= 80)
        game->volume += 20;
    for (int i = 0; i < NB_SOUND; i++)
        sfSound_setVolume(game->sounds[i], game->volume);
}