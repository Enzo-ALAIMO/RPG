/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** create_enemy.c
*/

#include "rpg.h"
#include "enemy.h"
#include "enemy_sprite.h"
#include "enemy_rect.h"
#include "util.h"
#include "weapon.h"

static sfVector2f get_random_spawn_pos(map_t *map)
{
    sfVector2i rand_pos = {0, 0};

    while (true) {
        rand_pos = (sfVector2i){get_random_int(map->width - 2),
            get_random_int(map->height - 2)};
        if (map->grid[rand_pos.y][rand_pos.x] == 'F')
            break;
    }
    return ((sfVector2f){rand_pos.x * TILE_SIZE, rand_pos.y * TILE_SIZE});
}

static sfRectangleShape *init_hitbox(enemy_t *enemy, sfTexture *texture,
    sfVector2f spawn_pos)
{
    sfRectangleShape *hitbox = sfRectangleShape_create();

    sfRectangleShape_setSize(hitbox, (sfVector2f){40, 40});
    sfRectangleShape_setPosition(hitbox, spawn_pos);
    sfRectangleShape_setTexture(hitbox, texture, 1);
    sfRectangleShape_setScale(hitbox, (sfVector2f){1, 1});
    sfRectangleShape_setTextureRect(hitbox, enemy->rect);
    return (hitbox);
}

enemy_t create_enemy(char const *filepath, sfVector2f spawn_pos, sfVector3f
    params, int type)
{
    enemy_t enemy = {0};
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);

    enemy.enemy_type = type;
    if (type == BANDIT)
        enemy.weapon = create_weapon(BANDIT_BULLET);
    else if (type == SKELETON)
        enemy.weapon = create_weapon(SKELETON_BULLET);
    enemy.enemy_state = WALK;
    enemy.hp = params.x;
    enemy.xp = params.y;
    enemy.gold = params.z;
    enemy.range = 150;
    enemy.rect = (sfIntRect){rect_start[type], 0, 40, 40};
    enemy.time_between_animation = 0.2;
    enemy.spritesheet_start = rect_start[type];
    enemy.spritesheet_end = rect_end[type];
    enemy.hitbox = init_hitbox(&enemy, texture, spawn_pos);
    enemy.speed = 100;
    enemy.pos = spawn_pos;
    return (enemy);
}

static enemy_t *choose_enemy(enemy_t *arr_enemies, map_t *map, int i, int
    random)
{
    switch (random) {
        case 0:
            arr_enemies[i] = create_enemy(SLIME_SPRITE, get_random_spawn_pos
            (map), (sfVector3f){SLIME_HP, 10, 500}, SLIME);
            break;
        case 1:
            arr_enemies[i] = create_enemy(BANDIT_SPRITE,
            get_random_spawn_pos(map), (sfVector3f){BANDIT_HP, 10, 500},
            BANDIT);
            break;
        case 2:
            arr_enemies[i] = create_enemy(SKELETON_SPRITE,
            get_random_spawn_pos(map), (sfVector3f){SKELETON_HP, 10, 500},
            SKELETON);
            break;
    }
    return (arr_enemies);
}

enemy_t *create_arr_enemies(map_t *map)
{
    enemy_t *arr_enemies = malloc(sizeof(enemy_t) * NB_ENEMY);
    int random = 0;

    if (arr_enemies == NULL)
        return (NULL);
    for (int i = 0; i < NB_ENEMY; ++i) {
        random = get_random_int(2);
        arr_enemies = choose_enemy(arr_enemies, map, i , random);
    }
    random = get_random_int(NB_ENEMY);
    arr_enemies[random].boss = true;
    arr_enemies[random].hp *= 10;
    arr_enemies[random].range *= 5;
    arr_enemies[random].xp *= 5;
    arr_enemies[random].gold *= 10;
    return (arr_enemies);
}