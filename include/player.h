/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** player.h
*/

#ifndef PLAYER_H
#define PLAYER_H

#include "rpg.h"

static const sfVector2f PLAYER_SCALE = (sfVector2f){1, 1};

enum player_state {
    NORMAL,
    ROLL,
    DEAD,
};

void player_animation(player_t *player, float dt);
void player_movement(game_t *game, player_t *player, float dt);
void player_movement_event(game_t *game);
void handle_input(game_t *game);
void player_item(game_t *game, player_t *player, float dt);
void check_reward_quest(game_t *game);

#endif