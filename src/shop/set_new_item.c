/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** set_new_item.c
*/

#include "rpg.h"
#include <stdbool.h>

unsigned int add_in_inventory(game_t *game)
{
    int i;

    for (i = 0; game->player.inventory.arr[i] != NULL; i++);
    return (i);
}