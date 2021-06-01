/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-mydefender-enzo.alaimo
** File description:
** change_fps.c
*/

#include "rpg.h"

void change_fps(game_t *game, unsigned int fps)
{
    sfRenderWindow_setFramerateLimit(game->window, fps);
}