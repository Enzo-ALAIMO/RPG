/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** weapon.c
*/

#include <stdlib.h>
#include "rpg.h"
#include "item.h"
#include "weapon.h"
#include "util.h"
#include "item_sprite.h"

static sfRectangleShape *create_hitbox(char *bullet_path)
{
    sfRectangleShape *hitbox = sfRectangleShape_create();
    sfTexture *texture = sfTexture_createFromFile(bullet_path,
        NULL);

    sfRectangleShape_setSize(hitbox, (sfVector2f){40, 40});
    sfRectangleShape_setPosition(hitbox, (sfVector2f){0, 0});
    sfRectangleShape_setTexture(hitbox, texture, 1);
    sfRectangleShape_setScale(hitbox, BULLET_SCALE);
    return (hitbox);
}

static bullet_t *create_bullets(char *bullet_path)
{
    bullet_t *arr_bullets = malloc(sizeof(bullet_t) * NB_BULLETS);

    if (arr_bullets == NULL)
        return (NULL);
    for (int i = 0; i < NB_BULLETS; ++i) {
        arr_bullets[i].is_used = false;
        arr_bullets[i].speed = 500;
        arr_bullets[i].damage = 10;
        arr_bullets[i].live_time = 2;
        arr_bullets[i].hitbox = create_hitbox(bullet_path);
    }
    return (arr_bullets);
}

static void init_item(weapon_t *weapon)
{
    weapon->weapon_item = malloc(sizeof(item_t) * 7);
    weapon->time_between_shoot = malloc(sizeof(float) * 3);
    weapon->damage = malloc(sizeof(int) * 3);
    weapon->weapon_item[0] = create_weapon_item(WEAPON_ONE);
    weapon->weapon_item[1] = create_weapon_item(WEAPON_TWO);
    weapon->weapon_item[2] = create_weapon_item(WEAPON_THREE);
    weapon->weapon_item[3] = create_potion_life(LIFE);
    weapon->weapon_item[4] = create_potion_strength(STRENGTH);
    weapon->weapon_item[5] = create_weapon_item(WEAPON_BANDIT);
    weapon->weapon_item[6] = create_weapon_item(WEAPON_SKELETON);
    weapon->time_between_shoot[0] = 0.2;
    weapon->time_between_shoot[1] = 0;
    weapon->time_between_shoot[2] = 0.5;
    weapon->damage[0] = 10;
    weapon->damage[1] = 10000;
    weapon->damage[2] = 500;
}

weapon_t create_weapon(char *path_bullet)
{
    weapon_t weapon = {0};

    init_item(&weapon);
    weapon.index = 0;
    weapon.arr_bullets = create_bullets(path_bullet);
    weapon.is_active = true;
    return (weapon);
}