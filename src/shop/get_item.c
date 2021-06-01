/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** get_item.c
*/

#include "util.h"
#include "rpg.h"
#include "shop.h"
#include "shop_sprite.h"
#include "sound.h"

void set_equipements(equipement_t *equipements)
{
    sfVector2f pos = {0, 0};
    sfVector2f scale = {1, 1};
    equipements->button = malloc(sizeof(bool) * 4);

    for (int i = 0; i < 4; i++)
        equipements->button[i] = false;
    equipements->first_gun = create_sprite(FIRST_GUN, pos, scale);
    equipements->second_gun = create_sprite(SECOND_GUN, pos, scale);
    equipements->life = create_sprite(GET_LIFE, pos, scale);
    equipements->strength = create_sprite(GET_STRENGTH, pos, scale);
}

void get_first_gun(game_t *game)
{
    int index = add_in_inventory(game);

    for (int i = 0; i < 4; i++)
        game->seller.equipements.button[i] = false;
    game->seller.equipements.button[0] = true;
    if (game->player.gold >= 1000000) {
        game->player.gold -= 1000000;
        game->player.weapon.damage[1] += 1000;
        game->player.inventory.arr[index] = &game->player.weapon.weapon_item[1];
    }
}

void get_second_gun(game_t *game)
{
    int index = add_in_inventory(game);

    for (int i = 0; i < 4; i++)
        game->seller.equipements.button[i] = false;
    game->seller.equipements.button[1] = true;
    if (game->player.gold >= 200000) {
        game->player.gold -= 200000;
        game->player.inventory.arr[index] = &game->player.weapon.weapon_item[2];
    }
}

void get_life(game_t *game)
{
    int index = add_in_inventory(game);

    for (int i = 0; i < 4; i++)
        game->seller.equipements.button[i] = false;
    game->seller.equipements.button[2] = true;
    if (game->player.gold >= 10000) {
        game->player.gold -= 10000;
        game->player.health += 10;
        sfSound_play(game->sounds[S_POT]);
        game->player.inventory.arr[index] = &game->player.weapon.weapon_item[3];
    }
    if (game->player.weapon.weapon_item[3].new == false)
        game->player.inventory.arr[index] = NULL;
}

void get_strength(game_t *game)
{
    int index = add_in_inventory(game);
    int weapon = game->player.weapon.index;

    for (int i = 0; i < 4; i++)
        game->seller.equipements.button[i] = false;
    game->seller.equipements.button[3] = true;
    if (game->player.gold >= 20000) {
        game->player.gold -= 20000;
        game->player.weapon.damage[weapon] += 10;
        sfSound_play(game->sounds[S_POW]);
        game->player.inventory.arr[index] = &game->player.weapon.weapon_item[4];
    }
}