/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** draw.h
*/

#ifndef DRAW_H
#define DRAW_H

#include "rpg.h"

void draw_menu(game_t *game);
void draw_htp(game_t *game);
void draw_settings(game_t *game);
void draw_hub(game_t *game);
void draw_buttons(game_t *game, scene_t scene, int nb_buttons);
void draw_cave(game_t *game);

#endif