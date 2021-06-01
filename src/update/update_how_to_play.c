/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** update_how_to_play.c
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

    arr_buttons[RETURN_BTN_HTP].draw_over =
        button_is_hover(&arr_buttons[PLAY_BTN_MENU], mouse_pos, game);
}

void update_htp(game_t *game)
{
    if (game->scene_index != HTP_SCENE)
        return;
    buttons_hover(game);
}