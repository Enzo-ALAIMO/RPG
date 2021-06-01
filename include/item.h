/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** item.h
*/

#ifndef ITEM_H
#define ITEM_H

enum item_type {
    WEAPON,
    POTION,
};

enum weapon_type {
    POS_X,
    POS_Y,
    ROTATION,
    NB_WEAPON_VAR,
};

item_t create_weapon_item(char const *path);

#endif