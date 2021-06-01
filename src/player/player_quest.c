/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** player_quest.c
*/

#include "rpg.h"

static void reward_bandits(game_t *game)
{
    game->quest.bandits_done = true;
    game->player.gold += 50000;
}

static void reward_skeleton(game_t *game)
{
    game->quest.skeletons_done = true;
    game->player.gold += 35000;
}

static void reward_boss(game_t *game)
{
    game->quest.boss_done = true;
    game->player.gold += 500000;
}

static void reward_end(game_t *game)
{
    game->quest.end_done = true;
    game->player.gold += 20000;
}

void check_reward_quest(game_t *game)
{
    if (!game->quest.bandits_done && game->quest.bandits >= 50)
        reward_bandits(game);
    if (!game->quest.skeletons_done && game->quest.skeletons >= 35)
        reward_skeleton(game);
    if (!game->quest.boss_done && game->quest.boss >= 5)
        reward_boss(game);
    if (!game->quest.end_done && game->quest.end >= 1)
        reward_end(game);
}