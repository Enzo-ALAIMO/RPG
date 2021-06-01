/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** event_pause.c
*/

#include "rpg.h"
#include "scene.h"

static void active_or_not_button(button_t *button)
{
    button->draw = !button->draw;
}

void reset_event_pause(game_t *game)
{
    scene_t *scene = &game->arr_scenes[game->scene_index];

    scene->pause = !scene->pause;
    active_or_not_button(&scene->arr_buttons[BTN_P_RESUME]);
    active_or_not_button(&scene->arr_buttons[BTN_P_MENU]);
    active_or_not_button(&scene->arr_buttons[BTN_P_EXIT]);
}

void event_pause(game_t *game)
{
    scene_t *scene = &game->arr_scenes[game->scene_index];

    if (game->event.type == sfEvtKeyReleased)
        if (game->event.key.code == sfKeyEscape) {
            scene->pause = !scene->pause;
            active_or_not_button(&scene->arr_buttons[BTN_P_RESUME]);
            active_or_not_button(&scene->arr_buttons[BTN_P_MENU]);
            active_or_not_button(&scene->arr_buttons[BTN_P_EXIT]);
            sfClock_restart(scene->clock_dt);
        }
}