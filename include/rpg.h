/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** rpg.h
*/

#ifndef RPG_H
#define RPG_H

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

static const int WINDOW_WIDTH = 1920;
static const int WINDOW_HEIGHT = 1080;

typedef struct spot_s {
    int i;
    int j;
    int f;
    int g;
    int h;
    struct spot_s **neighbors;
    struct spot_s *previous;
    bool is_wall;
    bool is_closed;
} spot_t;

typedef struct a_star_s {
    char **init_grid;
    char **grid;
    int grid_width;
    int grid_height;
    int nb_spots;
    spot_t **spots;
    sfVector2i *open_set;
    int winner;
    spot_t *end;
    spot_t *current;
    int len_open_set;
    int index_open;
    sfVector2i *path;
    int path_len;
} a_star_t;

typedef struct map_s {
    int height;
    int width;
    char **grid;
    int sprite_size;
    int nb_hitbox;
    sfSprite **arr_sprites;
    sfRectangleShape **hitbox;
} map_t;

typedef struct item_s {
    int item_type;
    int *variables;
    void (*use)();
    sfSprite *sprite;
    sfIntRect rect;
    bool new;
} item_t;

typedef struct inventory_s {
    sfSprite *sprite;
    bool open;
    item_t **arr;
    int index_item_selected;
} inventory_t;

typedef struct quest_s {
    sfSprite *sprite;
    bool open;
    int bandits;
    int skeletons;
    int boss;
    int end;
    bool bandits_done;
    bool skeletons_done;
    bool boss_done;
    bool end_done;
} quest_t;

typedef struct bullet_s {
    sfVector2f position;
    sfRectangleShape *hitbox;
    sfIntRect rect;
    int speed;
    int damage;
    float timer;
    float live_time;
    bool is_used;
} bullet_t;

typedef struct weapon_s {
    bool is_active;
    item_t *weapon_item;
    bullet_t *arr_bullets;
    float timer;
    float *time_between_shoot;
    int *damage;
    int index;
} weapon_t;

typedef struct particle_s {
    bool activated;
    sfVector2f position;
    sfVector2f velocity;
    float gravity;
    float time;
    float live_time;
    float fade;
    float fade_scale;
    sfSprite *sprite;
} particle_t;

typedef struct particle_spawner_s {
    int nb_particles;
    particle_t *arr_particles;
    float timer;
    float time_between_spawn;
    int live_time;
    sfVector2i range_velocity_x;
    sfVector2i range_velocity_y;
    float gravity;
    sfVector2i range_spawn_x;
    sfVector2i range_spawn_y;
    char *sprite_path;
    bool loop;
    float fade;
} particle_spawner_t;

typedef struct btn_path_s {
    char *sprite;
    char *sprite_over;
    char *sprite_click;
} btn_path_t;

typedef struct button_s {
    sfRectangleShape *rect;
    sfVector2f pos;
    sfVector2f size;
    sfSprite *sprite;
    sfSprite *over_sprite;
    sfSprite *click_sprite;
    bool draw;
    bool draw_over;
    bool draw_click;
    void (*on_click)();
} button_t;

typedef struct text_s {
    sfText *text;
    sfFont *font;
    sfVector2f pos;
    char *text_content;
    bool draw;
} text_t;

typedef struct enemy_s {
    int enemy_type;
    int enemy_state;
    int hp;
    int gold;
    int xp;
    int boss;
    bool already_hit_player;
    bool dead;
    sfRectangleShape *hitbox;
    weapon_t weapon;
    int speed;
    int range;
    float timer;
    float time_between_animation;
    sfIntRect rect;
    int spritesheet_start;
    int spritesheet_end;
    sfVector2f pos;
    sfVector2i *path;
    int index_path;
    int len_path;
} enemy_t;

typedef struct npc_s {
    int npc_state;
    sfRectangleShape *hitbox;
    sfSprite *dialog;
    int speed;
    float timer;
    float time_between_animation;
    sfIntRect rect;
    int spritesheet_start;
    int spritesheet_end;
    sfVector2f pos;
    sfVector2i *path;
    int index_path;
    int len_path;
} npc_t;

typedef struct in_game_s {
    particle_spawner_t particle_spawner;
    sfRectangleShape **arr_hitbox;
    sfRectangleShape *cave_entry;
    a_star_t a_star;
    npc_t *arr_npc;
    enemy_t *arr_enemies;
} in_game_t;

typedef struct scene_s {
    int nb_buttons;
    int nb_texts;
    button_t *arr_buttons;
    text_t *arr_texts;
    sfSprite *background;
    map_t *map;
    in_game_t *in_game;
    sfClock *clock_dt;
    float dt;
    sfFont *font;
    sfSprite *spr_pause;
    bool pause;
    bool change;
    int scene_change;
    void (*event)();
    void (*update)();
    void (*draw)();
} scene_t;

typedef struct player_input_s {
    bool up;
    bool down;
    bool left;
    bool right;
    bool stuck_up;
    bool stuck_down;
    bool stuck_left;
    bool stuck_right;
    bool roll;
    bool use_item;
} player_input_t;

typedef struct player_s {
    int player_state;
    int health;
    int xp;
    int level;
    int gold;
    int speed;
    float timer;
    float time_between_animation;
    sfVector2f position;
    sfRectangleShape *hitbox;
    sfIntRect rect;
    int spritesheet_start;
    int spritesheet_end;
    player_input_t player_input;
    sfVector2i roll_direction_neg;
    sfVector2i roll_direction_pos;
    float init_roll_speed;
    float roll_speed;
    item_t *item_equiped;
    weapon_t weapon;
    inventory_t inventory;
} player_t;

typedef struct equipement_s {
    sfSprite *strength;
    sfSprite *life;
    sfSprite *first_gun;
    sfSprite *second_gun;
    bool *button;
} equipement_t;

typedef struct shoper_s {
    int player_state;
    float timer;
    float time_between_animation;
    sfVector2f position;
    sfRectangleShape *hitbox;
    sfIntRect rect;
    int spritesheet_start;
    int spritesheet_end;
    equipement_t equipements;
    sfSprite *seller;
} shoper_t;

typedef struct game_s {
    sfRenderWindow *window;
    sfVideoMode video_mode;
    sfEvent event;
    int scene_index;
    scene_t *arr_scenes;
    int volume;
    sfSound **sounds;
    player_t player;
    quest_t quest;
    shoper_t seller;
} game_t;

#endif