/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** init_hitbox.c
*/

#include <stdlib.h>
#include "rpg.h"
#include "my.h"
#include "player.h"

sfRectangleShape *create_hitbox(sfVector2f position, sfVector2f size)
{
    sfRectangleShape *hitbox = sfRectangleShape_create();

    sfRectangleShape_setSize(hitbox, size);
    sfRectangleShape_setPosition(hitbox, position);
    sfRectangleShape_setFillColor(hitbox, sfTransparent);
    sfRectangleShape_setOutlineThickness(hitbox, 1);
    sfRectangleShape_setOutlineColor(hitbox, sfBlack);
    return (hitbox);
}

sfRectangleShape **init_hitbox(char **values, sfRectangleShape **arr_hitbox,
    int size)
{
    for (int i = 0; i < size; ++i) {
        if (arr_hitbox[i] != NULL)
            continue;
        arr_hitbox[i] = create_hitbox((sfVector2f){my_getnbr(values[1]),
            my_getnbr(values[2])}, (sfVector2f){my_getnbr(values[3]),
            my_getnbr(values[4])});
        break;
    }
    return (arr_hitbox);
}