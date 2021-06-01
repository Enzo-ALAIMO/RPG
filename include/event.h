/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** event.h
*/

#ifndef EVENT_H
#define EVENT_H

#include "rpg.h"

void event_menu(game_t *game);
void event_htp(game_t *game);
void event_settings(game_t *game);
void event_hub(game_t *game);
void event_pause(game_t *game);
void reset_event_pause(game_t *game);
void event_cave(game_t *game);

#endif