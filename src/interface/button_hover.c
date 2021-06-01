/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** button_hover.c
*/

#include "rpg.h"
#include "interface.h"

void check_button_zero_arg(button_t *button, game_t *game, sfVector2f
mouse_pos)
{
    if (button_is_hover(button, mouse_pos, game)) {
        button->draw_click = true;
        button->on_click(game);
    } else
        button->draw_click = false;
}

void check_button_one_arg(button_t *button, game_t *game, sfVector2f
    mouse_pos, int arg)
{
    if (button_is_hover(button, mouse_pos, game)) {
        button->draw_click = true;
        button->on_click(game, arg);
    } else
        button->draw_click = false;
}

void check_button_two_arg(button_t *button, game_t *game, sfVector2f
    mouse_pos, sfVector2i args)
{
    if (button_is_hover(button, mouse_pos, game)) {
        button->draw_click = true;
        button->on_click(game, args.x, args.y);
    } else
        button->draw_click = false;
}