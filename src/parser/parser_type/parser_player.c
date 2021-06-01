/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** parser_player.c
*/

#include <stdio.h>
#include "my.h"
#include "parser.h"
#include "rpg.h"

static player_t player_parse_line(char ***array)
{
    player_t player = {0};

    for (int i = 0; array[i] != NULL; i++) {
        for (int j = 0; array[i][j] != NULL; j++) {
            if (!my_strcmp(array[i][j], "player")) {
                init_player(array[i], &player);
            }
        }
    }
    return (player);
}

player_t create_player_parser(char *arg)
{
    player_t player = {0};
    char *str = load_file(arg);
    char **array = split_string_opt(str, '\n');
    char ***triple_array = init_triple_array(array);

    player = player_parse_line(triple_array);
    free_triple_array(triple_array);
    free_double_array(array);
    free(str);
    return (player);
}