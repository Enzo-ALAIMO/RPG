/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-mydefender-enzo.alaimo
** File description:
** change_res.c
*/

#include "rpg.h"

void change_res(game_t *game, unsigned int x, unsigned int y)
{
    sfRenderWindow_setSize(game->window, (sfVector2u){x, y});
}