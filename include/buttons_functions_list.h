/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** buttons_functions_list.h
*/

#ifndef BUTTONS_FUNCTIONS_LIST_H
#define BUTTONS_FUNCTIONS_LIST_H

#include "buttons_functions.h"
#include "shop.h"
#include "inventory.h"

static const void *buttons_functions[14] = {
    empty, exit_game, change_scene, resume_game, return_to_menu,
    change_res, change_fps, change_volume, get_first_gun, get_second_gun,
    get_life, get_strength, swap_item, toggle_quest
};

#endif