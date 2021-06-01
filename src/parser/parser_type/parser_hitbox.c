/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** parser_hitbox.c
*/

#include <stdio.h>
#include "my.h"
#include "parser.h"
#include "rpg.h"

static sfRectangleShape **hitbox_parse_line(char ***array)
{
    int nb_hitbox = my_getnbr(array[0][1]);
    sfRectangleShape **arr_hitbox = malloc(sizeof(*arr_hitbox) * (nb_hitbox +
        1));

    for (int i = 0; i < nb_hitbox + 1; ++i)
        arr_hitbox[i] = NULL;
    for (int i = 0; array[i] != NULL; i++) {
        for (int j = 0; array[i][j] != NULL; j++) {
            if (!my_strcmp(array[i][j], "hitbox")) {
                arr_hitbox = init_hitbox(array[i], arr_hitbox, nb_hitbox);
            }
        }
    }
    return (arr_hitbox);
}

sfRectangleShape **create_hitbox_parser(char *arg)
{
    sfRectangleShape **arr_hitbox = NULL;
    char *str = load_file(arg);
    char **array = split_string_opt(str, '\n');
    char ***triple_array = init_triple_array(array);

    arr_hitbox = hitbox_parse_line(triple_array);
    free_triple_array(triple_array);
    free_double_array(array);
    free(str);
    return (arr_hitbox);
}