/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** player_collision_points.c
*/

#include "rpg.h"
#include "collision.h"

void check_top(player_t *player, sfFloatRect
    bounding_box_rect, sfRectangleShape *hitbox)
{
    if (collision_between_rectangle_and_two_points(hitbox,
        bounding_box_rect.left + offset,
        bounding_box_rect.top) ||
        collision_between_rectangle_and_two_points(hitbox,
        bounding_box_rect.left - offset + bounding_box_rect.width,
        bounding_box_rect.top))
        player->player_input.stuck_up = true;
}

void check_down(player_t *player, sfFloatRect
    bounding_box_rect, sfRectangleShape *hitbox)
{
    if (collision_between_rectangle_and_two_points(hitbox,
        bounding_box_rect.left + offset,
        bounding_box_rect.top + bounding_box_rect.height) ||
        collision_between_rectangle_and_two_points(hitbox,
        bounding_box_rect.left - offset + bounding_box_rect.width,
        bounding_box_rect.top + bounding_box_rect.height))
        player->player_input.stuck_down = true;
}

void check_left(player_t *player, sfFloatRect
    bounding_box_rect, sfRectangleShape *hitbox)
{
    if (collision_between_rectangle_and_two_points(hitbox,
        bounding_box_rect.left,
        bounding_box_rect.top + offset) ||
        collision_between_rectangle_and_two_points(hitbox,
        bounding_box_rect.left,
        bounding_box_rect.top - offset + bounding_box_rect.height))
        player->player_input.stuck_left = true;
}

void check_right(player_t *player, sfFloatRect
    bounding_box_rect, sfRectangleShape *hitbox)
{
    if (collision_between_rectangle_and_two_points(hitbox,
        bounding_box_rect.left + bounding_box_rect.width,
        bounding_box_rect.top + offset)
        || collision_between_rectangle_and_two_points(hitbox,
        bounding_box_rect.left + bounding_box_rect.width,
        bounding_box_rect.top - offset + bounding_box_rect.height))
        player->player_input.stuck_right = true;
}

void check_player_collision_with_scene_hitbox(player_t *player, in_game_t
    *in_game)
{
    sfFloatRect bounding_box_rect = sfRectangleShape_getGlobalBounds(
        player->hitbox);

    player->player_input.stuck_up = false;
    player->player_input.stuck_down = false;
    player->player_input.stuck_left = false;
    player->player_input.stuck_right = false;
    for (int i = 0; in_game->arr_hitbox[i] != NULL; ++i) {
        check_top(player, bounding_box_rect, in_game->arr_hitbox[i]);
        check_down(player, bounding_box_rect, in_game->arr_hitbox[i]);
        check_left(player, bounding_box_rect, in_game->arr_hitbox[i]);
        check_right(player, bounding_box_rect, in_game->arr_hitbox[i]);
    }
}