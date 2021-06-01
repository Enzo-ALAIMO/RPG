/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** shop.h
*/

#include "rpg.h"

#ifndef SHOP_H
#define SHOP_H

void shoper_animation(shoper_t *shoper, float dt);
shoper_t create_shoper_parser(char *arg);
void get_first_gun(game_t *game);
void get_second_gun(game_t *game);
void get_life(game_t *game);
void get_strength(game_t *game);
void draw_shop(game_t *game);
void set_equipements(equipement_t *equipements);
unsigned int add_in_inventory(game_t *game);

#endif