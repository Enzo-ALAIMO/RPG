/*
** EPITECH PROJECT, 2020
** solver
** File description:
** a_star_util.c
*/

#include "rpg.h"

int get_len_set(sfVector2i *set, int size)
{
    int len = 0;

    for (int i = 0; set[i].x != -1; i++) {
        if (i == size - 1)
            break;
        len++;
    }
    return (len);
}

int heuristic(spot_t *spot_one, spot_t *spot_two)
{
    return (((spot_two->j - spot_one->j) * (spot_two->j - spot_one->j))
        + ((spot_two->i - spot_one->i) * (spot_two->i - spot_one->i)));
}

bool set_include(sfVector2i *set, spot_t *spot, int size)
{
    int len_set = get_len_set(set, size);

    for (int i = 0; i < len_set; i++) {
        if (set[i].x == spot->j && set[i].y == spot->i)
            return (true);
        if (set[i].x == -1 && set[i].y == -1)
            break;
    }
    return (false);
}

sfVector2i *add_to_set(sfVector2i *set, spot_t *spot, a_star_t *a_star)
{
    if (set[a_star->index_open].x == -1 && set[a_star->index_open].y == -1) {
        set[a_star->index_open].y = spot->i;
        set[a_star->index_open].x = spot->j;
        a_star->index_open++;
    }
    return (set);
}

sfVector2i *remove_from_set(sfVector2i *set, spot_t *spot, int size)
{
    bool found = false;
    int len_set = get_len_set(set, size);

    for (int i = 0; i < len_set; i++) {
        if (set[i].x == spot->j && set[i].y == spot->i)
            found = true;
        if (found) {
            set[i] = (sfVector2i){-1, -1};
            if (i + 1 < len_set && set[i + 1].x == -1 && set[i + 1].y == -1)
                break;
            else if (i + 1 < len_set)
                set[i] = set[i + 1];
        }
    }
    return (set);
}