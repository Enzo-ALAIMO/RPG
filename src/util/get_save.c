/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** get_save.c
*/

#include <stdio.h>
#include <fcntl.h>
#include <stdbool.h>
#include <unistd.h>
#include "rpg.h"

static bool open_file(void)
{
    int fd = 0;

    fd = open(".save", O_RDONLY);
    if (fd == -1) {
        return false;
    } else
        close(fd);
    return (true);
}

void get_save(game_t *game)
{
    FILE *file;

    if (open_file())
        file = fopen(".save", "rb");
    else
        return;
    fread(&game->player.xp, sizeof(int), 1, file);
    fread(&game->player.level, sizeof(int), 1, file);
    fread(&game->player.gold, sizeof(int), 1, file);
    fread(&game->player.health, sizeof(int), 1, file);
    fread(&game->quest.bandits, sizeof(int), 1, file);
    fread(&game->quest.skeletons, sizeof(int), 1, file);
    fread(&game->quest.boss, sizeof(int), 1, file);
    fread(&game->quest.end, sizeof(int), 1, file);
    fread(&game->quest.bandits_done, sizeof(int), 1, file);
    fread(&game->quest.skeletons_done, sizeof(int), 1, file);
    fread(&game->quest.boss_done, sizeof(int), 1, file);
    fread(&game->quest.end_done, sizeof(int), 1, file);
    fclose(file);
}