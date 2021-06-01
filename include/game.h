/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** game.h
*/

#ifndef GAME_H
#define GAME_H

#include "rpg.h"

void game_loop(game_t *game);
in_game_t *in_game_init(scene_t scene, in_game_t *in_game);
map_t *map_init(char *map_path);

#endif