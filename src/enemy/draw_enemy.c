/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** draw_enemy.c
*/

#include "rpg.h"
#include "enemy.h"

static void draw_bandit_weapon(game_t *game, enemy_t *enemy)
{
    if (enemy->boss) {
        sfSprite_setOrigin(enemy->weapon.weapon_item[5].sprite,
            (sfVector2f){20, 20});
        sfSprite_setPosition(enemy->weapon.weapon_item[5].sprite, (sfVector2f)
            {enemy->pos.x + (3 * 20), enemy->pos.y + (3 * 20)});
        sfRenderWindow_drawSprite(game->window, enemy->weapon
            .weapon_item[5].sprite, NULL);
    } else {
        sfSprite_setOrigin(enemy->weapon.weapon_item[5].sprite,
            (sfVector2f){20, 20});
        sfSprite_setPosition(enemy->weapon.weapon_item[5].sprite, (sfVector2f)
            {enemy->pos.x + (1 * 20), enemy->pos.y + (1 * 20)});
        sfRenderWindow_drawSprite(game->window, enemy->weapon
            .weapon_item[5].sprite, NULL);
    }
}

static void draw_skeleton_weapon(game_t *game, enemy_t *enemy)
{
    if (enemy->boss) {
        sfSprite_setOrigin(enemy->weapon.weapon_item[6].sprite,
        (sfVector2f){20, 20});
        sfSprite_setPosition(enemy->weapon.weapon_item[6].sprite, (sfVector2f)
            {enemy->pos.x + (3 * 20), enemy->pos.y + (3 * 20)});
        sfRenderWindow_drawSprite(game->window, enemy->weapon
            .weapon_item[6].sprite, NULL);
    } else {
        sfSprite_setOrigin(enemy->weapon.weapon_item[6].sprite,
        (sfVector2f){20, 20});
        sfSprite_setPosition(enemy->weapon.weapon_item[6].sprite, (sfVector2f)
            {enemy->pos.x + (1 * 20), enemy->pos.y + (1 * 20)});
        sfRenderWindow_drawSprite(game->window, enemy->weapon
            .weapon_item[6].sprite, NULL);
    }
}

static void set_boss(enemy_t *enemy)
{
    sfRectangleShape_setScale(enemy->hitbox, (sfVector2f){3, 3});
    if (enemy->enemy_type != SLIME)
        sfSprite_setScale(enemy->weapon.weapon_item->sprite,
            (sfVector2f){3, 3});
}

void draw_enemy(game_t *game, scene_t scene)
{
    enemy_t *enemy = NULL;

    for (int i = 0; i < NB_ENEMY; ++i) {
        enemy = &scene.in_game->arr_enemies[i];
        if (enemy->dead)
            continue;
        if (enemy->boss)
            set_boss(enemy);
        sfRenderWindow_drawRectangleShape(game->window, enemy->hitbox, NULL);
        if (enemy->enemy_type == SLIME)
            continue;
        else if (enemy->enemy_type == BANDIT)
            draw_bandit_weapon(game, enemy);
        else
            draw_skeleton_weapon(game, enemy);
        draw_enemy_bullets(game, enemy);
    }
}