/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** free_a_star.c
*/

#include "rpg.h"
#include "pathfinding.h"

void free_a_star(a_star_t *a_star)
{
    for (int i = 0; i < a_star->grid_height; ++i) {
        free(a_star->init_grid[i]);
        free(a_star->grid[i]);
    }
    free(a_star->init_grid);
    free(a_star->grid);
    for (int i = 0; i < a_star->grid_height; ++i) {
        for (int j = 0; j < a_star->grid_width; j++)
            free(a_star->spots[i][j].neighbors);
        free(a_star->spots[i]);
    }
    free(a_star->spots);
}