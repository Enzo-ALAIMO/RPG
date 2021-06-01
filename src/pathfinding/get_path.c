/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** get_path.c
*/

#include "rpg.h"
#include "pathfinding.h"

int len_path(a_star_t *a_star)
{
    int len = 0;

    for (int i = 0; i < a_star->grid_height; ++i)
        for (int j = 0; j < a_star->grid_width; ++j)
            if (a_star->grid[i][j] == 'o')
                len++;
    return (len);
}

void get_path(a_star_t *a_star, spot_t *temp)
{
    int index = a_star->path_len - 1;

    a_star->path = malloc(sizeof(sfVector2i) * a_star->path_len);
    if (a_star->path == NULL)
        return;
    while (temp->previous) {
        a_star->path[index--] = (sfVector2i){temp->j, temp->i};
        temp = temp->previous;
    }
}