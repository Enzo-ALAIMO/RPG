/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-mydefender-enzo.alaimo
** File description:
** exit.c
*/

#include "rpg.h"
#include "util.h"

void exit_game(game_t *game)
{
    set_save(game);
    sfRenderWindow_close(game->window);
}