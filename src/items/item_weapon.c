/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** item_weapon.c
*/

#include <stdlib.h>
#include "rpg.h"
#include "item.h"
#include "util.h"
#include "weapon.h"

item_t create_potion_life(char const *path)
{
    item_t life = {0};

    life.item_type = WEAPON;
    life.variables = malloc(sizeof(int) * NB_WEAPON_VAR);
    if (life.variables == NULL)
        return ((item_t){0});
    life.variables[POS_X] = 500;
    life.variables[POS_Y] = 500;
    life.variables[ROTATION] = 0;
    life.rect = (sfIntRect){0, 0, 40, 40};
    life.sprite = create_sprite(path, (sfVector2f)
            {500, 500}, WEAPON_SCALE);
    life.new = true;
    life.use = &use_potion_life;
    sfSprite_setTextureRect(life.sprite, life.rect);
    return (life);
}

item_t create_potion_strength(char const *path)
{
    item_t strength = {0};

    strength.item_type = WEAPON;
    strength.variables = malloc(sizeof(int) * NB_WEAPON_VAR);
    if (strength.variables == NULL)
        return ((item_t){0});
    strength.variables[POS_X] = 500;
    strength.variables[POS_Y] = 500;
    strength.variables[ROTATION] = 0;
    strength.rect = (sfIntRect){0, 0, 40, 40};
    strength.sprite = create_sprite(path, (sfVector2f)
            {500, 500}, WEAPON_SCALE);
    strength.new = true;
    strength.use = &use_potion_strength;
    sfSprite_setTextureRect(strength.sprite, strength.rect);
    return (strength);
}

item_t create_weapon_item(char const *path)
{
    item_t weapon = {0};

    weapon.item_type = WEAPON;
    weapon.variables = malloc(sizeof(int) * NB_WEAPON_VAR);
    if (weapon.variables == NULL)
        return ((item_t){0});
    weapon.variables[POS_X] = 500;
    weapon.variables[POS_Y] = 500;
    weapon.variables[ROTATION] = 0;
    weapon.rect = (sfIntRect){0, 0, 40, 40};
    weapon.sprite = create_sprite(path, (sfVector2f)
        {500, 500}, WEAPON_SCALE);
    weapon.new = true;
    weapon.use = &weapon_shoot;
    sfSprite_setTextureRect(weapon.sprite, weapon.rect);
    return (weapon);
}