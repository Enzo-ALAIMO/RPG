/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** init_player.c
*/

#include <stdlib.h>
#include "rpg.h"
#include "my.h"
#include "player.h"
#include "inventory.h"

static sfRectangleShape *create_hitbox(char const *filepath,
        sfVector2f position, sfIntRect rect)
{
    sfRectangleShape *hitbox = sfRectangleShape_create();
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);

    sfRectangleShape_setSize(hitbox, (sfVector2f){40, 40});
    sfRectangleShape_setPosition(hitbox, position);
    sfRectangleShape_setTexture(hitbox, texture, 1);
    sfRectangleShape_setScale(hitbox, PLAYER_SCALE);
    sfRectangleShape_setTextureRect(hitbox, rect);
    return (hitbox);
}

void init_player(char **values, player_t *player)
{
    player->health = my_getnbr(values[1]);
    player->xp = my_getnbr(values[2]);
    player->level = my_getnbr(values[3]);
    player->gold = my_getnbr(values[4]);
    player->speed = my_getnbr(values[5]);
    player->init_roll_speed = my_getnbr(values[6]);
    player->position = (sfVector2f){500, 500};
    player->rect = (sfIntRect){0, 0, 40, 40};
    player->spritesheet_end = 200;
    player->hitbox = create_hitbox(values[7], player->position, player->rect);
    player->time_between_animation = 0.2;
    player->player_input = (player_input_t){0};
    player->inventory = create_inventory();
}