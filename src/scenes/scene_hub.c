/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** scene_hub.c
*/

#include "rpg.h"
#include "event.h"
#include "update.h"
#include "draw.h"
#include "parser.h"
#include "util.h"
#include "pathfinding.h"
#include "npc.h"

static sfRectangleShape *create_cave_entry(void)
{
    sfRectangleShape *hitbox = sfRectangleShape_create();

    sfRectangleShape_setSize(hitbox, (sfVector2f){40, 40});
    sfRectangleShape_setPosition(hitbox, (sfVector2f){940, 30});
    sfRectangleShape_setFillColor(hitbox, sfTransparent);
    sfRectangleShape_setOutlineThickness(hitbox, 1);
    sfRectangleShape_setOutlineColor(hitbox, sfBlack);
    return (hitbox);
}

static in_game_t *create_in_game(void)
{
    in_game_t *in_game = malloc(sizeof(in_game_t));

    if (in_game == NULL)
        return (NULL);
    in_game->particle_spawner = create_particle_spawner_parser("test.txt");
    in_game->a_star = init_a_star("./assets/hub/path_hub.txt", NULL);
    in_game->arr_hitbox = create_hitbox_parser("hitbox_hub.txt");
    in_game->cave_entry = create_cave_entry();
    in_game->arr_npc = malloc(sizeof(npc_t) * NB_NPC);
    in_game->arr_npc[0] = create_npc("./assets/npc/starman_spritesheet.png",
        "./assets/npc/easter_egg.png", (sfVector2f){500, 500});
    in_game->arr_npc[1] = create_npc("./assets/npc/questman_spritesheet.png",
        "./assets/npc/quest.png", (sfVector2f){1000, 500});
    return (in_game);
}

scene_t create_scene_hub(void)
{
    scene_t scene = {0};

    scene.background = create_sprite("./assets/hub/hub.png", (sfVector2f){0, 0}
        , (sfVector2f){1, 1});
    scene.in_game = create_in_game();
    scene.spr_pause = create_sprite("./assets/in_game/pause.png",
        (sfVector2f){0, 0}, (sfVector2f){1, 1});
    scene.arr_buttons = create_button_parser("buttons_in_game.txt");
    scene.arr_texts = create_text_parser("texts.txt");
    scene.clock_dt = sfClock_create();
    scene.event = &event_hub;
    scene.update = &update_hub;
    scene.draw = &draw_hub;
    return (scene);
}