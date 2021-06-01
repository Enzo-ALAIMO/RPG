/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** draw_shop.c
*/

#include "rpg.h"
#include "scene.h"
#include "collision.h"

static void draw_button(game_t *game)
{
    for (int i = 3; i < 7; i++) {
        game->arr_scenes[game->scene_index].arr_buttons[i].draw = true;
    }
}

static void undraw_button(game_t *game)
{
    for (int i = 3; i < 7; i++) {
        game->arr_scenes[game->scene_index].arr_buttons[i].draw = false;
    }
}

static void set_draw_item(game_t *game)
{
    if (game->seller.equipements.button[0] == true)
        sfRenderWindow_drawSprite(game->window,
        game->seller.equipements.first_gun, NULL);
    if (game->seller.equipements.button[1] == true)
        sfRenderWindow_drawSprite(game->window,
        game->seller.equipements.second_gun, NULL);
    if (game->seller.equipements.button[2] == true)
        sfRenderWindow_drawSprite(game->window,
        game->seller.equipements.life, NULL);
    if (game->seller.equipements.button[3] == true)
        sfRenderWindow_drawSprite(game->window,
        game->seller.equipements.strength, NULL);
}

void draw_shop(game_t *game)
{
    if (collision_between_rectangle(game->player.hitbox, game->seller.hitbox)) {
        sfRenderWindow_drawSprite(game->window, game->seller.seller, NULL);
        draw_button(game);
        set_draw_item(game);
    } else
        undraw_button(game);
}