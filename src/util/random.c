/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** random.c
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int get_random_int(int bound)
{
    unsigned int seed = 0;
    int fd = open("/dev/urandom", O_RDONLY);

    if (fd == -1)
        return (0);
    if (read(fd, &seed, sizeof(seed)) == -1)
        return (0);
    srand(seed);
    close(fd);
    return (rand() % (bound + 1));
}