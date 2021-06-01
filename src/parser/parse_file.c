/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** parse_file.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "parser.h"

int len_array(char **array)
{
    int i = 0;

    for (i = 0; array[i] != NULL; i++);
    return (i);
}

void free_triple_array(char ***triple_array)
{
    for (int i = 0; triple_array[i] != NULL; i++) {
        for (int j = 0; triple_array[i][j] != NULL; ++j)
            free(triple_array[i][j]);
        free(triple_array[i]);
    }
    free(triple_array);
}

void free_double_array(char **array)
{
    for (int i = 0; array[i] != NULL ; ++i)
        free(array[i]);
    free(array);
}

char ***init_triple_array(char **array)
{
    int i = 0;
    char ***list_array = malloc(sizeof(char **) * (len_array(array) + 1));

    for (i = 0; array[i] != NULL; i++)
        list_array[i] = split_string_opt(array[i], ' ');
    list_array[i] = NULL;
    return (list_array);
}