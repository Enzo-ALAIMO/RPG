/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** util.h
*/

#ifndef UTIL_H
#define UTIL_H

#include <SFML/Graphics.h>
#include "rpg.h"

static const int NB_LEN = 10;

char *nb_to_string(int nb);
int get_random_int(int bound);
sfSprite *create_sprite(char const *filepath, sfVector2f position, sfVector2f
scale);
float get_float(char const *str);
void get_save(game_t *game);
void set_save(game_t *game);

#endif