/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** reset_path_enemy.c
*/

#include "rpg.h"
#include "pathfinding.h"
#include "util.h"
#include "enemy.h"

static sfVector2i get_random_pos(scene_t scene)
{
    sfVector2i pos = {0, 0};
    int random_i = 0;
    int random_j = 0;

    while (true) {
        random_i = get_random_int(scene.in_game->a_star.grid_height);
        random_j = get_random_int(scene.in_game->a_star.grid_width);
        if (random_i <= 2 || random_i >= scene.in_game->a_star.grid_height - 2
        || random_j <= 2 || random_j >= scene.in_game->a_star.grid_width - 2)
            continue;
        if (!scene.in_game->a_star.spots[random_i][random_j].is_wall)
            break;
    }
    pos.x = random_j;
    pos.y = random_i;
    return (pos);
}

static bool player_in_range(player_t *player, enemy_t *enemy)
{
    int check = sqrt(pow((player->position.x - enemy->pos.x), 2) + pow(
        (player->position.y - enemy->pos.y), 2));

    if (check <= enemy->range)
        return (true);
    return (false);
}

static sfVector2i get_player_pos(game_t *game, scene_t scene)
{
    sfVector2i player_pos = {game->player.position.x / TILE_SIZE,
        game->player.position.y / TILE_SIZE};
    int direction_x[4] = {1, -1, 0, 0};
    int direction_y[4] = {0, 0, 1, -1};

    if (scene.in_game->a_star.init_grid[player_pos.y][player_pos.x] == 'F')
        return (player_pos);
    for (int i = 0; i < 4; ++i) {
        player_pos.x += direction_x[i];
        player_pos.y += direction_y[i];
        if (scene.in_game->a_star.init_grid[player_pos.y][player_pos.x] == 'F')
            break;
    }
    if (scene.in_game->a_star.init_grid[player_pos.y][player_pos.x] != 'F')
        return (get_random_pos(scene));
    return (player_pos);
}

static sfVector2i get_goal_pos(game_t *game, scene_t scene, enemy_t *enemy)
{
    if (player_in_range(&game->player, enemy)) {
        return (get_player_pos(game, scene));
    }
    return (get_random_pos(scene));
}

void reset_path(game_t *game, scene_t scene, enemy_t *enemy)
{
    if (enemy->index_path > 0)
        start_a_star(&scene.in_game->a_star, (sfVector2i)
            {enemy->path[enemy->index_path - 1].x,
            enemy->path[enemy->index_path - 1].y},
            get_goal_pos(game, scene, enemy));
    else
        start_a_star(&scene.in_game->a_star, (sfVector2i){enemy->pos.x /
            TILE_SIZE, enemy->pos.y / TILE_SIZE}, get_goal_pos(game, scene,
            enemy));
    enemy->index_path = 0;
    enemy->len_path = scene.in_game->a_star.path_len;
    if (enemy->path != NULL)
        free(enemy->path);
    enemy->path = malloc(sizeof(sfVector2i) * enemy->len_path);
    if (enemy->path == NULL)
        return;
    for (int j = 0; j < enemy->len_path; ++j)
        enemy->path[j] = scene.in_game->a_star.path[j];
    scene.in_game->a_star.path_len = 0;
}