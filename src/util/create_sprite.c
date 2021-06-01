/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** create_sprite.c
*/

#include "rpg.h"

sfSprite *create_sprite(char const *filepath, sfVector2f position, sfVector2f
scale)
{
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfFalse);
    sfSprite_setPosition(sprite, position);
    sfSprite_setScale(sprite, scale);
    return (sprite);
}