/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** create_settings_buttons.c
*/

#include "rpg.h"
#include "scene.h"
#include "interface.h"
#include "buttons_functions.h"

static button_t *create_sett_buttons_part_two(button_t *arr_buttons,
    char **path)
{
    arr_buttons[LOW_BTN_SETT] = button_init((sfVector2f){810, 630},
    set_btn_path(path, IMG_S_R_L, IMG_S_OVER, IMG_S_CLICK), &change_res);
    arr_buttons[MEDIUM_BTN_SETT] = button_init((sfVector2f){810, 730},
    set_btn_path(path, IMG_S_R_M, IMG_S_OVER, IMG_S_CLICK), &change_res);
    arr_buttons[HIGH_BTN_SETT] = button_init((sfVector2f){810, 830},
    set_btn_path(path, IMG_S_R_H, IMG_S_OVER, IMG_S_CLICK), &change_res);
    arr_buttons[FPS_L_BTN_SETT] = button_init((sfVector2f){1120, 630},
    set_btn_path(path, IMG_S_F_L, IMG_S_OVER, IMG_S_CLICK), &change_fps);
    arr_buttons[FPS_M_BTN_SETT] = button_init((sfVector2f){1120, 730},
    set_btn_path(path, IMG_S_F_M, IMG_S_OVER, IMG_S_CLICK), &change_fps);
    arr_buttons[FPS_H_BTN_SETT] = button_init((sfVector2f){1120, 830},
    set_btn_path(path, IMG_S_F_H, IMG_S_OVER, IMG_S_CLICK), &change_fps);
    return (arr_buttons);
}

button_t *create_sett_buttons(scene_t scene)
{
    button_t *arr_buttons = malloc(sizeof(button_t) * scene.nb_buttons);
    char *path[] = {"./assets/menu/set_return.png",
        "./assets/menu/v_plus.png", "./assets/menu/v_moins.png",
        "./assets/menu/res_l.png", "./assets/menu/res_m.png",
        "./assets/menu/res_h.png", "./assets/menu/fps_l.png",
        "./assets/menu/fps_m.png", "./assets/menu/fps_h.png",
        "./assets/menu/set_over.png", "./assets/menu/set_click.png",
        "./assets/menu/v_over.png", "./assets/menu/v_click.png"};

    arr_buttons[RETURN_BTN_SETT] = button_init((sfVector2f){960, 910},
    set_btn_path(path, IMG_S_RETURN, IMG_S_OVER, IMG_S_CLICK), &change_scene);
    arr_buttons[VOL_UP_BTN_SETT] = button_init((sfVector2f){1160, 370},
        set_btn_path(path, IMG_S_PLUS, IMG_S_V_OVER, IMG_S_V_CLICK),
        &change_volume);
    arr_buttons[VOL_DOWN_BTN_SETT] = button_init((sfVector2f){758, 370},
        set_btn_path(path, IMG_S_MOINS, IMG_S_V_OVER, IMG_S_V_CLICK),
        &change_volume);
    arr_buttons = create_sett_buttons_part_two(arr_buttons, path);
    return (arr_buttons);
}