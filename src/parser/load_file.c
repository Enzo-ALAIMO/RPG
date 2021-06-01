/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** load_file.c
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "my.h"
#include "parser.h"

char *load_file(char const *filename)
{
    int fd = 0;
    char *buffer = malloc(sizeof(char) * (SIZE + 1));

    for (int i = 0; i < SIZE + 1; ++i)
        buffer[i] = '\0';
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        write(2, "Unable to open %s\n", my_strlen(filename));
        return (NULL);
    }
    read(fd, buffer, SIZE);
    close(fd);
    return (buffer);
}