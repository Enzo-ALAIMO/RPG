/*
** EPITECH PROJECT, 2020
** solver
** File description:
** add_neighbors.c
*/

#include <stddef.h>
#include "rpg.h"
#include "pathfinding.h"

static void add_to_list(spot_t *spot, spot_t *spot_to_add)
{
    for (int i = 0; i < NB_NEIGHBORS; i++)
        if (spot->neighbors[i] == NULL) {
            spot->neighbors[i] = spot_to_add;
            break;
        }
}

int get_nb_neighbors(spot_t **neighbors)
{
    int nb = 0;

    for (int i = 0; i < NB_NEIGHBORS; i++)
        if (neighbors[i] != NULL)
            nb++;
    return (nb);
}

void add_neighbors(spot_t *spot, a_star_t *a_star)
{
    if (spot->i < a_star->grid_height - 1)
        add_to_list(spot, &a_star->spots[spot->i + 1][spot->j]);
    if (spot->i > 0)
        add_to_list(spot, &a_star->spots[spot->i - 1][spot->j]);
    if (spot->j < a_star->grid_width - 1)
        add_to_list(spot, &a_star->spots[spot->i][spot->j + 1]);
    if (spot->j > 0)
        add_to_list(spot, &a_star->spots[spot->i][spot->j - 1]);
}
