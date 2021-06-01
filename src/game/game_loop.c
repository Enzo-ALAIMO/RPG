/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-mydefender-enzo.alaimo
** File description:
** game_loop.c
*/

#include <SFML/Graphics.h>
#include "rpg.h"
#include "free.h"
#include "buttons_functions.h"
#include "scene.h"

static void game_event(game_t *game, scene_t current_scene)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (current_scene.event != NULL)
            current_scene.event(game);
    }
}

static void update(game_t *game, scene_t current_scene)
{
    if (current_scene.update != NULL)
        current_scene.update(game);
}

static void draw(game_t *game, scene_t current_scene)
{
    sfRenderWindow_clear(game->window, sfBlack);
    if (current_scene.draw != NULL)
        current_scene.draw(game);
    sfRenderWindow_display(game->window);
}

void game_loop(game_t *game)
{
    scene_t current_scene;

    while (sfRenderWindow_isOpen(game->window)) {
        current_scene = game->arr_scenes[game->scene_index];
        game->arr_scenes[game->scene_index].dt = sfTime_asSeconds(
            sfClock_restart(game->arr_scenes[game->scene_index].clock_dt));
        game_event(game, current_scene);
        if (game->arr_scenes[game->scene_index].change) {
            change_scene(game, current_scene.scene_change);
            continue;
        }
        update(game, current_scene);
        draw(game, current_scene);
    }
}