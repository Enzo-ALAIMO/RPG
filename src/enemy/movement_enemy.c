/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** movement_enemy.c
*/

#include "rpg.h"
#include "enemy.h"

static void move(enemy_t *enemy, float dt, int x_or_y, int dir)
{
    if (x_or_y == 0) {
        enemy->pos.x += dir * (enemy->speed * dt);
        if (dir == -1)
            sfRectangleShape_setOrigin(enemy->hitbox, (sfVector2f){0, 0});
        else
            sfRectangleShape_setOrigin(enemy->hitbox, (sfVector2f){40, 0});
        sfRectangleShape_setScale(enemy->hitbox, (sfVector2f){dir * -1, 1});
    } else if (x_or_y == 1)
        enemy->pos.y += dir * (enemy->speed * dt);
    sfRectangleShape_setPosition(enemy->hitbox, enemy->pos);
}

static bool move_vertical(scene_t scene, enemy_t *enemy)
{
    if (roundf(enemy->pos.y) <=
        (enemy->path[enemy->index_path].y * TILE_SIZE) + 1
        && roundf(enemy->pos.y) >=
    (enemy->path[enemy->index_path].y * TILE_SIZE) - 1)
        return (false);
    if (roundf(enemy->pos.y) < enemy->path[enemy->index_path].y * TILE_SIZE) {
        move(enemy, scene.dt, 1, 1);
        return (true);
    } else if (roundf(enemy->pos.y) >
        enemy->path[enemy->index_path].y * TILE_SIZE) {
        move(enemy, scene.dt, 1, -1);
        return (true);
    }
    return (false);
}

static void move_horizontal(scene_t scene, enemy_t *enemy)
{
    if (roundf(enemy->pos.x) <=
        (enemy->path[enemy->index_path].x * TILE_SIZE) + 1
        && roundf(enemy->pos.x) >=
        (enemy->path[enemy->index_path].x * TILE_SIZE) - 1)
        return;
    if (roundf(enemy->pos.x) < enemy->path[enemy->index_path].x * TILE_SIZE)
        move(enemy, scene.dt, 0, 1);
    else if (roundf(enemy->pos.x) >
        enemy->path[enemy->index_path].x * TILE_SIZE)
        move(enemy, scene.dt, 0, -1);
}

void move_enemy(scene_t scene, enemy_t *enemy)
{
    if (roundf(enemy->pos.x) <=
        (enemy->path[enemy->index_path].x * TILE_SIZE) + 1
        && roundf(enemy->pos.x) >=
        (enemy->path[enemy->index_path].x * TILE_SIZE) - 1
        && roundf(enemy->pos.y) <=
        (enemy->path[enemy->index_path].y * TILE_SIZE) + 1
        && roundf(enemy->pos.y) >=
        (enemy->path[enemy->index_path].y * TILE_SIZE) - 1) {
        enemy->index_path++;
        return;
    }
    if (move_vertical(scene, enemy))
        return;
    move_horizontal(scene, enemy);
    sfRectangleShape_setPosition(enemy->hitbox, enemy->pos);
}