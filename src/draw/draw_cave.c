/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** draw_cave.c
*/

#include "rpg.h"
#include "weapon.h"
#include "draw.h"
#include "scene.h"
#include "enemy.h"
#include "inventory.h"
#include "interface.h"

static void draw_sprite_cave(game_t *game, scene_t scene, int i, int j)
{
    switch (scene.map->grid[i][j]) {
        case 'F':
            sfSprite_setPosition(scene.map->arr_sprites[S_FLOOR],
            (sfVector2f){j * 64, i * 64});
            sfRenderWindow_drawSprite(game->window,
            scene.map->arr_sprites[S_FLOOR], NULL);
            break;
        case 'W':
            sfSprite_setPosition(scene.map->arr_sprites[S_WALL],
            (sfVector2f){j * 64, i * 64});
            sfRenderWindow_drawSprite(game->window,
            scene.map->arr_sprites[S_WALL], NULL);
            break;
        case '.':
            sfSprite_setPosition(scene.map->arr_sprites[S_VOID],
            (sfVector2f){j * 64, i * 64});
            sfRenderWindow_drawSprite(game->window,
            scene.map->arr_sprites[S_VOID], NULL);
            break;
    }
}

static void draw_hub_ui(game_t *game)
{
    scene_t scene = game->arr_scenes[game->scene_index];
    sfView *view = sfView_create();

    sfView_setSize(view, (sfVector2f){WINDOW_WIDTH, WINDOW_HEIGHT});
    sfView_setCenter(view, (sfVector2f){WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2});
    sfRenderWindow_setView(game->window, view);
    if (scene.pause)
        sfRenderWindow_drawSprite(game->window, scene.spr_pause, NULL);
    if (game->player.inventory.open)
        sfRenderWindow_drawSprite(game->window,
            game->player.inventory.sprite, NULL);
    if (game->player.inventory.open && game->quest.open)
        sfRenderWindow_drawSprite(game->window, game->quest.sprite, NULL);
    draw_buttons(game, scene, NB_BTN_CAVE);
    if (game->player.inventory.open)
        draw_inventory_item(game, &game->player.inventory);
    draw_texts(game, scene);
    sfView_destroy(view);
}

void draw_cave(game_t *game)
{
    scene_t scene = game->arr_scenes[game->scene_index];
    item_t *p_item = game->player.item_equiped;

    for (int i = 0; i < scene.map->height; ++i)
        for (int j = 0; j < scene.map->width; ++j)
            draw_sprite_cave(game, scene, i, j);
    draw_enemy(game, scene);
    sfRenderWindow_drawRectangleShape(game->window, game->player.hitbox, NULL);
    if (p_item != NULL)
        sfRenderWindow_drawSprite(game->window, p_item->sprite, NULL);
    draw_bullets(game);
    draw_hub_ui(game);
}