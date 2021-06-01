/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** interface.h
*/

#ifndef INTERFACE_H
#define INTERFACE_H

#include <SFML/Graphics.h>
#include <stdbool.h>
#include "rpg.h"

enum img_path_sett_index {
    IMG_S_RETURN,
    IMG_S_PLUS,
    IMG_S_MOINS,
    IMG_S_R_L,
    IMG_S_R_M,
    IMG_S_R_H,
    IMG_S_F_L,
    IMG_S_F_M,
    IMG_S_F_H,
    IMG_S_OVER,
    IMG_S_CLICK,
    IMG_S_V_OVER,
    IMG_S_V_CLICK,
    NB_IMG_SETTINGS
};

btn_path_t set_btn_path(char **path, int sprite, int sprite_over,
    int sprite_click);
button_t button_init(sfVector2f pos, btn_path_t btn_path, void (*on_click)());
bool button_is_hover(button_t *button, sfVector2f click_position, game_t *game);
text_t text_init(scene_t const scene, sfVector2f const pos,
    char const *content);
void check_button_one_arg(button_t *button, game_t *game, sfVector2f
    mouse_pos, int arg);
void check_button_two_arg(button_t *button, game_t *game, sfVector2f
    mouse_pos, sfVector2i args);
void check_button_zero_arg(button_t *button, game_t *game, sfVector2f
    mouse_pos);
sfSprite *create_sprite_button(char const *path, sfVector2f pos);
void draw_texts(game_t *game, scene_t scene);
void toggle_texts(game_t *game, scene_t *scene);

#endif