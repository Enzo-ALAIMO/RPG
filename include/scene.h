/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** scene.h
*/

#ifndef SCENE_H
#define SCENE_H

#include "rpg.h"

enum scenes_names {
    MENU_SCENE,
    HTP_SCENE,
    SETTINGS_SCENE,
    HUB_SCENE,
    CAVE_SCENE,
    NB_SCENES
};

enum btn_menu {
    PLAY_BTN_MENU,
    HTP_BTN_MENU,
    SETTINGS_BTN_MENU,
    EXIT_BTN_MENU,
    NB_BTN_MENU
};

enum btn_htp {
    RETURN_BTN_HTP,
    NB_BTN_HTP
};

enum btn_settings {
    RETURN_BTN_SETT,
    VOL_UP_BTN_SETT,
    VOL_DOWN_BTN_SETT,
    LOW_BTN_SETT,
    MEDIUM_BTN_SETT,
    HIGH_BTN_SETT,
    FPS_L_BTN_SETT,
    FPS_M_BTN_SETT,
    FPS_H_BTN_SETT,
    NB_BTN_SETT
};

enum btn_in_game {
    BTN_P_RESUME,
    BTN_P_MENU,
    BTN_P_EXIT,
    BTN_GUN_ONE,
    BTN_GUN_TWO,
    BTN_LIFE,
    BTN_POTION,
    BTN_I_SLOT_1,
    BTN_I_SLOT_2,
    BTN_I_SLOT_3,
    BTN_I_SLOT_4,
    BTN_I_SLOT_5,
    BTN_I_SLOT_6,
    BTN_I_SLOT_7,
    BTN_I_SLOT_8,
    BTN_I_SLOT_9,
    BTN_I_SLOT_10,
    BTN_I_SLOT_11,
    BTN_I_SLOT_12,
    BTN_I_SLOT_13,
    BTN_QUEST,
    NB_BTN_IN_GAME
};

enum btn_cave {
    BTN_C_P_RESUME,
    BTN_C_P_MENU,
    BTN_C_P_EXIT,
    BTN_C_I_SLOT_1,
    BTN_C_I_SLOT_2,
    BTN_C_I_SLOT_3,
    BTN_C_I_SLOT_4,
    BTN_C_I_SLOT_5,
    BTN_C_I_SLOT_6,
    BTN_C_I_SLOT_7,
    BTN_C_I_SLOT_8,
    BTN_C_I_SLOT_9,
    BTN_C_I_SLOT_10,
    BTN_C_I_SLOT_11,
    BTN_C_I_SLOT_12,
    BTN_C_I_SLOT_13,
    BTN_C_QUEST,
    NB_BTN_CAVE
};

enum sprites_cave {
    S_FLOOR,
    S_WALL,
    S_VOID,
    NB_SPRITES,
};

enum texts {
    T_LEVEL,
    T_XP,
    T_XP_LEVEL,
    T_HP,
    T_DAMAGE,
    T_SPEED,
    T_GOLD,
    T_BANDITS,
    T_SKELETONS,
    T_BOSS,
    T_END,
    NB_TEXTS
};

scene_t create_scene_menu(void);
scene_t create_scene_settings(void);
scene_t create_scene_htp(void);
scene_t create_scene_hub(void);
scene_t create_scene_cave(void);
button_t *create_sett_buttons(scene_t scene);
void reset_cave(game_t *game);

#endif