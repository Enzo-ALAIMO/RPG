/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-mydefender-enzo.alaimo
** File description:
** free_game.c
*/

#include <stdlib.h>
#include "rpg.h"
#include "scene.h"
#include "free.h"

void free_game(game_t *game)
{
    if (game->arr_scenes != NULL) {
        for (int i = 0; i < NB_SCENES; i++)
            free_scene(game->arr_scenes[i]);
        free(game->arr_scenes);
    }
}