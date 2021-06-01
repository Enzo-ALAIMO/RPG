/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** player_item.c
*/

#include <math.h>
#include "rpg.h"
#include "player.h"

static void update_item_position(game_t *game, sfVector2f player_pos, item_t
*item)
{
    sfVector2f cursor_pos = sfRenderWindow_mapPixelToCoords(game->window,
        (sfVector2i){sfMouse_getPositionRenderWindow
        (game->window).x, sfMouse_getPositionRenderWindow(game->window).y},
        sfRenderWindow_getView(game->window));
    float angle = atan2(cursor_pos.y - (player_pos.y + (PLAYER_SCALE.y * 20))
        , cursor_pos.x - (player_pos.x + (PLAYER_SCALE.y * 18)));

    angle *= 180 / M_PI;
    if (angle < 0)
        angle = 360 - (-angle);
    sfSprite_setOrigin(item->sprite, (sfVector2f){20, 20});
    sfSprite_setRotation(item->sprite, angle);
    sfSprite_setPosition(item->sprite, (sfVector2f)
    {player_pos.x + (PLAYER_SCALE.x * 20), player_pos.y + (PLAYER_SCALE.y *
    20)});
}

static void use_player_item(game_t *game, player_t *player)
{
    if (player->player_input.use_item)
        player->item_equiped->use(game);
}

void player_item(game_t *game, player_t *player, float dt)
{
    if (player->item_equiped == NULL)
        return;
    player->weapon.timer += dt;
    update_item_position(game, player->position, player->item_equiped);
    use_player_item(game, player);
}