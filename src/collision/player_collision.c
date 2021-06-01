/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** player_collision.c
*/

#include <stdlib.h>
#include "rpg.h"
#include "weapon.h"
#include "collision.h"

bool check_player_collision_with_bullet(player_t *player, weapon_t *weapon)
{
    bullet_t *bullet = NULL;

    for (int i = 0; i < NB_BULLETS; ++i) {
        bullet = &weapon->arr_bullets[i];
        if (!bullet->is_used)
            continue;
        if (collision_between_rectangle(player->hitbox, bullet->hitbox))
            return (true);
    }
    return (false);
}