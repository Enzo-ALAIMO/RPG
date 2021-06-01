/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** shoot_enemy.c
*/

#include "rpg.h"
#include "weapon.h"
#include "enemy.h"

void update_enemy_bullets(float dt, enemy_t *enemy)
{
    weapon_t *weapon = &enemy->weapon;
    bullet_t *bullet = NULL;
    sfVector2f angle = (sfVector2f){0, 0};

    for (int i = 0; i < NB_BULLETS; ++i) {
        bullet = &weapon->arr_bullets[i];
        if (!bullet->is_used)
            continue;
        bullet->timer += dt;
        if (bullet->timer >= bullet->live_time)
            bullet->is_used = false;
        angle.x = cos((M_PI / 180) *
            sfRectangleShape_getRotation(bullet->hitbox));
        angle.y = sin((M_PI / 180) *
            sfRectangleShape_getRotation(bullet->hitbox));
        sfRectangleShape_setPosition(bullet->hitbox, (sfVector2f){
            sfRectangleShape_getPosition(bullet->hitbox).x + angle.x *
                (bullet->speed * dt),
            sfRectangleShape_getPosition(bullet->hitbox).y + angle.y *
                (bullet->speed * dt)});
    }
}

void draw_enemy_bullets(game_t *game, enemy_t *enemy)
{
    for (int i = 0; i < NB_BULLETS; ++i) {
        if (!enemy->weapon.arr_bullets[i].is_used)
            continue;
        sfRenderWindow_drawRectangleShape(
            game->window, enemy->weapon.arr_bullets[i].hitbox, NULL);
    }
}

static void spawn_bullet(int enemy_type, weapon_t *weapon)
{
    bullet_t *bullet = NULL;
    sfVector2f weapon_pos = enemy_type == BANDIT ?
        sfSprite_getPosition(weapon->weapon_item[5].sprite) :
        sfSprite_getPosition(weapon->weapon_item[6].sprite);
    sfSprite *weapon_sprite = enemy_type == BANDIT ?
        weapon->weapon_item[5].sprite : weapon->weapon_item[6].sprite;

    for (int i = 0; i < NB_BULLETS; ++i) {
        bullet = &weapon->arr_bullets[i];
        if (bullet->is_used)
            continue;
        bullet->position = weapon_pos;
        sfRectangleShape_setPosition(bullet->hitbox, bullet->position);
        sfRectangleShape_setOrigin(bullet->hitbox, (sfVector2f){20, 20});
        sfRectangleShape_setRotation(bullet->hitbox, sfSprite_getRotation
            (weapon_sprite));
        bullet->is_used = true;
        bullet->timer = 0;
        weapon->timer = 0;
        break;
    }
}

static void update_weapon_position(sfVector2f player_pos, item_t *item,
    enemy_t *enemy)
{
    float angle = atan2(player_pos.y - (enemy->pos.y + (1 * 20))
        , player_pos.x - (enemy->pos.x + (1 * 18)));

    angle *= 180 / M_PI;
    if (angle < 0)
        angle = 360 - (-angle);
    sfSprite_setOrigin(item->sprite, (sfVector2f){20, 20});
    sfSprite_setRotation(item->sprite, angle);
}

void shoot_enemy(game_t *game, scene_t *scene, enemy_t *enemy)
{
    player_t *player = &game->player;
    weapon_t *weapon = &enemy->weapon;

    if (enemy->enemy_type == BANDIT)
        update_weapon_position(player->position, &enemy->weapon
            .weapon_item[5], enemy);
    else if (enemy->enemy_type == SKELETON)
        update_weapon_position(player->position, &enemy->weapon
            .weapon_item[6], enemy);
    weapon->timer += scene->dt;
    if (weapon->timer >= 1) {
        spawn_bullet(enemy->enemy_type, weapon);
        weapon->timer = 0;
    }
}