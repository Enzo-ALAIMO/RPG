/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-mydefender-enzo.alaimo
** File description:
** scene.c
*/

#include <stdlib.h>
#include "rpg.h"
#include "interface.h"
#include "event.h"
#include "draw.h"
#include "buttons_functions.h"
#include "scene.h"
#include "update.h"

static sfSprite *create_menu_background(void)
{
    sfTexture *texture = sfTexture_createFromFile(
        "./assets/menu/bg_menu.png", NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfFalse);
    return (sprite);
}

static button_t *create_buttons(scene_t scene)
{
    button_t *arr_buttons = malloc(sizeof(button_t) * scene.nb_buttons);
    char *path[] = {"./assets/menu/play.png", "./assets/menu/over_exit.png",
        "./assets/menu/over.png", "./assets/menu/click.png",
        "./assets/menu/click_exit.png", "./assets/menu/settings.png",
        "./assets/menu/htp.png", "./assets/menu/exit.png"};

    if (arr_buttons == NULL)
        return (NULL);
    arr_buttons[PLAY_BTN_MENU] = button_init((sfVector2f){WINDOW_WIDTH / 2,
        WINDOW_HEIGHT / 2 - 250}, set_btn_path(path, 0, 2, 3), &change_scene);
    arr_buttons[HTP_BTN_MENU] = button_init((sfVector2f){WINDOW_WIDTH / 2,
        WINDOW_HEIGHT / 2 - 0}, set_btn_path(path, 6, 2, 3), &change_scene);
    arr_buttons[SETTINGS_BTN_MENU] = button_init((sfVector2f){WINDOW_WIDTH / 2,
        WINDOW_HEIGHT / 2 + 250}, set_btn_path(path, 5, 2, 3), &change_scene);
    arr_buttons[EXIT_BTN_MENU] = button_init((sfVector2f){WINDOW_WIDTH - 100,
        WINDOW_HEIGHT - 150}, set_btn_path(path, 7, 1, 4), &exit_game);
    return (arr_buttons);
}

scene_t create_scene_menu(void)
{
    scene_t scene = {0};

    scene.nb_buttons = NB_BTN_MENU;
    scene.arr_buttons = create_buttons(scene);
    scene.background = create_menu_background();
    scene.clock_dt = sfClock_create();
    scene.event = &event_menu;
    scene.update = &update_menu;
    scene.draw = &draw_menu;
    return (scene);
}