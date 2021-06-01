/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-mydefender-enzo.alaimo
** File description:
** free_in_game.c
*/

#include <stdlib.h>
#include "rpg.h"

void free_enemy(in_game_t *in_game)
{
    for (int i = 0; i < in_game->nb_enemies; i++) {
        sfRectangleShape_destroy(in_game->arr_enemies[i].hitbox);
        sfSprite_destroy(in_game->arr_enemies[i].sprite);
    }
    free(in_game->arr_enemies);
}

void free_turret(in_game_t *in_game)
{
    for (int i = 0; i < in_game->nb_turrets; i++)
        continue;
    free(in_game->arr_turret);
}

void free_in_game(in_game_t *in_game)
{
    sfSprite_destroy(in_game->hud);
    free_enemy(in_game);
    free_turret(in_game);
    free(in_game);
}