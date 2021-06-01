/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** animation_enemy.c
*/

#include "rpg.h"
#include "enemy.h"

void enemy_animation(enemy_t *enemy, float dt)
{
    sfRectangleShape_setTextureRect(enemy->hitbox, enemy->rect);
    enemy->timer += dt;
    if (enemy->timer < enemy->time_between_animation)
        return;
    enemy->timer = 0;
    if (enemy->enemy_state == DESTROY &&
        enemy->rect.left + enemy->rect.width >= enemy->spritesheet_end) {
        enemy->dead = true;
        return;
    } else if (enemy->rect.left + enemy->rect.width >= enemy->spritesheet_end)
        enemy->rect.left = enemy->spritesheet_start;
    else
        enemy->rect.left += enemy->rect.width;
}