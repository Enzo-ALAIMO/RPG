/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** parser_particle_spawner.c
*/

#include <stdio.h>
#include "my.h"
#include "parser.h"
#include "rpg.h"

static particle_spawner_t particle_spawner_parse_line(char ***array)
{
    particle_spawner_t particle_spawner = {0};

    for (int i = 0; array[i] != NULL; i++) {
        for (int j = 0; array[i][j] != NULL; j++) {
            if (!my_strcmp(array[i][j], "particle_spawner")) {
                init_particle_spawner(array[i], &particle_spawner);
            }
        }
    }
    return (particle_spawner);
}

particle_spawner_t create_particle_spawner_parser(char *arg)
{
    particle_spawner_t particle_spawner = {0};
    char *str = load_file(arg);
    char **array = split_string_opt(str, '\n');
    char ***triple_array = init_triple_array(array);

    particle_spawner = particle_spawner_parse_line(triple_array);
    free_triple_array(triple_array);
    free_double_array(array);
    free(str);
    return (particle_spawner);
}