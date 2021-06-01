/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-mydefender-enzo.alaimo
** File description:
** draw_menu.c
*/

#include "rpg.h"
#include "draw.h"

void draw_menu(game_t *game)
{
    scene_t scene = game->arr_scenes[game->scene_index];

    if (scene.background != NULL)
        sfRenderWindow_drawSprite(game->window, scene.background, NULL);
    draw_buttons(game, scene, scene.nb_buttons);
}