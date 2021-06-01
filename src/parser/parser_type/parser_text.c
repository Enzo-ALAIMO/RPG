/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** parser_text.c
*/

#include <stdlib.h>
#include "my.h"
#include "parser.h"
#include "rpg.h"

static text_t *text_parse_line(char ***array)
{
    int nb_texts = my_getnbr(array[0][1]);
    text_t *arr_texts = malloc(sizeof(text_t) * (nb_texts + 1));
    int index_text = 0;

    for (int i = 0; array[i] != NULL; i++) {
        for (int j = 0; array[i][j] != NULL; j++) {
            if (!my_strcmp(array[i][j], "text")) {
                init_text(array[i], &arr_texts[index_text++]);
            }
        }
    }
    return (arr_texts);
}

text_t *create_text_parser(char *arg)
{
    text_t *arr_texts = NULL;
    char *str = load_file(arg);
    char **array = split_string_opt(str, '\n');
    char ***triple_array = init_triple_array(array);

    arr_texts = text_parse_line(triple_array);
    free_triple_array(triple_array);
    free_double_array(array);
    free(str);
    return (arr_texts);
}