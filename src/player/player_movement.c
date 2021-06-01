/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-william.karkegi
** File description:
** player_movement.c
*/

#include "rpg.h"
#include "player.h"
#include "sound.h"

static void move(player_t *player, float speed, int x_or_y, int dir)
{
    if (x_or_y == 1) {
        player->position.y += dir * speed;
        return;
    }
    player->position.x += dir * speed;
    if (dir == -1) {
        sfRectangleShape_setOrigin(player->hitbox, (sfVector2f) {40, 0});
        if (player->item_equiped != NULL)
            sfSprite_setScale(player->item_equiped->sprite, (sfVector2f)
                {40, 0});
    } else {
        sfRectangleShape_setOrigin(player->hitbox, (sfVector2f) {0, 0});
        if (player->item_equiped != NULL)
            sfSprite_setScale(player->item_equiped->sprite, (sfVector2f)
                {0, 0});
    }
    sfRectangleShape_setScale(player->hitbox, (sfVector2f){dir, 1});
    if (player->item_equiped != NULL)
        sfSprite_setScale(player->item_equiped->sprite, (sfVector2f){1, dir});
}

static void apply_movement(player_t *player, float speed)
{
    if (player->player_input.up && !player->player_input.stuck_up)
        move(player, speed, 1, -1);
    if (player->player_input.down && !player->player_input.stuck_down)
        move(player, speed, 1, 1);
    if (player->player_input.left && !player->player_input.stuck_left)
        move(player, speed, 0, -1);
    if (player->player_input.right && !player->player_input.stuck_right)
        move(player, speed, 0, 1);
}

static void normal_state(player_t *player, float dt)
{
    float speed = (float)player->speed * dt;

    apply_movement(player, speed);
    if (player->player_input.roll) {
        player->spritesheet_start = 200;
        player->spritesheet_end = 440;
        player->player_state = ROLL;
        player->time_between_animation = 0.1;
        player->roll_speed = player->init_roll_speed;
        player->roll_direction_neg = (sfVector2i){
        player->player_input.up ? 1 : 0, player->player_input.left ? 1 : 0};
        player->roll_direction_pos = (sfVector2i){
        player->player_input.down ? 1 : 0, player->player_input.right ? 1 : 0};
    }
}

static void roll_state(player_t *player, float dt)
{
    player->roll_speed -= player->roll_speed * 5 * dt;
    if (player->roll_direction_neg.x || player->roll_direction_pos.x)
        player->position.y += (player->roll_direction_neg.x ? -1 : 1) *
            player->roll_speed * dt;
    if (player->roll_direction_neg.y || player->roll_direction_pos.y)
        player->position.x += (player->roll_direction_neg.y ? -1 : 1) *
            player->roll_speed * dt;
    if (player->roll_speed < 100) {
        player->spritesheet_start = 0;
        player->spritesheet_end = 200;
        player->player_state = NORMAL;
        player->player_input.roll = false;
        player->time_between_animation = 0.2;
    }
}

void player_movement(game_t *game, player_t *player, float dt)
{
    switch (player->player_state) {
        case NORMAL:
            normal_state(player, dt);
            break;
        case ROLL:
            roll_state(player, dt);
            break;
    }
    if (player->xp >= 100) {
        sfSound_play(game->sounds[S_POW]);
        player->xp = 0;
        player->level++;
        player->speed++;
        player->health++;
    }
    sfRectangleShape_setPosition(player->hitbox, player->position);
}