/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** particle.h
*/

#ifndef PARTICLE_H
#define PARTICLE_H

particle_t *create_particles(particle_spawner_t *spawner);
void update_particle(particle_spawner_t *particle_spawner, float dt);

#endif
