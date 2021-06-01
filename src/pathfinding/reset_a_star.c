/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** reset_a_star.c
*/

#include "rpg.h"
#include "pathfinding.h"

static void reset_open_set(int size, a_star_t *a_star)
{
    for (int i = 0; i < size; ++i)
        a_star->open_set[i] = (sfVector2i){-1, -1};
}

static void reset_spots(a_star_t *a_star)
{
    for (int i = 0; i < a_star->grid_height; i++) {
        for (int j = 0; j < a_star->grid_width; j++)
            free(a_star->spots[i][j].neighbors);
        free(a_star->spots[i]);
    }
    free(a_star->spots);
}

void reset_a_star(a_star_t *a_star)
{
    for (int i = 0; i < a_star->grid_height; ++i)
        for (int j = 0; j < a_star->grid_width; ++j)
            a_star->grid[i][j] = a_star->init_grid[i][j];
    reset_spots(a_star);
    create_spots(a_star);
    reset_open_set(a_star->nb_spots, a_star);
    for (int i = 0; i < a_star->grid_height; i++)
        for (int j = 0; j < a_star->grid_width; j++)
            add_neighbors(&a_star->spots[i][j], a_star);
    a_star->winner = 0;
    a_star->current = NULL;
    a_star->end = NULL;
    a_star->open_set[0] = (sfVector2i){0, 0};
    a_star->len_open_set = 0;
    a_star->index_open = 1;
}