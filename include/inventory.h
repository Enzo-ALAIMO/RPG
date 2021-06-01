/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** inventory.h
*/

#ifndef INVENTORY_H
#define INVENTORY_H

#include "rpg.h"

static const int INVENTORY_SIZE = 13;
static const int INV_POS_X_LEFT = 1550;
static const int INV_POS_X_MIDDLE = 1612;
static const int INV_POS_X_RIGHT = 1672;
static const int INV_POS_Y_ONE = 185;
static const int INV_POS_Y_TWO = 247;
static const int INV_POS_Y_THREE = 311;
static const int INV_POS_Y_FOUR = 372;
static const int INV_POS_X_EQUIPED = 1797;
static const int INV_POS_Y_EQUIPED = 402;

inventory_t create_inventory(void);
void swap_item(game_t *game, int index);
void inventory_event(game_t *game);
void draw_inventory_item(game_t *game, inventory_t *inventory);
void trigger_inventory(game_t *game);
void weapon_check(game_t *game);

#endif