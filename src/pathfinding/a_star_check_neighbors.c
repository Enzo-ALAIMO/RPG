/*
** EPITECH PROJECT, 2020
** solver
** File description:
** a_star_check_neighbors.c
*/

#include <stddef.h>
#include "rpg.h"
#include "pathfinding.h"

static void valid_next_spot(a_star_t *a_star, spot_t *current, spot_t *neighbor)
{
    int temp_g = current->g + heuristic(neighbor, current);

    if (set_include(a_star->open_set, neighbor, a_star->nb_spots) && temp_g <
        neighbor->g)
        neighbor->g = temp_g;
    else {
        neighbor->g = temp_g;
        a_star->open_set = add_to_set(a_star->open_set, neighbor, a_star);
    }
    neighbor->h = heuristic(neighbor, a_star->end);
    neighbor->f = neighbor->g + neighbor->h;
    neighbor->previous = current;
}

void check_neighbors(a_star_t *a_star, spot_t *current)
{
    spot_t *neighbor = NULL;

    for (int i = 0; i < NB_NEIGHBORS; i++) {
        neighbor = current->neighbors[i];
        if (neighbor == NULL)
            continue;
        if (!neighbor->is_closed && !neighbor->is_wall)
            valid_next_spot(a_star, current, neighbor);
    }
}