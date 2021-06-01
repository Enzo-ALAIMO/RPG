/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** weapon_shoot.c
*/

#include <stdlib.h>
#include "rpg.h"
#include "weapon.h"
#include "sound.h"

static void play_weapon_sound(game_t *game, weapon_t *weapon)
{
    if (weapon->index == 1)
        sfSound_play(game->sounds[S_SHOOT]);
    else
        sfSound_play(game->sounds[S_LASER]);
}

static void spawn_bullet(game_t *game, weapon_t *weapon)
{
    bullet_t *bullet = NULL;

    for (int i = 0; i < NB_BULLETS; ++i) {
        bullet = &weapon->arr_bullets[i];
        if (bullet->is_used)
            continue;
        play_weapon_sound(game, weapon);
        bullet->position.x = sfSprite_getPosition(weapon->weapon_item
            [weapon->index].sprite).x;
        bullet->position.y = sfSprite_getPosition(weapon->weapon_item
            [weapon->index].sprite).y;
        sfRectangleShape_setPosition(bullet->hitbox, bullet->position);
        sfRectangleShape_setOrigin(bullet->hitbox, (sfVector2f){20, 20});
        sfRectangleShape_setRotation(bullet->hitbox, sfSprite_getRotation
            (weapon->weapon_item[weapon->index].sprite));
        bullet->is_used = true;
        bullet->timer = 0;
        weapon->timer = 0;
        break;
    }
}

void weapon_shoot(game_t *game)
{
    player_t *player = &game->player;
    weapon_t *weapon = &player->weapon;

    if (!weapon->is_active)
        return;
    if (weapon->timer >= weapon->time_between_shoot[weapon->index])
        spawn_bullet(game, weapon);
}

void use_potion_life(game_t *game)
{
    static int value = 0;

    if (game->player.weapon.weapon_item[3].new == false && value > 10) {
        game->player.inventory.arr[12] = NULL;
        game->player.item_equiped = NULL;
    }
    if (game->player.health <= game->player.health - 20) {
        game->player.health += 20;
        game->player.weapon.weapon_item[3].new = false;
    }
    value++;
}

void use_potion_strength(game_t *game)
{
    static int value = 0;

    if (game->player.weapon.weapon_item[4].new == false && value > 10) {
        game->player.weapon.damage[4] += 20;
        game->player.inventory.arr[12] = NULL;
        game->player.item_equiped = NULL;
        value = 0;
    }
    game->player.weapon.weapon_item[4].new = false;
    value++;
}