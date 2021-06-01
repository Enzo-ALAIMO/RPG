/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-mydefender-enzo.alaimo
** File description:
** change_scene.c
*/

#include "rpg.h"
#include "event.h"
#include "scene.h"
#include "util.h"
#include "inventory.h"
#include "sound.h"

static void place_player_cave(game_t *game)
{
    scene_t scene = game->arr_scenes[game->scene_index];
    sfVector2i rand_pos = {0, 0};

    while (true) {
        rand_pos = (sfVector2i){get_random_int(scene.map->width - 2),
            get_random_int(scene.map->height - 2)};
        if (scene.map->grid[rand_pos.y][rand_pos.x] == 'F')
            break;
    }
    game->player.position = (sfVector2f){(rand_pos.x * 64) + 10, (rand_pos.y *
        64) + 10};
    sfRectangleShape_setPosition(game->player.hitbox, game->player.position);
}

static void place_player_hub(game_t *game)
{
    game->player.position = (sfVector2f){960, 700};
    sfRectangleShape_setPosition(game->player.hitbox, game->player.position);
}

static void toggle_sound(game_t  *game, int index, int play)
{
    if (play) {
        sfSound_setLoop(game->sounds[index], true);
        sfSound_play(game->sounds[index]);
    } else {
        sfSound_stop(game->sounds[index]);
    }
}

static void play_bg_music(game_t *game, int scene_index)
{
    if (scene_index == HUB_SCENE) {
        toggle_sound(game, S_BG_HUB, 1);
        toggle_sound(game, S_BG_MENU, 0);
        toggle_sound(game, S_BG_CAVE, 0);
    }
    if (scene_index == CAVE_SCENE) {
        toggle_sound(game, S_BG_HUB, 0);
        toggle_sound(game, S_BG_MENU, 0);
        toggle_sound(game, S_BG_CAVE, 1);
    }
    if (scene_index == MENU_SCENE) {
        toggle_sound(game, S_BG_HUB, 0);
        toggle_sound(game, S_BG_MENU, 1);
        toggle_sound(game, S_BG_CAVE, 0);
    }
}

void change_scene(game_t *game, int index)
{
    if (game->arr_scenes[game->scene_index].in_game != NULL) {
        game->arr_scenes[game->scene_index].change = false;
        if (game->arr_scenes[game->scene_index].pause)
            reset_event_pause(game);
        if (game->player.inventory.open)
            trigger_inventory(game);
    }
    play_bg_music(game, index);
    game->scene_index = index;
    sfClock_restart(game->arr_scenes[game->scene_index].clock_dt);
    if (index == HUB_SCENE)
        place_player_hub(game);
    else if (index == CAVE_SCENE) {
        reset_cave(game);
        place_player_cave(game);
    }
}