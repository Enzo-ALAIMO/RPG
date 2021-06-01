/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** buttons_functions.h
*/

#ifndef BUTTONS_FUNCTIONS_H
#define BUTTONS_FUNCTIONS_H

#include <SFML/Graphics.h>

void exit_game(sfRenderWindow *window);
void change_scene(game_t *game, int index);
void empty(void);
void resume_game(game_t *game);
void return_to_menu(game_t *game, int scene_index);
void change_res(game_t *game, unsigned int x, unsigned int y);
void change_fps(game_t *game, unsigned int fps);
void change_volume(game_t *game, int value);
void toggle_quest(game_t *game);

#endif