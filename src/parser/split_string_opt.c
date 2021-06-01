/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** split_string_opt.c
*/

#include <stdlib.h>
#include "my.h"
#include "parser.h"

char *get_words(char *cmd, unsigned int nbr_words, unsigned int nbr)
{
    for (; cmd[nbr + nbr_words] != '\0'; nbr++)
        cmd[nbr] = cmd[nbr + nbr_words];
    cmd[nbr] = '\0';
    return (cmd);
}

static int count_words_opt(char const *str, char const delim)
{
    int	count = 0;

    for (int i = 0; str[i]; i++)
        if (str[i] == delim)
            count++;
    return (count + 1);
}

static int	char_nbr(char const *str, int i, char limit)
{
    int	len = 0;

    while (str[i] != '\0' && str[i] != limit && str[i] != '\t') {
        i++;
        len++;
    }
    return (len);
}

char **split_string_opt(char *str, char limit)
{
    char **tab = NULL;
    int	x = 0, y = 0, i = 0;

    clean_string(str);
    tab = malloc(sizeof(char *) * (count_words_opt(str, limit) + 1));
    tab[x] = malloc(sizeof(char) * (char_nbr(str, i, limit) + 1));
    for (; str[i] != '\0'; i++, y++) {
        if (str[i] == limit) {
            i++;
            tab[x][y] = '\0';
            y = 0;
            x++;
            tab[x] = malloc(sizeof(char) * (char_nbr(str, i, limit) + 1));
        }
        tab[x][y] = str[i];
    }
    tab[x][y] = '\0';
    tab[x + 1] = NULL;
    return (tab);
}