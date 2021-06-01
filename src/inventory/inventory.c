/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** inventory.c
*/

#include <stdlib.h>
#include "rpg.h"
#include "inventory.h"
#include "util.h"

static void draw_item(game_t *game, item_t *item, int x, int y)
{
    if (item == NULL)
        return;
    sfSprite_setOrigin(item->sprite, (sfVector2f){20, 20});
    sfSprite_setPosition(item->sprite, (sfVector2f){x, y});
    sfSprite_setRotation(item->sprite, 0);
    sfSprite_setScale(item->sprite, (sfVector2f){1, 1});
    sfRenderWindow_drawSprite(game->window, item->sprite, NULL);
}

void draw_inventory_item(game_t *game, inventory_t *inventory)
{
    draw_item(game, inventory->arr[0], INV_POS_X_LEFT, INV_POS_Y_ONE);
    draw_item(game, inventory->arr[1], INV_POS_X_MIDDLE, INV_POS_Y_ONE);
    draw_item(game, inventory->arr[2], INV_POS_X_RIGHT, INV_POS_Y_ONE);
    draw_item(game, inventory->arr[3], INV_POS_X_LEFT, INV_POS_Y_TWO);
    draw_item(game, inventory->arr[4], INV_POS_X_MIDDLE, INV_POS_Y_TWO);
    draw_item(game, inventory->arr[5], INV_POS_X_RIGHT, INV_POS_Y_TWO);
    draw_item(game, inventory->arr[6], INV_POS_X_LEFT, INV_POS_Y_THREE);
    draw_item(game, inventory->arr[7], INV_POS_X_MIDDLE, INV_POS_Y_THREE);
    draw_item(game, inventory->arr[8], INV_POS_X_RIGHT, INV_POS_Y_THREE);
    draw_item(game, inventory->arr[9], INV_POS_X_LEFT, INV_POS_Y_FOUR);
    draw_item(game, inventory->arr[10], INV_POS_X_MIDDLE, INV_POS_Y_FOUR);
    draw_item(game, inventory->arr[11], INV_POS_X_RIGHT, INV_POS_Y_FOUR);
    draw_item(game, inventory->arr[12], INV_POS_X_EQUIPED, INV_POS_Y_EQUIPED);
}

static void swap(item_t **a, item_t **b)
{
    item_t *temp = *a;

    *a = *b;
    *b = temp;
}

void swap_item(game_t *game, int index)
{
    inventory_t *inventory = &game->player.inventory;

    if (inventory->index_item_selected == -1)
        inventory->index_item_selected = index;
    else {
        swap(&inventory->arr[index],
            &inventory->arr[inventory->index_item_selected]);
        if (index == 12)
            game->player.item_equiped = inventory->arr[index];
        else if (inventory->index_item_selected == 12)
            game->player.item_equiped =
                inventory->arr[inventory->index_item_selected];
        weapon_check(game);
        inventory->index_item_selected = -1;
    }
}

inventory_t create_inventory(void)
{
    inventory_t inventory = {0};

    inventory.sprite = create_sprite("./assets/in_game/hud.png",
        (sfVector2f){0, 0}, (sfVector2f){1, 1});
    inventory.arr = malloc(sizeof(item_t) * INVENTORY_SIZE);
    if (inventory.arr == NULL)
        return ((inventory_t){0});
    for (int i = 0; i < INVENTORY_SIZE; ++i)
        inventory.arr[i] = NULL;
    inventory.index_item_selected = -1;
    return (inventory);
}