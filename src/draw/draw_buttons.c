/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** draw_buttons.c
*/

#include <stddef.h>
#include "rpg.h"

void draw_buttons(game_t *game, scene_t scene, int nb_buttons)
{
    button_t *button = NULL;

    for (int i = 0; i < nb_buttons; i++) {
        button = &scene.arr_buttons[i];
        if (button->sprite == NULL || !button->draw)
            continue;
        sfRenderWindow_drawSprite(game->window, button->sprite, NULL);
        if (button->draw_over && !button->draw_click)
            sfRenderWindow_drawSprite(game->window, button->over_sprite, NULL);
        if (button->draw_over && button->draw_click)
            sfRenderWindow_drawSprite(game->window, button->click_sprite, NULL);
    }
}