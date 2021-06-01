/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** bullet.c
*/

#include <stdlib.h>
#include "rpg.h"
#include "weapon.h"

void update_bullets(game_t *game, float dt)
{
    weapon_t *weapon = &game->player.weapon;
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

void draw_bullets(game_t *game)
{
    for (int i = 0; i < NB_BULLETS; ++i) {
        if (!game->player.weapon.arr_bullets[i].is_used)
            continue;
        sfRenderWindow_drawRectangleShape(
            game->window, game->player.weapon.arr_bullets[i].hitbox, NULL);
    }
}