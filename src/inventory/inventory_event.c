/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** inventory_event.c
*/

#include "rpg.h"
#include "scene.h"
#include "interface.h"

static void buttons_actions(game_t *game)
{
    button_t *arr_buttons = game->arr_scenes[game->scene_index].arr_buttons;
    sfVector2f mouse_pos = (sfVector2f){game->event.mouseButton.x,
        game->event.mouseButton.y};

    if (game->scene_index == HUB_SCENE)
        for (int i = BTN_I_SLOT_1; i <= BTN_I_SLOT_13; ++i)
            check_button_one_arg(&arr_buttons[i], game, mouse_pos,
                i - BTN_I_SLOT_1);
    else if (game->scene_index == CAVE_SCENE)
        for (int i = BTN_C_I_SLOT_1; i <= BTN_C_I_SLOT_13; ++i)
            check_button_one_arg(&arr_buttons[i], game, mouse_pos,
                i - BTN_C_I_SLOT_1);
}

static void active_or_not_button(bool *value)
{
    *value = !(*value);
}

void trigger_inventory(game_t *game)
{
    scene_t *scene = &game->arr_scenes[game->scene_index];

    toggle_texts(game, scene);
    active_or_not_button(&game->player.inventory.open);
    if (game->scene_index == HUB_SCENE) {
        for (int i = BTN_I_SLOT_1; i <= BTN_I_SLOT_13; ++i)
            active_or_not_button(&scene->arr_buttons[i].draw);
        active_or_not_button(&scene->arr_buttons[BTN_QUEST].draw);
    } else if (game->scene_index == CAVE_SCENE) {
        for (int i = BTN_C_I_SLOT_1; i <= BTN_C_I_SLOT_13; ++i)
            active_or_not_button(&scene->arr_buttons[i].draw);
        active_or_not_button(&scene->arr_buttons[BTN_C_QUEST].draw);
    }
}

void inventory_event(game_t *game)
{
    if (game->event.type == sfEvtMouseButtonPressed)
        if (game->event.mouseButton.button == sfMouseLeft)
            buttons_actions(game);
    if (game->event.type == sfEvtKeyReleased)
        if (game->event.key.code == sfKeyE)
            trigger_inventory(game);
}