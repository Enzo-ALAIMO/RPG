/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** player_animation.c
*/

#include "rpg.h"

void player_animation(player_t *player, float dt)
{
    sfRectangleShape_setTextureRect(player->hitbox, player->rect);
    player->timer += dt;
    if (player->timer > player->time_between_animation) {
        player->timer = 0;
        if (player->rect.left + player->rect.width >= player->spritesheet_end)
            player->rect.left = player->spritesheet_start;
        else
            player->rect.left += player->rect.width;
    } else if (player->rect.left < player->spritesheet_start || player->rect
        .left > player->spritesheet_end)
        player->rect.left = player->spritesheet_start;
}