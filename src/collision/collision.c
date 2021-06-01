/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** collision.c
*/

#include "rpg.h"

bool collision_between_rectangle(sfRectangleShape *r1, sfRectangleShape *r2)
{
    sfFloatRect bounding_box_r1 = sfRectangleShape_getGlobalBounds(r1);
    sfFloatRect bounding_box_r2 = sfRectangleShape_getGlobalBounds(r2);

    if (sfFloatRect_intersects(&bounding_box_r1, &bounding_box_r2, NULL))
        return (true);
    return (false);
}

bool collision_between_rectangle_and_two_points(sfRectangleShape *rect,
    float x, float y)
{
    sfFloatRect bounding_box_rect = sfRectangleShape_getGlobalBounds(rect);

    if (sfFloatRect_contains(&bounding_box_rect, x, y))
        return (true);
    return (false);
}