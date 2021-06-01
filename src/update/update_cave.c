/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** update_cave.c
*/

#include "rpg.h"
#include "player.h"
#include "particle.h"
#include "weapon.h"
#include "collision.h"
#include "interface.h"
#include "scene.h"
#include "enemy.h"
#include "map.h"

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
    float width = MAP_WIDTH * 64;
    float height = MAP_HEIGHT * 64;

    sfView_setSize(view, (sfVector2f){WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2});
    sfView_setCenter(view, (sfVector2f){
        clamp(game->player.position.x, 0 + WINDOW_WIDTH / 4,
            width - WINDOW_WIDTH / 4),
        clamp(game->player.position.y, 0 + WINDOW_HEIGHT / 4,
            height  - WINDOW_HEIGHT / 4)});
    sfRenderWindow_setView(game->window, view);
    sfView_destroy(view);
}

static void buttons_hover(game_t *game)
{
    button_t *arr_buttons = game->arr_scenes[game->scene_index].arr_buttons;
    sfVector2f mouse_pos =
        (sfVector2f){sfMouse_getPositionRenderWindow(game->window).x,
            sfMouse_getPositionRenderWindow(game->window).y};

    for (int i = 0; i < NB_BTN_CAVE; ++i)
        arr_buttons[i].draw_over = button_is_hover(&arr_buttons[i],
            mouse_pos, game);
}

static void check_win(game_t *game, scene_t scene)
{
    bool win = true;

    for (int i = 0; i < NB_ENEMY; ++i)
        if (!scene.in_game->arr_enemies[i].dead) {
            win = false;
            break;
        }
    if (win) {
        game->arr_scenes[game->scene_index].change = true;
        game->arr_scenes[game->scene_index].scene_change = HUB_SCENE;
        game->quest.end = 1;
    }
}

void update_cave(game_t *game)
{
    scene_t scene = game->arr_scenes[game->scene_index];

    buttons_hover(game);
    update_camera_view(game);
    if (scene.pause)
        return;
    check_win(game, scene);
    update_enemy(game, scene);
    check_enemy_bullet_collision(game);
    check_player_collision_with_cave_map(&game->player, scene);
    check_bullets_collisions_with_enemies(game);
    player_animation(&game->player, scene.dt);
    player_movement(game, &game->player, scene.dt);
    player_item(game, &game->player, scene.dt);
    update_bullets(game, scene.dt);
}