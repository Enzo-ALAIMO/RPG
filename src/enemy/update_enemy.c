/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** update_npc.c
*/

#include "rpg.h"
#include "pathfinding.h"
#include "util.h"
#include "enemy.h"

static void check_range_shoot(player_t *player, enemy_t *enemy)
{
    int check = sqrt(pow((player->position.x - enemy->pos.x), 2) + pow(
        (player->position.y - enemy->pos.y), 2));

    if (enemy->enemy_type == SLIME || enemy->enemy_state == DESTROY)
        return;
    if (check <= enemy->range)
        enemy->enemy_state = SHOOT;
    else
        enemy->enemy_state = WALK;
}

static void update(game_t *game, enemy_t *enemy, scene_t scene)
{
    check_range_shoot(&game->player, enemy);
    if (enemy->enemy_type != SLIME)
        update_enemy_bullets(scene.dt, enemy);
    switch (enemy->enemy_state) {
        case WALK:
            if (enemy->index_path == enemy->len_path)
                reset_path(game, scene, enemy);
            else
                move_enemy(scene, enemy);
            break;
        case SHOOT:
            shoot_enemy(game, &scene, enemy);
            break;
        case DESTROY:
            break;
    }
    enemy_animation(enemy, scene.dt);
}

void update_enemy(game_t *game, scene_t scene)
{
    enemy_t *enemy = NULL;

    for (int i = 0; i < NB_ENEMY; ++i) {
        enemy = &scene.in_game->arr_enemies[i];
        update(game, enemy, scene);
    }
}