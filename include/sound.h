/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** sound.h
*/

#ifndef SOUND_H
#define SOUND_H

#include "rpg.h"

enum sounds {
    S_BG_MENU,
    S_BG_HUB,
    S_BG_CAVE,
    S_DEAD_P,
    S_HIT_E,
    S_HIT_P,
    S_POT,
    S_POW,
    S_SHOOT,
    S_LASER,
    NB_SOUND
};

void init_sounds(game_t *game);

#endif