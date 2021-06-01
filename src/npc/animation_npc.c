/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** animation_npc.c
*/

#include "rpg.h"

void npc_animation(npc_t *npc, float dt)
{
    sfRectangleShape_setTextureRect(npc->hitbox, npc->rect);
    npc->timer += dt;
    if (npc->timer > npc->time_between_animation) {
        npc->timer = 0;
        if (npc->rect.left + npc->rect.width >= npc->spritesheet_end)
            npc->rect.left = npc->spritesheet_start;
        else
            npc->rect.left += npc->rect.width;
    } else if (npc->rect.left < npc->spritesheet_start || npc->rect
        .left > npc->spritesheet_end)
        npc->rect.left = npc->spritesheet_start;
}