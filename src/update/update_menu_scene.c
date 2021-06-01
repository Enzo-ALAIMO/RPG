/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-mydefender-enzo.alaimo
** File description:
** update_menu_scene.c
*/

#include "rpg.h"
#include "scene.h"
#include "interface.h"

static void buttons_hover(game_t *game)
{
    button_t *arr_buttons = game->arr_scenes[game->scene_index].arr_buttons;
    sfVector2f mouse_pos =
        (sfVector2f){sfMouse_getPositionRenderWindow(game->window).x,
        sfMouse_getPositionRenderWindow(game->window).y};

    arr_buttons[PLAY_BTN_MENU].draw_over =
        button_is_hover(&arr_buttons[PLAY_BTN_MENU], mouse_pos, game);
    arr_buttons[HTP_BTN_MENU].draw_over =
        button_is_hover(&arr_buttons[HTP_BTN_MENU], mouse_pos, game);
    arr_buttons[SETTINGS_BTN_MENU].draw_over =
        button_is_hover(&arr_buttons[SETTINGS_BTN_MENU], mouse_pos, game);
    arr_buttons[EXIT_BTN_MENU].draw_over =
        button_is_hover(&arr_buttons[EXIT_BTN_MENU], mouse_pos, game);
}

void update_menu(game_t *game)
{
    if (game->scene_index != 0)
        return;
    buttons_hover(game);
}