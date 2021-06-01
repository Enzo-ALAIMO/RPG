/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** update_particle.c
*/

#include "rpg.h"
#include "particle.h"

static void reset_particle_spawner(particle_spawner_t *spawner)
{
    if (!spawner->loop)
        return;
    for (int i = 0; i < spawner->nb_particles; i++)
        if (spawner->arr_particles[i].time > 0)
            return;
    for (int i = 0; i < spawner->nb_particles; i++)
        sfSprite_destroy(spawner->arr_particles[i].sprite);
    free(spawner->arr_particles);
    spawner->arr_particles = create_particles(spawner);
}

static void activate_particle(particle_spawner_t *spawner, float dt)
{
    spawner->timer += dt;
    if (spawner->timer < spawner->time_between_spawn)
        return;
    for (int i = 0; i < spawner->nb_particles; i++) {
        if (!spawner->arr_particles[i].activated && spawner->arr_particles[i]
            .time > 0) {
            spawner->arr_particles[i].activated = true;
            spawner->timer = 0;
            break;
        }
    }
}

static void update_variable(particle_t *particle, float dt)
{
    particle->position.x += particle->velocity.x * dt;
    particle->position.y += particle->velocity.y *dt;
    particle->velocity.y += particle->gravity * dt;
    particle->fade -= particle->fade_scale;
    particle->time -= dt;
    sfSprite_setPosition(particle->sprite, particle->position);
    sfSprite_setColor(particle->sprite,
        sfColor_fromRGBA(255, 255, 255, particle->fade));
}

void update_particle(particle_spawner_t *particle_spawner, float dt)
{
    particle_t *particle = NULL;

    reset_particle_spawner(particle_spawner);
    activate_particle(particle_spawner, dt);
    for (int i = 0; i < particle_spawner->nb_particles; i++) {
        particle = &particle_spawner->arr_particles[i];
        if (!particle->activated)
            continue;
        update_variable(particle, dt);
        if (particle->time < 0)
            particle->activated = false;
    }
}