/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** draw_hub.c
*/

#include "rpg.h"
#include "weapon.h"
#include "draw.h"
#include "collision.h"
#include "scene.h"
#include "shop.h"
#include "npc.h"
#include "inventory.h"
#include "interface.h"

static void draw_particle(game_t *game, particle_spawner_t *particle_spawner)
{
    for (int i = 0; i < particle_spawner->nb_particles; i++) {
        if (!particle_spawner->arr_particles[i].activated)
            continue;
        sfRenderWindow_drawSprite(game->window,
            particle_spawner->arr_particles[i].sprite, NULL);
    }
}

static void draw_hub_ui(game_t *game)
{
    scene_t scene = game->arr_scenes[game->scene_index];
    sfView *view = sfView_create();

    sfView_setSize(view, (sfVector2f){WINDOW_WIDTH, WINDOW_HEIGHT});
    sfView_setCenter(view, (sfVector2f){WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2});
    sfRenderWindow_setView(game->window, view);
    draw_npc_dialog(game, scene);
    draw_shop(game);
    if (scene.pause)
        sfRenderWindow_drawSprite(game->window, scene.spr_pause, NULL);
    if (game->player.inventory.open)
        sfRenderWindow_drawSprite(game->window,
            game->player.inventory.sprite, NULL);
    if (game->player.inventory.open && game->quest.open)
        sfRenderWindow_drawSprite(game->window, game->quest.sprite, NULL);
    draw_buttons(game, scene, NB_BTN_IN_GAME);
    if (game->player.inventory.open)
        draw_inventory_item(game, &game->player.inventory);
    draw_texts(game, scene);
    sfView_destroy(view);
}

void draw_hub(game_t *game)
{
    scene_t scene = game->arr_scenes[game->scene_index];
    item_t *p_item = game->player.item_equiped;

    sfRenderWindow_drawSprite(game->window, scene.background, NULL);
    draw_npc(game, scene);
    draw_particle(game, &scene.in_game->particle_spawner);
    sfRenderWindow_drawRectangleShape(game->window, game->player.hitbox, NULL);
    sfRenderWindow_drawRectangleShape(game->window, game->seller.hitbox, NULL);
    if (p_item != NULL)
        sfRenderWindow_drawSprite(game->window, p_item->sprite, NULL);
    draw_bullets(game);
    draw_hub_ui(game);
}