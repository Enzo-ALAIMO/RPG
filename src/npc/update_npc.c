/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** update_npc.c
*/

#include "rpg.h"
#include "pathfinding.h"
#include "util.h"
#include "npc.h"

static sfVector2i get_random_pos(scene_t scene)
{
    sfVector2i pos = {0, 0};
    int random_i = 0;
    int random_j = 0;

    while (true) {
        random_i = get_random_int(scene.in_game->a_star.grid_height);
        random_j = get_random_int(scene.in_game->a_star.grid_width);
        if (random_i <= 2 || random_i >= 67 || random_j <= 2 || random_j >= 118)
            continue;
        if (!scene.in_game->a_star.spots[random_i][random_j].is_wall)
            break;
    }
    pos.x = random_j;
    pos.y = random_i;
    return (pos);
}

static void reset_path(scene_t scene, npc_t *npc)
{
    start_a_star(&scene.in_game->a_star, (sfVector2i){npc->pos.x / 16,
        npc->pos.y / 16}, get_random_pos(scene));
    npc->index_path = 0;
    npc->len_path = scene.in_game->a_star.path_len;
    if (npc->path != NULL)
        free(npc->path);
    npc->path = malloc(sizeof(sfVector2i) * npc->len_path);
    for (int j = 0; j < npc->len_path; ++j)
        npc->path[j] = scene.in_game->a_star.path[j];
}

void update_npc(scene_t scene)
{
    npc_t *npc = NULL;

    for (int i = 0; i < NB_NPC; ++i) {
        npc = &scene.in_game->arr_npc[i];
        switch (npc->npc_state) {
            case IDLE:
                break;
            case WALK:
                if (npc->index_path == npc->len_path)
                    reset_path(scene, npc);
                else
                    move_npc(scene, npc);
                break;
        }
        npc_animation(npc, scene.dt);
    }
}