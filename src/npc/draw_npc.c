/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** draw_npc.c
*/

#include "rpg.h"
#include "npc.h"
#include "collision.h"

void draw_npc_dialog(game_t *game, scene_t scene)
{
    for (int i = 0; i < NB_NPC; ++i) {
        if (collision_between_rectangle(scene.in_game->arr_npc[i].hitbox,
            game->player.hitbox)) {
            scene.in_game->arr_npc[i].npc_state = IDLE;
            sfRenderWindow_drawSprite(game->window, scene.in_game->arr_npc[i]
                .dialog, NULL);
        } else
            scene.in_game->arr_npc[i].npc_state = WALK;
    }
}

void draw_npc(game_t *game, scene_t scene)
{
    for (int i = 0; i < NB_NPC; ++i) {
        sfRenderWindow_drawRectangleShape(game->window,
            scene.in_game->arr_npc[i].hitbox, NULL);
    }
}