/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** parser_button.c
*/

#include <stdlib.h>
#include "my.h"
#include "parser.h"
#include "rpg.h"

static button_t *button_parse_line(char ***array)
{
    int nb_buttons = my_getnbr(array[0][1]);
    button_t *arr_buttons = malloc(sizeof(button_t) * (nb_buttons + 1));
    int index_button = 0;

    for (int i = 0; i < nb_buttons + 1; ++i) {
        arr_buttons[i] = (button_t) {0};
        arr_buttons[i].sprite = NULL;
    }
    for (int i = 0; array[i] != NULL; i++) {
        for (int j = 0; array[i][j] != NULL; j++) {
            if (!my_strcmp(array[i][j], "button")) {
                init_button(array[i], &arr_buttons[index_button++]);
            }
        }
    }
    return (arr_buttons);
}

button_t *create_button_parser(char *arg)
{
    button_t *arr_buttons = NULL;
    char *str = load_file(arg);
    char **array = split_string_opt(str, '\n');
    char ***triple_array = init_triple_array(array);

    arr_buttons = button_parse_line(triple_array);
    free_triple_array(triple_array);
    free_double_array(array);
    free(str);
    return (arr_buttons);
}