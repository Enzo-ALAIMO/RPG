/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** update_settings.c
*/

#include "rpg.h"
#include "scene.h"
#include "interface.h"

static void buttons_hover(game_t *game, button_t *arr_buttons,
    sfVector2f mouse_pos)
{
    arr_buttons[RETURN_BTN_SETT].draw_over =
        button_is_hover(&arr_buttons[RETURN_BTN_SETT], mouse_pos, game);
    arr_buttons[VOL_UP_BTN_SETT].draw_over =
        button_is_hover(&arr_buttons[VOL_UP_BTN_SETT], mouse_pos, game);
    arr_buttons[VOL_DOWN_BTN_SETT].draw_over =
        button_is_hover(&arr_buttons[VOL_DOWN_BTN_SETT], mouse_pos, game);
    arr_buttons[LOW_BTN_SETT].draw_over =
        button_is_hover(&arr_buttons[LOW_BTN_SETT], mouse_pos, game);
    arr_buttons[MEDIUM_BTN_SETT].draw_over =
        button_is_hover(&arr_buttons[MEDIUM_BTN_SETT], mouse_pos, game);
    arr_buttons[HIGH_BTN_SETT].draw_over =
        button_is_hover(&arr_buttons[HIGH_BTN_SETT], mouse_pos, game);
    arr_buttons[FPS_L_BTN_SETT].draw_over =
        button_is_hover(&arr_buttons[FPS_L_BTN_SETT], mouse_pos, game);
    arr_buttons[FPS_M_BTN_SETT].draw_over =
        button_is_hover(&arr_buttons[FPS_M_BTN_SETT], mouse_pos, game);
    arr_buttons[FPS_H_BTN_SETT].draw_over =
        button_is_hover(&arr_buttons[FPS_H_BTN_SETT], mouse_pos, game);
}

void update_settings(game_t *game)
{
    button_t *arr_buttons = game->arr_scenes[game->scene_index].arr_buttons;
    sfVector2f mouse_pos =
        (sfVector2f){sfMouse_getPositionRenderWindow(game->window).x,
        sfMouse_getPositionRenderWindow(game->window).y};

    if (game->scene_index != SETTINGS_SCENE)
        return;
    buttons_hover(game, arr_buttons, mouse_pos);
}