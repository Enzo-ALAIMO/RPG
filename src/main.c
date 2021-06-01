/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** main.c
*/

#include "rpg.h"
#include "scene.h"
#include "sound.h"
#include "game.h"
#include "free.h"
#include "weapon.h"
#include "parser.h"
#include "shop.h"
#include "util.h"

static quest_t create_quest(void)
{
    quest_t quest = {0};

    quest.sprite = create_sprite("./assets/in_game/quests.png", (sfVector2f)
    {40, 0}, (sfVector2f){1, 1});
    return (quest);
}

static void init_scenes(game_t *game)
{
    game->arr_scenes[MENU_SCENE] = create_scene_menu();
    game->arr_scenes[HTP_SCENE] = create_scene_htp();
    game->arr_scenes[SETTINGS_SCENE] = create_scene_settings();
    game->arr_scenes[HUB_SCENE] = create_scene_hub();
    game->arr_scenes[CAVE_SCENE] = create_scene_cave();
    game->scene_index = MENU_SCENE;
}

static int init_game(game_t *game)
{
    game->video_mode = (sfVideoMode){1920, 1080, 32};
    game->window = sfRenderWindow_create(game->video_mode, "My_RPG", sfResize |
    sfClose, NULL);
    if (game->window == NULL)
        return (84);
    sfRenderWindow_setFramerateLimit(game->window, 60);
    game->volume = 10;
    init_sounds(game);
    game->arr_scenes = malloc(sizeof(scene_t) * NB_SCENES);
    if (game->arr_scenes == NULL)
        return (84);
    game->seller = create_shoper_parser("test.txt");
    init_scenes(game);
    game->player = create_player_parser("test.txt");
    game->player.weapon = create_weapon("./assets/weapon/bullet.png");
    game->player.item_equiped = NULL;
    game->player.inventory.arr[0] = &game->player.weapon.weapon_item[0];
    game->quest = create_quest();
    get_save(game);
    return (0);
}

int main(void)
{
    game_t game = {0};

    if (init_game(&game) == 84)
        return (84);
    sfSound_setLoop(game.sounds[S_BG_MENU], true);
    sfSound_play(game.sounds[S_BG_MENU]);
    game_loop(&game);
    free_game(&game);
    return (0);
}