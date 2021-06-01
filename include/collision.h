/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** collision.h
*/

#ifndef COLLISION_H
#define COLLISION_H

static const int offset = 5;

bool collision_between_rectangle(sfRectangleShape *r1, sfRectangleShape *r2);
bool collision_between_rectangle_and_two_points(sfRectangleShape *rect,
    float x, float y);
bool check_player_collision_with_bullet(player_t *player, weapon_t *weapon);
void check_player_collision_with_scene_hitbox(player_t *player, in_game_t
*in_game);
void check_player_collision_with_cave_map(player_t *player, scene_t scene);
void check_top(player_t *player, sfFloatRect
bounding_box_rect, sfRectangleShape *hitbox);
void check_down(player_t *player, sfFloatRect
bounding_box_rect, sfRectangleShape *hitbox);
void check_left(player_t *player, sfFloatRect
bounding_box_rect, sfRectangleShape *hitbox);
void check_right(player_t *player, sfFloatRect
bounding_box_rect, sfRectangleShape *hitbox);
void check_bullets_collisions_with_enemies(game_t *game);

#endif