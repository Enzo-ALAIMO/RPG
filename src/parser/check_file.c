/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** check_file.c
*/

#include <stdlib.h>
#include "my.h"
#include "parser.h"

static void replace_tab(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '\t')
            str[i] = ' ';
}

char *without_n(char *cmd)
{
    char *str = malloc(sizeof(char) * my_strlen(cmd));

    for (int i = 0; i < my_strlen(cmd) - 1; i++)
        str[i] = cmd[i];
    return (str);
}

static void delete_space(char *str)
{
    int	i = 0;

    for (i = 0; str[i] != '\0'; i++);
    i--;
    for (; i > 0 && str[i] == ' '; i--)
        str[i] = '\0';
}

char *clean_string(char *str)
{
    int	i = 0;

    replace_tab(str);
    delete_space(str);
    for (i = 0; str[i] == ' '; i++)
    get_words(str, i, 0);
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' ) {
            i++;
            for (; str[i] == ' ';)
                get_words(str, 1, i);
        }
    }
    i--;
    return (str);
}
