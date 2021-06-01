/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** scene_settings.c
*/

#include <stdlib.h>
#include "rpg.h"
#include "interface.h"
#include "event.h"
#include "draw.h"
#include "buttons_functions.h"
#include "scene.h"
#include "update.h"

static sfSprite *create_settings_background(void)
{
    sfTexture *texture = sfTexture_createFromFile(
        "./assets/menu/settings_bg.png", NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfFalse);
    return (sprite);
}

scene_t create_scene_settings(void)
{
    scene_t scene = {0};

    scene.nb_buttons = NB_BTN_SETT;
    scene.arr_buttons = create_sett_buttons(scene);
    scene.background = create_settings_background();
    scene.clock_dt = sfClock_create();
    scene.event = &event_settings;
    scene.update = &update_settings;
    scene.draw = &draw_settings;
    return (scene);
}