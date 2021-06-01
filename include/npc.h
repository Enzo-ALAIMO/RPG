/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** npc.h
*/

#ifndef NPC_H
#define NPC_H

#include "rpg.h"

static const int NB_NPC = 2;

enum npc_state {
    IDLE,
    WALK,
};

npc_t create_npc(char const *filepath, char const *filepath_dialog, sfVector2f
    spawn_pos);
void draw_npc(game_t *game, scene_t scene);
void draw_npc_dialog(game_t *game, scene_t scene);
void update_npc(scene_t scene);
void npc_animation(npc_t *npc, float dt);
void move_npc(scene_t scene, npc_t *npc);

#endif