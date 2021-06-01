/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** a_start_get_spots.c
*/

#include "rpg.h"
#include "map.h"

void get_nb_spots(a_star_t *a_star)
{
    for (int i = 0; i < a_star->grid_height; ++i)
        for (int j = 0; j < a_star->grid_width; ++j)
            if (a_star->init_grid[i][j] == FLOOR)
                a_star->nb_spots++;
}