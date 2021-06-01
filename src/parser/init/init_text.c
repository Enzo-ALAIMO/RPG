/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** init_text.c
*/

#include "rpg.h"
#include "my.h"
#include "util.h"
#include "interface.h"

void init_text(char **values, text_t *text)
{
    text->pos.x = my_getnbr(values[1]);
    text->pos.y = my_getnbr(values[2]);
    text->text_content = my_strdup(values[3]);
    text->draw = my_getnbr(values[4]);
    text->text = sfText_create();
    text->font = sfFont_createFromFile("./assets/font/font.TTF");
    sfText_setFont(text->text, text->font);
    sfText_setPosition(text->text, text->pos);
    sfText_setString(text->text, text->text_content);
    sfText_setCharacterSize(text->text, my_getnbr(values[5]));
}