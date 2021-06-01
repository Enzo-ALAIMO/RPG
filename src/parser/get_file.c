/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** get_file.c
*/

#include <stdio.h>
#include "my.h"
#include "parser.h"
#include "rpg.h"

void parse_line(char ***array)
{
    int i;
    int j;
    button_t button;

    for (i = 0; array[i] != NULL; i++) {
        for (j = 0; array[i][j] != NULL; j++) {
            if (!my_strcmp(array[i][j], "bouton")) {
                init_button(array[i], &button);
            }
        }
    }
}