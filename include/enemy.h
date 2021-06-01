/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** enemy.h
*/

#ifndef ENEMY_H
#define ENEMY_H

#include "rpg.h"

static const int NB_ENEMY = 100;
static const int TILE_SIZE = 64;
static const int SLIME_HP = 50;
static const int BANDIT_HP = 50;
static const int SKELETON_HP = 50;

enum enemy_type {
    SLIME,
    BANDIT,
    SKELETON,
    NB_ENEMY_TYPE
};

enum enemy_state {
    WALK,
    SHOOT,
    DESTROY,
};

enemy_t create_enemy(char const *filepath, sfVector2f spawn_pos, sfVector3f
    params, int type);
enemy_t *create_arr_enemies(map_t *map);
void enemy_animation(enemy_t *enemy, float dt);
void draw_enemy(game_t *game, scene_t scene);
void move_enemy(scene_t scene, enemy_t *enemy);
void update_enemy(game_t *game, scene_t scene);
void reset_path(game_t *game, scene_t scene, enemy_t *enemy);
void shoot_enemy(game_t *game, scene_t *scene, enemy_t *enemy);
void update_enemy_bullets(float dt, enemy_t *enemy);
void draw_enemy_bullets(game_t *game, enemy_t *enemy);
void check_enemy_bullet_collision(game_t *game);

#endif