/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** scene_how_to_play.c
*/

#include <stdlib.h>
#include "rpg.h"
#include "interface.h"
#include "event.h"
#include "draw.h"
#include "buttons_functions.h"
#include "scene.h"
#include "update.h"

static sfSprite *create_htp_background(void)
{
    sfTexture *texture = sfTexture_createFromFile(
        "./assets/menu/htp_scene.png", NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfFalse);
    return (sprite);
}

static button_t *create_buttons(scene_t scene)
{
    button_t *arr_buttons = malloc(sizeof(button_t) * scene.nb_buttons);
    char *path[] = {"./assets/menu/set_return.png",
        "./assets/menu/set_over.png", "./assets/menu/set_click.png"};

    if (arr_buttons == NULL)
        return (NULL);
    arr_buttons[RETURN_BTN_HTP] = button_init((sfVector2f){100, 100},
        set_btn_path(path, 0, 1, 2), &change_scene);
    return (arr_buttons);
}

scene_t create_scene_htp(void)
{
    scene_t scene = {0};

    scene.nb_buttons = NB_BTN_HTP;
    scene.arr_buttons = create_buttons(scene);
    scene.background = create_htp_background();
    scene.clock_dt = sfClock_create();
    scene.event = &event_htp;
    scene.update = &update_htp;
    scene.draw = &draw_htp;
    return (scene);
}