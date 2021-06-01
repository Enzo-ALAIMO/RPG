/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** event_hub.c
*/

#include "rpg.h"
#include "player.h"
#include "interface.h"
#include "scene.h"
#include "event.h"
#include "inventory.h"

static void buttons_actions(game_t *game)
{
    button_t *arr_buttons = game->arr_scenes[game->scene_index].arr_buttons;
    sfVector2f mouse_pos = (sfVector2f){game->event.mouseButton.x,
        game->event.mouseButton.y};

    check_button_zero_arg(&arr_buttons[BTN_P_RESUME], game, mouse_pos);
    check_button_one_arg(&arr_buttons[BTN_P_MENU], game, mouse_pos, MENU_SCENE);
    check_button_zero_arg(&arr_buttons[BTN_P_EXIT], game, mouse_pos);
    check_button_zero_arg(&arr_buttons[BTN_GUN_ONE], game, mouse_pos);
    check_button_zero_arg(&arr_buttons[BTN_GUN_TWO], game, mouse_pos);
    check_button_zero_arg(&arr_buttons[BTN_LIFE], game, mouse_pos);
    check_button_zero_arg(&arr_buttons[BTN_POTION], game, mouse_pos);
    check_button_zero_arg(&arr_buttons[BTN_QUEST], game, mouse_pos);
}

void event_hub(game_t *game)
{
    if (game->event.type == sfEvtMouseButtonPressed)
        if (game->event.mouseButton.button == sfMouseLeft)
            buttons_actions(game);
    event_pause(game);
    if (game->arr_scenes[game->scene_index].pause)
        return;
    inventory_event(game);
    player_movement_event(game);
}