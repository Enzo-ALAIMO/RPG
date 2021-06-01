/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** create_npc.c
*/

#include "rpg.h"
#include "npc.h"
#include "util.h"

npc_t create_npc(char const *filepath, char const *filepath_dialog, sfVector2f
    spawn_pos)
{
    npc_t npc = {0};
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);

    npc.npc_state = WALK;
    npc.dialog = create_sprite(filepath_dialog, (sfVector2f){0, 0},
        (sfVector2f){1, 1});
    npc.rect = (sfIntRect){0, 0, 40, 40};
    npc.time_between_animation = 0.2;
    npc.spritesheet_start = 200;
    npc.spritesheet_end = 520;
    npc.hitbox = sfRectangleShape_create();
    sfRectangleShape_setSize(npc.hitbox, (sfVector2f){40, 40});
    sfRectangleShape_setPosition(npc.hitbox, spawn_pos);
    sfRectangleShape_setTexture(npc.hitbox, texture, 1);
    sfRectangleShape_setScale(npc.hitbox, (sfVector2f){1, 1});
    sfRectangleShape_setTextureRect(npc.hitbox, npc.rect);
    npc.speed = 50;
    npc.pos = spawn_pos;
    return (npc);
}