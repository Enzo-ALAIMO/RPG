/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-mydefender-enzo.alaimo
** File description:
** text.c
*/

#include "rpg.h"
#include "scene.h"
#include "util.h"
#include "interface.h"

static void update_text_string(text_t text, char const *content)
{
    sfText_setString(text.text, content);
}

static void update_texts_player(game_t *game, scene_t *scene)
{
    update_text_string(scene->arr_texts[T_LEVEL], nb_to_string
        (game->player.level));
    update_text_string(scene->arr_texts[T_XP], nb_to_string
        (game->player.xp));
    update_text_string(scene->arr_texts[T_DAMAGE], nb_to_string
        (game->player.weapon.damage[game->player.weapon.index]));
    update_text_string(scene->arr_texts[T_SPEED], nb_to_string
        (game->player.speed));
    update_text_string(scene->arr_texts[T_HP], nb_to_string
        (game->player.health));
    update_text_string(scene->arr_texts[T_GOLD], nb_to_string
        (game->player.gold));
    update_text_string(scene->arr_texts[T_BANDITS], nb_to_string
        (game->quest.bandits));
    update_text_string(scene->arr_texts[T_SKELETONS], nb_to_string
        (game->quest.skeletons));
    update_text_string(scene->arr_texts[T_BOSS], nb_to_string
        (game->quest.boss));
    update_text_string(scene->arr_texts[T_END], nb_to_string(game->quest.end));
}

void toggle_texts(game_t *game, scene_t *scene)
{
    for (int i = 0; i < NB_TEXTS; ++i) {
        if (i >= T_BANDITS && !game->quest.open)
            continue;
        scene->arr_texts[i].draw = !scene->arr_texts[i].draw;
    }
}

void draw_texts(game_t *game, scene_t scene)
{
    update_texts_player(game, &scene);
    for (int i = 0; i < NB_TEXTS; ++i)
        if (scene.arr_texts[i].draw)
            sfRenderWindow_drawText(game->window, scene.arr_texts[i].text,
                NULL);
}