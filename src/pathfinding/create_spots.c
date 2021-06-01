/*
** EPITECH PROJECT, 2020
** solver
** File description:
** create_spots.c
*/

#include <stdlib.h>
#include "rpg.h"
#include "pathfinding.h"
#include "map.h"

static int malloc_spots(a_star_t *a_star)
{
    a_star->spots = malloc(sizeof(spot_t *) * a_star->grid_height);
    if (a_star->spots == NULL)
        return (84);
    for (int i = 0; i < a_star->grid_height; i++) {
        a_star->spots[i] = malloc(sizeof(spot_t) * a_star->grid_width);
        if (a_star->spots[i] == NULL)
            return (84);
        for (int j = 0; j < a_star->grid_width; ++j) {
            a_star->spots[i][j] = (spot_t){0};
        }
    }
    return (0);
}

static int create_spot(a_star_t *a_star, int i, int j)
{
    if (a_star->grid[i][j] == WALL || a_star->grid[i][j] == VOID)
        a_star->spots[i][j].is_wall = true;
    else
        a_star->spots[i][j].is_wall = false;
    a_star->spots[i][j].i = i;
    a_star->spots[i][j].j = j;
    a_star->spots[i][j].f = 0;
    a_star->spots[i][j].g = 0;
    a_star->spots[i][j].h = 0;
    a_star->spots[i][j].previous = NULL;
    a_star->spots[i][j].neighbors = malloc(sizeof(spot_t) * NB_NEIGHBORS);
    if (a_star->spots[i][j].neighbors == NULL)
        return (84);
    for (int k = 0; k < NB_NEIGHBORS; ++k)
        a_star->spots[i][j].neighbors[k] = NULL;
    return (0);
}

int create_spots(a_star_t *a_star)
{
    if (malloc_spots(a_star) == 84)
        return (84);
    for (int i = 0; i < a_star->grid_height; i++)
        for (int j = 0; j < a_star->grid_width; j++)
            if (create_spot(a_star, i, j) == 84)
                return (84);
    return (0);
}