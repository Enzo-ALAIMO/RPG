/*
** EPITECH PROJECT, 2021
** grid
** File description:
** grid.c
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "rpg.h"
#include "my.h"

static char **fill_map(char **grid, char const *buffer)
{
    sfVector2i pos = {0, 0};

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n') {
            pos.y++;
            pos.x = 0;
            continue;
        }
        grid[pos.y][pos.x++] = buffer[i];
    }
    return (grid);
}

static char **init_grid(int height, int width, char const *buffer)
{
    char **grid = malloc(sizeof(char *) * height);

    if (grid == NULL)
        return (NULL);
    for (int i = 0; i < height; i++) {
        grid[i] = malloc(sizeof(char) * width);
        if (grid[i] == NULL)
            return (NULL);
    }
    grid = fill_map(grid, buffer);
    return (grid);
}

static char *load_grid_content(char const *filepath, char *buffer)
{
    int fd = open(filepath, O_RDONLY);
    int value = 0;

    buffer = malloc(sizeof(char) * (8228 + 1));
    for (int i = 0; i < 8229; ++i)
        buffer[i] = '\0';
    if (fd == -1 || buffer == NULL)
        return (NULL);
    value = read(fd, buffer, 8228);
    close(fd);
    if (value == -1)
        return (NULL);
    return (buffer);
}

void load_grid(char const *filepath, a_star_t *a_star)
{
    char *buffer = NULL;

    buffer = load_grid_content(filepath, buffer);
    if (buffer == NULL)
        return;
    for (int i = 0; buffer[i] != '\0'; i++)
        if (buffer[i] == '\n')
            a_star->grid_height++;
    for (int i = 0; buffer[i] != '\n'; i++)
        a_star->grid_width++;
    a_star->init_grid = init_grid(a_star->grid_height, a_star->grid_width,
        buffer);
    a_star->grid = init_grid(a_star->grid_height, a_star->grid_width,
        buffer);
    free(buffer);
}
