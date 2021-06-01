/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-mydefender-enzo.alaimo
** File description:
** button_init.c
*/

#include <SFML/Graphics.h>
#include <stdbool.h>
#include "rpg.h"
#include "my.h"
#include "interface.h"

sfSprite *create_sprite_button(char const *path, sfVector2f pos)
{
    sfTexture *texture = sfTexture_createFromFile(path, NULL);
    sfSprite *sprite = sfSprite_create();

    pos.x -= sfTexture_getSize(texture).x / 2;
    pos.y -= sfTexture_getSize(texture).y / 2;
    sfSprite_setPosition(sprite, pos);
    sfSprite_setTexture(sprite, texture, sfFalse);
    return (sprite);
}

btn_path_t set_btn_path(char **path, int sprite, int sprite_over,
    int sprite_click)
{
    return ((btn_path_t){
        .sprite = path[sprite],
        .sprite_over = path[sprite_over],
        .sprite_click = path[sprite_click],
    });
}

button_t button_init(sfVector2f pos, btn_path_t btn_path, void (*on_click)())
{
    button_t button = {0};

    button.pos = pos;
    button.size = (sfVector2f){100, 50};
    button.rect = sfRectangleShape_create();
    button.sprite = create_sprite_button(btn_path.sprite, pos);
    button.over_sprite = create_sprite_button(btn_path.sprite_over, pos);
    button.click_sprite = create_sprite_button(btn_path.sprite_click, pos);
    button.on_click = on_click;
    button.pos.x -= sfTexture_getSize(sfSprite_getTexture(button.sprite)).x / 2;
    button.pos.y -= sfTexture_getSize(sfSprite_getTexture(button.sprite)).y / 2;
    button.size.x = sfTexture_getSize(sfSprite_getTexture(button.sprite)).x;
    button.size.y = sfTexture_getSize(sfSprite_getTexture(button.sprite)).y;
    button.draw = true;
    sfRectangleShape_setPosition(button.rect, button.pos);
    sfRectangleShape_setSize(button.rect, button.size);
    return (button);
}

bool button_is_hover(button_t *button, sfVector2f click_position, game_t *game)
{
    sfVector2f cursor_pos =
        sfRenderWindow_mapPixelToCoords(game->window,
        (sfVector2i){click_position.x, click_position.y},
        sfRenderWindow_getView(game->window));

    if (!button->draw)
        return (false);
    if (button->pos.x  <= cursor_pos.x
        && button->pos.x + button->size.x >= cursor_pos.x
        && button->pos.y <= cursor_pos.y
        && button->pos.y + button->size.y >= cursor_pos.y)
        return (true);
    return (false);
}