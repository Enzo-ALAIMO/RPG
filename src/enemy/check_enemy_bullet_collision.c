/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** check_enemy_bullet_collision.c
*/

#include "rpg.h"
#include "weapon.h"
#include "collision.h"
#include "scene.h"
#include "enemy.h"
#include "sound.h"

static void check_collision(game_t *game, enemy_t *enemy, int j)
{
    bullet_t *bullet = &enemy->weapon.arr_bullets[j];
    player_t *player = &game->player;

    if (!bullet->is_used)
        return;
    if (collision_between_rectangle(bullet->hitbox, player->hitbox)) {
        bullet->is_used = false;
        player->health -= bullet->damage;
        sfSound_play(game->sounds[S_HIT_P]);
        if (player->health <= 0) {
            sfSound_play(game->sounds[S_DEAD_P]);
            game->arr_scenes[game->scene_index].change = true;
            game->arr_scenes[game->scene_index].scene_change = HUB_SCENE;
            player->health = 100;
        }
    }
}

static void check_collision_slime(game_t *game, enemy_t *enemy)
{
    if (collision_between_rectangle(game->player.hitbox, enemy->hitbox)
        && !enemy->already_hit_player) {
        enemy->already_hit_player = true;
        game->player.health -= 10;
        sfSound_play(game->sounds[S_HIT_P]);
        if (game->player.health <= 0) {
            sfSound_play(game->sounds[S_DEAD_P]);
            game->arr_scenes[game->scene_index].change = true;
            game->arr_scenes[game->scene_index].scene_change = HUB_SCENE;
            game->player.health = 100;
        }
    } else if (!collision_between_rectangle(game->player.hitbox, enemy->hitbox))
        enemy->already_hit_player = false;
}

void check_enemy_bullet_collision(game_t *game)
{
    scene_t *scene = &game->arr_scenes[game->scene_index];
    enemy_t *enemy = NULL;

    for (int i = 0; i < NB_ENEMY; ++i) {
        enemy = &scene->in_game->arr_enemies[i];
        if (enemy->dead)
            continue;
        if (enemy->enemy_type == SLIME) {
            check_collision_slime(game, enemy);
            continue;
        }
        for (int j = 0; j < NB_BULLETS; ++j) {
            if (!enemy->weapon.arr_bullets[j].is_used)
                continue;
            check_collision(game, enemy, j);
        }
    }
}