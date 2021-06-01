/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** swap_weapon.c
*/

#include "rpg.h"

void weapon_check(game_t *game)
{
    if (game->player.item_equiped == &game->player.weapon.weapon_item[0]) {
        game->player.weapon.index = 0;
        game->player.weapon.damage[0] = 10;
    }
    if (game->player.item_equiped == &game->player.weapon.weapon_item[1]) {
        game->player.weapon.index = 1;
        game->player.weapon.damage[1] = 10000;
    }
    if (game->player.item_equiped == &game->player.weapon.weapon_item[2]) {
        game->player.weapon.index = 2;
        game->player.weapon.damage[2] = 500;
    }
}