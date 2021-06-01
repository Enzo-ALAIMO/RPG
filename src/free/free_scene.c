/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-mydefender-enzo.alaimo
** File description:
** free_scene.c
*/

#include <stdlib.h>
#include "rpg.h"
#include "free.h"

static void free_button(button_t button)
{
    sfSprite_destroy(button.over_sprite);
    sfSprite_destroy(button.sprite);
    sfRectangleShape_destroy(button.rect);
}

static void free_text(text_t text)
{
    sfText_destroy(text.text);
    free(text.text_content);
}

void free_scene(scene_t scene)
{
    if (scene.arr_buttons != NULL) {
        for (int i = 0; i < scene.nb_buttons; i++)
            free_button(scene.arr_buttons[i]);
        free(scene.arr_buttons);
    }
    if (scene.arr_texts != NULL) {
        for (int i = 0; i < scene.nb_texts; i++)
            free_text(scene.arr_texts[i]);
        free(scene.arr_texts);
    }
    if (scene.background != NULL)
        sfSprite_destroy(scene.background);
    if (scene.clock_dt != NULL)
        sfClock_destroy(scene.clock_dt);
    if (scene.font != NULL)
        sfFont_destroy(scene.font);
}