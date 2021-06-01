/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** pathfinding.h
*/
#ifndef PATHFINDING_H
#define PATHFINDING_H

#include "rpg.h"

static const int NB_NEIGHBORS = 4;

a_star_t init_a_star(char const *filepath, map_t *map);
void load_grid(char const *filepath, a_star_t *a_star);
void load_map(map_t *map, a_star_t *a_star);
int create_spots(a_star_t *a_star);
void free_manager(a_star_t *a_star);
void start_a_star(a_star_t *a_star, sfVector2i start, sfVector2i goal);
void check_neighbors(a_star_t *a_star, spot_t *current);
int get_len_set(sfVector2i *set, int size);
int heuristic(spot_t *spot_one, spot_t *spot_two);
bool set_include(sfVector2i *set, spot_t *spot, int size);
sfVector2i *add_to_set(sfVector2i *set, spot_t *spot, a_star_t *a_star);
sfVector2i *remove_from_set(sfVector2i *set, spot_t *spot, int size);
int get_nb_neighbors(spot_t **neighbors);
void add_neighbors(spot_t *spot, a_star_t *a_star);
void get_nb_spots(a_star_t *a_star);
int len_path(a_star_t *a_star);
void get_path(a_star_t *a_star, spot_t *temp);
void reset_a_star(a_star_t *a_star);

#endif