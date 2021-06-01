/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** weapon.h
*/

#ifndef WEAPON_H
#define WEAPON_H

static const sfVector2f BULLET_SCALE = (sfVector2f){1, 1};
static const sfVector2f WEAPON_SCALE = (sfVector2f){1, 1};
static const int NB_BULLETS = 50;

weapon_t create_weapon(char *path_bullet);
item_t create_potion_strength(char const *path);
item_t create_potion_life(char const *path);
void weapon_shoot(game_t *game);
void draw_bullets(game_t *game);
void update_bullets(game_t *game, float dt);
void use_potion_life(game_t *game);
void use_potion_strength(game_t *game);

#endif