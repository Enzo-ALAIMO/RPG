/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** set_save.c
*/

#include <stdio.h>
#include "rpg.h"

void set_save(game_t *game)
{
    int xp = game->player.xp;
    int level = game->player.level;
    int gold = game->player.gold;
    int health = game->player.health;
    FILE *file = fopen(".save", "wb");


    fwrite(&xp, sizeof(int), 1, file);
    fwrite(&level, sizeof(int), 1, file);
    fwrite(&gold, sizeof(int), 1, file);
    fwrite(&health, sizeof(int), 1, file);
    fwrite(&game->quest.bandits, sizeof(int), 1, file);
    fwrite(&game->quest.skeletons, sizeof(int), 1, file);
    fwrite(&game->quest.boss, sizeof(int), 1, file);
    fwrite(&game->quest.end, sizeof(int), 1, file);
    fwrite(&game->quest.bandits_done, sizeof(int), 1, file);
    fwrite(&game->quest.skeletons_done, sizeof(int), 1, file);
    fwrite(&game->quest.boss_done, sizeof(int), 1, file);
    fwrite(&game->quest.end_done, sizeof(int), 1, file);
    fclose(file);
}