/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** anim_shoper.c
*/

#include "my.h"
#include "parser.h"
#include "shop.h"
#include "util.h"

static sfRectangleShape *create_hitbox_shop(char const *filepath,
    sfVector2f position, sfIntRect rect)
{
    sfRectangleShape *hitbox = sfRectangleShape_create();
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);

    sfRectangleShape_setSize(hitbox, (sfVector2f){40, 40});
    sfRectangleShape_setPosition(hitbox, position);
    sfRectangleShape_setTexture(hitbox, texture, 1);
    sfRectangleShape_setScale(hitbox, (sfVector2f){1, 1});
    sfRectangleShape_setTextureRect(hitbox, rect);
    return (hitbox);
}

void shoper_animation(shoper_t *shoper, float dt)
{
    sfRectangleShape_setTextureRect(shoper->hitbox, shoper->rect);
    shoper->timer += dt;
    if (shoper->timer > shoper->time_between_animation) {
        shoper->timer = 0;
        if (shoper->rect.left + shoper->rect.width >= shoper->spritesheet_end)
            shoper->rect.left = shoper->spritesheet_start;
        else
            shoper->rect.left += shoper->rect.width;
    }
}

void init_shoper(char **values, shoper_t *shoper)
{
    shoper->position = (sfVector2f){870, 560};
    shoper->rect = (sfIntRect){0, 0, 40, 40};
    shoper->spritesheet_end = 200;
    shoper->hitbox = create_hitbox_shop(values[1], shoper->position,
        shoper->rect);
    shoper->time_between_animation = 0.2;
}

static shoper_t shoper_parse_line(char ***array)
{
    shoper_t shoper = {0};

    for (int i = 0; array[i] != NULL; i++) {
        for (int j = 0; array[i][j] != NULL; j++) {
            if (!my_strcmp(array[i][j], "shoper")) {
                init_shoper(array[i], &shoper);
            }
        }
    }
    return (shoper);
}

shoper_t create_shoper_parser(char *arg)
{
    shoper_t shoper = {0};
    sfVector2f pos = {0, 0};
    sfVector2f scale = {1, 1};
    char *str = load_file(arg);
    char **array = split_string_opt(str, '\n');
    char ***triple_array = init_triple_array(array);

    shoper = shoper_parse_line(triple_array);
    shoper.seller = create_sprite("./assets/shop/shop.png", pos, scale);
    set_equipements(&shoper.equipements);
    free_triple_array(triple_array);
    free_double_array(array);
    free(str);
    return (shoper);
}