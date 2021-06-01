/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** player_map_collision.c
*/

#include "rpg.h"
#include "collision.h"

void check_player_collision_with_cave_map(player_t *player, scene_t scene)
{
    sfFloatRect bounding_box_rect = sfRectangleShape_getGlobalBounds(
        player->hitbox);

    player->player_input.stuck_up = false;
    player->player_input.stuck_down = false;
    player->player_input.stuck_left = false;
    player->player_input.stuck_right = false;
    for (int i = 0; i < scene.map->nb_hitbox; ++i) {
        if (scene.map->hitbox[i] == NULL)
            continue;
        check_top(player, bounding_box_rect, scene.map->hitbox[i]);
        check_down(player, bounding_box_rect, scene.map->hitbox[i]);
        check_left(player, bounding_box_rect, scene.map->hitbox[i]);
        check_right(player, bounding_box_rect, scene.map->hitbox[i]);
    }
}