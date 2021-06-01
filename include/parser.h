/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** parser.h
*/

#ifndef PARSER_H
#define PARSER_H

#include "rpg.h"

static const int SIZE = 4096;

sfRectangleShape *create_hitbox(sfVector2f position, sfVector2f size);
char *load_file(char const *filepath);
char **split_string_opt(char *str, char limit);
char *get_words(char *cmd, unsigned int nbr_words, unsigned int nbr);
int len_array(char **array);
void free_triple_array(char ***triple_array);
void free_double_array(char **array);
char ***init_triple_array(char **array);
player_t create_player_parser(char *arg);
particle_spawner_t create_particle_spawner_parser(char *arg);
sfRectangleShape **create_hitbox_parser(char *arg);
button_t *create_button_parser(char *arg);
text_t *create_text_parser(char *arg);
void init_button(char **values, button_t *button);
void init_player(char **values, player_t *player);
void init_particle_spawner(char **values, particle_spawner_t *particle_spawner);
sfRectangleShape **init_hitbox(char **values, sfRectangleShape **arr_hitbox,
    int size);
void init_text(char **values, text_t *text);
char *clean_string(char *str);

#endif