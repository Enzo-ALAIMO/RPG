/*
** EPITECH PROJECT, 2020
** solver
** File description:
** a_star.c
*/

#include <stdlib.h>
#include "rpg.h"
#include "pathfinding.h"
#include "my.h"

static sfVector2i *init_set(int size)
{
    sfVector2i *arr = malloc(sizeof(sfVector2i) * (size + 1));

    if (arr == NULL)
        return (NULL);
    for (int i = 0; i < size; ++i)
        arr[i] = (sfVector2i){-1, -1};
    return (arr);
}

a_star_t init_a_star(char const *filepath, map_t *map)
{
    a_star_t a_star = {0};

    if (filepath != NULL)
        load_grid(filepath, &a_star);
    else
        load_map(map, &a_star);
    get_nb_spots(&a_star);
    create_spots(&a_star);
    a_star.open_set = init_set(a_star.nb_spots);
    for (int i = 0; i < a_star.grid_height; i++)
        for (int j = 0; j < a_star.grid_width; j++)
            add_neighbors(&a_star.spots[i][j], &a_star);
    a_star.winner = 0;
    a_star.end = NULL;
    a_star.open_set[0] = (sfVector2i){0, 0};
    a_star.len_open_set = 0;
    a_star.index_open = 1;
    return (a_star);
}

static bool is_finished(a_star_t *a_star)
{
    spot_t *temp = NULL;

    a_star->current = &a_star->spots[a_star->open_set[a_star->winner].y]
        [a_star->open_set[a_star->winner].x];
    if (a_star->open_set[a_star->winner].x == a_star->end->j &&
        a_star->open_set[a_star->winner].y == a_star->end->i) {
        temp = &a_star->spots[a_star->open_set[a_star->winner].y]
            [a_star->open_set[a_star->winner].x];
        while (temp->previous) {
            a_star->grid[temp->i][temp->j] = 'o';
            temp = temp->previous;
        }
        temp = &a_star->spots[a_star->open_set[a_star->winner].y]
            [a_star->open_set[a_star->winner].x];
        a_star->path_len = len_path(a_star);
        get_path(a_star, temp);
        return (true);
    }
    return (false);
}

static int a_star_loop(a_star_t *a_star)
{
    a_star->len_open_set = get_len_set(a_star->open_set, a_star->nb_spots);
    if (a_star->len_open_set > 0) {
        a_star->winner = 0;
        for (int i = 0; i < a_star->len_open_set; i++)
            if (a_star->spots[a_star->open_set[i].y][a_star->open_set[i].x].f <
                a_star->spots[a_star->open_set[a_star->winner].y]
                [a_star->open_set[a_star->winner].x].f)
                a_star->winner = i;
        if (is_finished(a_star))
            return (1);
        a_star->open_set = remove_from_set(a_star->open_set, a_star->current,
            a_star->nb_spots);
        a_star->index_open--;
        a_star->current->is_closed = true;
        check_neighbors(a_star, a_star->current);
    } else
        return (2);
    return (0);
}

void start_a_star(a_star_t *a_star, sfVector2i start, sfVector2i goal)
{
    reset_a_star(a_star);
    a_star->end = &a_star->spots[goal.y][goal.x];
    a_star->open_set[0] = (sfVector2i){start.x, start.y};
    while (true)
        if (a_star_loop(a_star) != 0)
            break;
}