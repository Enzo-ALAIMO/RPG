/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-mydefender-enzo.alaimo
** File description:
** sound.c
*/

#include <SFML/Audio.h>
#include <stdlib.h>
#include "rpg.h"
#include "sound.h"

static sfSoundBuffer **init_music_buffers(sfSoundBuffer **s_buff)
{
    s_buff[S_SHOOT] =
        sfSoundBuffer_createFromFile("./assets/sounds/shot.wav");
    s_buff[S_LASER] =
        sfSoundBuffer_createFromFile("./assets/sounds/shot_LASRGun.wav");
    return (s_buff);
}

static sfSoundBuffer **init_sounds_buffers(void)
{
    sfSoundBuffer **s_buff = malloc(sizeof(*s_buff) * NB_SOUND);

    s_buff = init_music_buffers(s_buff);
    s_buff[S_BG_MENU] =
        sfSoundBuffer_createFromFile("./assets/sounds/music_menu.wav");
    s_buff[S_BG_HUB] =
        sfSoundBuffer_createFromFile("./assets/sounds/music_hub.wav");
    s_buff[S_BG_CAVE] =
        sfSoundBuffer_createFromFile("./assets/sounds/music_cave.wav");
    s_buff[S_DEAD_P] =
        sfSoundBuffer_createFromFile("./assets/sounds/death.wav");
    s_buff[S_HIT_E] =
        sfSoundBuffer_createFromFile("./assets/sounds/Hit_En.wav");
    s_buff[S_HIT_P] =
        sfSoundBuffer_createFromFile("./assets/sounds/Hit_Pl.wav");
    s_buff[S_POT] =
        sfSoundBuffer_createFromFile("./assets/sounds/Popo.wav");
    s_buff[S_POW] =
        sfSoundBuffer_createFromFile("./assets/sounds/Powerup.wav");
    return (s_buff);
}

void init_sounds(game_t *game)
{
    sfSoundBuffer **sounds_buffers = init_sounds_buffers();

    game->sounds = malloc(sizeof(*game->sounds) * NB_SOUND);
    for (int i = 0; i < NB_SOUND; i++) {
        game->sounds[i] = sfSound_create();
        sfSound_setBuffer(game->sounds[i], sounds_buffers[i]);
        sfSound_setVolume(game->sounds[i], game->volume);
    }
}
