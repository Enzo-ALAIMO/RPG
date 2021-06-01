/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** event_settings.c
*/

#include "rpg.h"
#include "scene.h"
#include "interface.h"

static void event_buttons(button_t *arr_buttons, sfVector2f mouse_pos,
    game_t *game)
{
    check_button_one_arg(&arr_buttons[RETURN_BTN_SETT], game, mouse_pos,
        MENU_SCENE);
    check_button_one_arg(&arr_buttons[VOL_UP_BTN_SETT], game, mouse_pos, 1);
    check_button_one_arg(&arr_buttons[VOL_DOWN_BTN_SETT], game, mouse_pos, 0);
    check_button_two_arg(&arr_buttons[LOW_BTN_SETT], game, mouse_pos,
        (sfVector2i){800, 600});
    check_button_two_arg(&arr_buttons[MEDIUM_BTN_SETT], game, mouse_pos,
        (sfVector2i){1280, 720});
    check_button_two_arg(&arr_buttons[HIGH_BTN_SETT], game, mouse_pos,
        (sfVector2i){1920, 1080});
    check_button_one_arg(&arr_buttons[FPS_L_BTN_SETT], game, mouse_pos, 30);
    check_button_one_arg(&arr_buttons[FPS_M_BTN_SETT], game, mouse_pos, 60);
    check_button_one_arg(&arr_buttons[FPS_H_BTN_SETT], game, mouse_pos, 120);
}

void event_settings(game_t *game)
{
    button_t *arr_buttons = game->arr_scenes[game->scene_index].arr_buttons;
    sfVector2f mouse_pos = (sfVector2f){game->event.mouseButton.x,
        game->event.mouseButton.y};

    if (game->event.type == sfEvtMouseButtonPressed)
        if (game->event.mouseButton.button == sfMouseLeft)
            event_buttons(arr_buttons, mouse_pos, game);
}