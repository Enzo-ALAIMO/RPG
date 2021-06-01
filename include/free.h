/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** free.h
*/

#ifndef FREE_H
#define FREE_H

#include "rpg.h"

void free_game(game_t *game);
void free_scene(scene_t scene);
void free_in_game(in_game_t *in_game);
void free_map(map_t *map);
void free_a_star(a_star_t *a_star);
void free_weapon(game_t *game);

#endif