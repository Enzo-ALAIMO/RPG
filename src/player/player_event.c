/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** player_event.c
*/

#include "rpg.h"
#include "player.h"

void player_movement_event(game_t *game)
{
    handle_input(game);
    if (!game->player.player_input.up && !game->player.player_input.down &&
        !game->player.player_input.left && !game->player.player_input.right
        && game->player.player_state == NORMAL) {
        game->player.spritesheet_start = 0;
        game->player.spritesheet_end = 200;
    } else if (game->player.player_state == NORMAL) {
        game->player.spritesheet_start = 440;
        game->player.spritesheet_end = 760;
    }
}