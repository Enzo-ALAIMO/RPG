/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** bullet_collision_with_enemies.c
*/

#include "rpg.h"
#include "weapon.h"
#include "enemy.h"
#include "collision.h"
#include "sound.h"

static void destroy_enemy(game_t *game, player_t *player, enemy_t *enemy)
{
    if (enemy->enemy_type == BANDIT)
        game->quest.bandits++;
    else if (enemy->enemy_type == SKELETON)
        game->quest.skeletons++;
    if (enemy->boss)
        game->quest.boss++;
    player->gold += enemy->gold;
    player->xp += enemy->xp;
    enemy->speed = 0;
    enemy->enemy_state = DESTROY;
    enemy->time_between_animation = 0.1;
    enemy->rect.left = 0;
    enemy->spritesheet_start = 0;
    enemy->spritesheet_end = 520;
}

static void check_collision(game_t *game, scene_t *scene, int i, int j)
{
    bullet_t *bullet = &game->player.weapon.arr_bullets[i];
    enemy_t *enemy = &scene->in_game->arr_enemies[j];

    if (!game->player.weapon.arr_bullets[i].is_used || enemy->enemy_state ==
        DESTROY)
        return;
    if (enemy->enemy_state != DESTROY &&
        collision_between_rectangle(bullet->hitbox, enemy->hitbox)) {
        bullet->is_used = false;
        enemy->hp -= bullet->damage;
        sfSound_play(game->sounds[S_HIT_E]);
        if (enemy->hp <= 0) {
            destroy_enemy(game, &game->player, enemy);
            sfSound_play(game->sounds[S_DEAD_P]);
        }
    }
}

void check_bullets_collisions_with_enemies(game_t *game)
{
    scene_t *scene = &game->arr_scenes[game->scene_index];

    for (int i = 0; i < NB_BULLETS; ++i) {
        if (!game->player.weapon.arr_bullets[i].is_used)
            continue;
        for (int j = 0; j < NB_ENEMY; ++j)
            check_collision(game, scene, i, j);
    }
}