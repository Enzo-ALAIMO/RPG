/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** init_button.c
*/

#include "rpg.h"
#include "my.h"
#include "util.h"
#include "interface.h"
#include "buttons_functions_list.h"

void init_button(char **values, button_t *button)
{
    sfVector2u texture_size = (sfVector2u) {0, 0};

    button->pos.x = get_float(values[1]);
    button->pos.y = get_float(values[2]);
    button->size.x = get_float(values[3]);
    button->size.x = get_float(values[4]);
    button->rect = sfRectangleShape_create();
    button->sprite = create_sprite_button(values[5], button->pos);
    button->click_sprite = create_sprite_button(values[6], button->pos);
    button->over_sprite = create_sprite_button(values[7], button->pos);
    button->on_click = buttons_functions[my_getnbr(values[8])];
    texture_size = sfTexture_getSize(sfSprite_getTexture(button->sprite));
    button->pos.x -= texture_size.x / 2;
    button->pos.y -= texture_size.y / 2;
    button->size.x = texture_size.x;
    button->size.y = texture_size.y;
    button->draw = my_getnbr(values[9]);
    sfRectangleShape_setPosition(button->rect, button->pos);
    sfRectangleShape_setSize(button->rect, button->size);
}