/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** movement_npc.c
*/

#include "rpg.h"
#include "npc.h"

static void move(npc_t *npc, float dt, int x_or_y, int dir)
{
    if (x_or_y == 0) {
        npc->pos.x += dir * (npc->speed * dt);
        if (dir == -1)
            sfRectangleShape_setOrigin(npc->hitbox, (sfVector2f){40, 0});
        else
            sfRectangleShape_setOrigin(npc->hitbox, (sfVector2f){0, 0});
        sfRectangleShape_setScale(npc->hitbox, (sfVector2f){dir, 1});
    } else if (x_or_y == 1)
        npc->pos.y += dir * (npc->speed * dt);
    sfRectangleShape_setPosition(npc->hitbox, npc->pos);
}

static bool move_vertical(scene_t scene, npc_t *npc)
{
    if (roundf(npc->pos.y) <= (npc->path[npc->index_path].y * 16) + 5
        && roundf(npc->pos.y) >= (npc->path[npc->index_path].y * 16) - 5)
        return (false);
    if (roundf(npc->pos.y) < npc->path[npc->index_path].y * 16) {
        move(npc, scene.dt, 1, 1);
        return (true);
    } else if (roundf(npc->pos.y) > npc->path[npc->index_path].y * 16) {
        move(npc, scene.dt, 1, -1);
        return (true);
    }
    return (false);
}

static void move_horizontal(scene_t scene, npc_t *npc)
{
    if (roundf(npc->pos.x) <= (npc->path[npc->index_path].x * 16) + 5
        && roundf(npc->pos.x) >= (npc->path[npc->index_path].x * 16) - 5)
        return;
    if (roundf(npc->pos.x) < npc->path[npc->index_path].x * 16)
        move(npc, scene.dt, 0, 1);
    else if (roundf(npc->pos.x) > npc->path[npc->index_path].x * 16)
        move(npc, scene.dt, 0, -1);
}

void move_npc(scene_t scene, npc_t *npc)
{
    if (roundf(npc->pos.x) <= (npc->path[npc->index_path].x * 16) + 5
        && roundf(npc->pos.x) >= (npc->path[npc->index_path].x * 16) - 5
        && roundf(npc->pos.y) <= (npc->path[npc->index_path].y * 16) + 5
        && roundf(npc->pos.y) >= (npc->path[npc->index_path].y * 16) - 5) {
        npc->index_path++;
        return;
    }
    if (move_vertical(scene, npc))
        return;
    move_horizontal(scene, npc);
    sfRectangleShape_setPosition(npc->hitbox, npc->pos);
}