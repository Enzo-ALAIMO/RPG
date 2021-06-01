/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** get_float.c
*/

#include "my.h"

static int check_only_zero(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] != '0')
            return (0);
    return (1);
}

float get_float(char *str)
{
    float integer = my_getnbr(str);
    float decimal = 0;

    for (; *str != '.'; str++);
    str++;
    if (check_only_zero(str))
        return (integer);
    decimal = my_getnbr(str);
    if (integer >= 0)
        decimal = decimal / (10 ^ my_strlen(str)) * 1;
    else
        decimal = decimal / (10 ^ my_strlen(str)) * -1;
    return (integer + decimal);
}