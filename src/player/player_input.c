/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** player_input.c
*/

#include "rpg.h"

static void handle_key_pressed(game_t *game)
{
    switch (game->event.key.code) {
        case sfKeyZ:
            game->player.player_input.up = true;
            break;
        case sfKeyS:
            game->player.player_input.down = true;
            break;
        case sfKeyQ:
            game->player.player_input.left = true;
            break;
        case sfKeyD:
            game->player.player_input.right = true;
            break;
        default:
            break;
    }
}

static void handle_key_released(game_t *game)
{
    switch (game->event.key.code) {
        case sfKeyZ:
            game->player.player_input.up = false;
            break;
        case sfKeyS:
            game->player.player_input.down = false;
            break;
        case sfKeyQ:
            game->player.player_input.left = false;
            break;
        case sfKeyD:
            game->player.player_input.right = false;
            break;
        case sfKeySpace:
            game->player.player_input.roll = true;
            break;
        default:
            break;
    }
}

static void handle_mouse(game_t *game)
{
    if (game->event.type == sfEvtMouseButtonPressed
        && game->event.mouseButton.button == sfMouseLeft)
        game->player.player_input.use_item = true;
    else if (game->event.type == sfEvtMouseButtonReleased
        && game->event.mouseButton.button == sfMouseLeft)
        game->player.player_input.use_item = false;
}

void handle_input(game_t *game)
{
    if (game->event.type == sfEvtKeyPressed)
        handle_key_pressed(game);
    else if (game->event.type == sfEvtKeyReleased)
        handle_key_released(game);
    handle_mouse(game);
}