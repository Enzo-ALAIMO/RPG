/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** event_how_to_play.c
*/

#include "rpg.h"
#include "scene.h"
#include "interface.h"

static void buttons_actions(game_t *game)
{
    button_t *arr_buttons = game->arr_scenes[HTP_SCENE].arr_buttons;
    sfVector2f mouse_pos = (sfVector2f){game->event.mouseButton.x,
                                        game->event.mouseButton.y};

    check_button_one_arg(&arr_buttons[RETURN_BTN_HTP], game, mouse_pos,
        MENU_SCENE);
}

void event_htp(game_t *game)
{
    if (game->event.type == sfEvtMouseButtonPressed)
        if (game->event.mouseButton.button == sfMouseLeft)
            buttons_actions(game);
}