/*
** EPITECH PROJECT, 2020
** Projects
** File description:
** map.h
*/

#ifndef MAP_H
#define MAP_H

#include "rpg.h"

static const int MAP_HEIGHT = 50;
static const int MAP_WIDTH = 50;
static const int LOOP = 2000;

static const char FLOOR = 'F';
static const char WALL = 'W';
static const char VOID = '.';

void generate_map(map_t *map);
map_t *create_map(void);

#endif