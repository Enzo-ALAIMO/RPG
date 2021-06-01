/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** update_hub.c
*/

#include "rpg.h"
#include "player.h"
#include "particle.h"
#include "weapon.h"
#include "collision.h"
#include "shop.h"
#include "interface.h"
#include "scene.h"
#include "npc.h"

static float clamp(float value, float min, float max)
{
    if (value <= min)
        return (min);
    else if (value >= max)
        return (max);
    return (value);
}

static void update_camera_view(game_t *game)
{
    sfView *view = sfView_create();

    sfView_setSize(view, (sfVector2f){WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2});
    sfView_setCenter(view, (sfVector2f){
        clamp(game->player.position.x, 0 + WINDOW_WIDTH / 4,
            WINDOW_WIDTH - WINDOW_WIDTH / 4),
        clamp(game->player.position.y, 0 + WINDOW_HEIGHT / 4,
            WINDOW_HEIGHT  - WINDOW_HEIGHT / 4)});
    sfRenderWindow_setView(game->window, view);
    sfView_destroy(view);
}

static void buttons_hover(game_t *game)
{
    button_t *arr_buttons = game->arr_scenes[game->scene_index].arr_buttons;
    sfVector2f mouse_pos =
        (sfVector2f){sfMouse_getPositionRenderWindow(game->window).x,
        sfMouse_getPositionRenderWindow(game->window).y};

    for (int i = 0; i < NB_BTN_IN_GAME; ++i) {
        arr_buttons[i].draw_over = button_is_hover(&arr_buttons[i],
            mouse_pos, game);
    }
}

static void check_enter_cave(game_t *game, scene_t scene)
{
    if (collision_between_rectangle(game->player.hitbox,
        scene.in_game->cave_entry)) {
        game->arr_scenes[game->scene_index].change = true;
        game->arr_scenes[game->scene_index].scene_change = CAVE_SCENE;
    }
}

void update_hub(game_t *game)
{
    scene_t scene = game->arr_scenes[game->scene_index];

    check_reward_quest(game);
    check_player_collision_with_scene_hitbox(&game->player, scene.in_game);
    buttons_hover(game);
    update_camera_view(game);
    if (scene.pause)
        return;
    update_npc(scene);
    check_enter_cave(game, scene);
    check_player_collision_with_scene_hitbox(&game->player, scene.in_game);
    update_particle(&scene.in_game->particle_spawner, scene.dt);
    player_animation(&game->player, scene.dt);
    shoper_animation(&game->seller, scene.dt);
    player_movement(game, &game->player, scene.dt);
    player_item(game, &game->player, scene.dt);
    update_bullets(game, scene.dt);
}