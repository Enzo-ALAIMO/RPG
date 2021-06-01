/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-mydefender-enzo.alaimo
** File description:
** event_menu.c
*/

#include "rpg.h"
#include "scene.h"
#include "interface.h"

static void buttons_actions(game_t *game, button_t *arr_buttons,
    sfVector2f mouse_pos)
{
    check_button_one_arg(&arr_buttons[PLAY_BTN_MENU], game, mouse_pos,
        HUB_SCENE);
    check_button_one_arg(&arr_buttons[HTP_BTN_MENU], game, mouse_pos,
        HTP_SCENE);
    check_button_one_arg(&arr_buttons[SETTINGS_BTN_MENU], game, mouse_pos,
        SETTINGS_SCENE);
    check_button_zero_arg(&arr_buttons[EXIT_BTN_MENU], game, mouse_pos);
}

void event_menu(game_t *game)
{
    button_t *arr_buttons = game->arr_scenes[MENU_SCENE].arr_buttons;
    sfVector2f mouse_pos = (sfVector2f){game->event.mouseButton.x,
        game->event.mouseButton.y};

    if (game->event.type == sfEvtMouseButtonPressed)
        if (game->event.mouseButton.button == sfMouseLeft)
            buttons_actions(game, arr_buttons, mouse_pos);
}