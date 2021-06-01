/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** init_particle_spawner.c
*/


#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <time.h>
#include "rpg.h"
#include "my.h"
#include "util.h"

static int get_random_between_range(int lower, int upper)
{
    unsigned int seed = 0;
    int fd = open("/dev/urandom", O_RDONLY);

    if (fd == -1)
        return (0);
    if (read(fd, &seed, sizeof(seed)) == -1)
        return (0);
    srand(seed);
    close(fd);
    return ((rand() % (upper - lower + 1)) + lower);
}

static void init_particle(particle_t *particle, particle_spawner_t *spawner)
{
    particle->position.x = get_random_between_range
        (spawner->range_spawn_x.x, spawner->range_spawn_x.y);
    particle->position.y = get_random_between_range
        (spawner->range_spawn_y.x, spawner->range_spawn_y.y);
    particle->activated = 0;
    particle->time = spawner->live_time;
    particle->live_time = spawner->live_time;
    particle->velocity.x = get_random_between_range
        (spawner->range_velocity_x.x, spawner->range_velocity_x.y);
    particle->velocity.y = get_random_between_range
        (spawner->range_velocity_y.x, spawner->range_velocity_y.y);
    particle->gravity = spawner->gravity;
    particle->fade = 255;
    particle->fade_scale = spawner->fade;
    particle->sprite = create_sprite(spawner->sprite_path,
        particle->position, (sfVector2f){1, 1});
}

particle_t *create_particles(particle_spawner_t *spawner)
{
    particle_t *particles = malloc(sizeof(particle_t) *
        spawner->nb_particles);

    if (particles == NULL)
        return (NULL);
    for (int i = 0; i < spawner->nb_particles; i++)
        init_particle(&particles[i], spawner);
    return (particles);
}

void init_particle_spawner(char **values, particle_spawner_t *particle_spawner)
{
    particle_spawner->nb_particles = my_getnbr(values[1]);
    particle_spawner->time_between_spawn = get_float(values[2]);
    particle_spawner->range_velocity_x.x = my_getnbr(values[3]);
    particle_spawner->range_velocity_x.y = my_getnbr(values[4]);
    particle_spawner->range_velocity_y.x = my_getnbr(values[5]);
    particle_spawner->range_velocity_y.y = my_getnbr(values[6]);
    particle_spawner->gravity = get_float(values[7]);
    particle_spawner->range_spawn_x.x = my_getnbr(values[8]);
    particle_spawner->range_spawn_x.y = my_getnbr(values[9]);
    particle_spawner->range_spawn_y.x = my_getnbr(values[10]);
    particle_spawner->range_spawn_y.y = my_getnbr(values[11]);
    particle_spawner->sprite_path = my_strdup(values[12]);
    particle_spawner->loop = my_getnbr(values[13]);
    particle_spawner->fade = get_float(values[14]);
    particle_spawner->live_time = my_getnbr(values[15]);
    particle_spawner->arr_particles = create_particles(particle_spawner);
}