/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** draw_how_to_play.c
*/

#include "rpg.h"
#include "draw.h"

void draw_htp(game_t *game)
{
    scene_t scene = game->arr_scenes[game->scene_index];

    if (scene.background != NULL)
        sfRenderWindow_drawSprite(game->window, scene.background, NULL);
    draw_buttons(game, scene, scene.nb_buttons);
}