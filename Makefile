##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC = 	src/main.c \
		src/buttons_functions/change_fps.c \
		src/buttons_functions/change_res.c \
		src/buttons_functions/change_scene.c \
		src/buttons_functions/change_volume.c \
		src/buttons_functions/empty.c \
		src/buttons_functions/exit.c \
		src/buttons_functions/menu.c \
		src/buttons_functions/resume.c \
		src/buttons_functions/toggle_quest.c \
		src/collision/bullet_collision_player.c \
		src/collision/collision.c \
		src/collision/player_collision.c \
		src/collision/player_collision_points.c \
		src/collision/player_map_collision.c \
		src/draw/draw_buttons.c \
		src/draw/draw_cave.c \
		src/draw/draw_how_to_play.c \
		src/draw/draw_menu.c \
		src/draw/draw_settings.c \
		src/draw/draw_hub.c \
		src/enemy/animation_enemy.c \
		src/enemy/check_enemy_bullet_collision.c \
		src/enemy/create_enemy.c \
		src/enemy/draw_enemy.c \
		src/enemy/movement_enemy.c \
		src/enemy/reset_path_enemy.c \
		src/enemy/shoot_enemy.c \
		src/enemy/update_enemy.c \
		src/events/event_cave.c \
		src/events/event_how_to_play.c \
		src/events/event_hub.c \
		src/events/event_menu.c \
		src/events/event_pause.c \
		src/events/event_settings.c \
		src/free/free_a_star.c \
		src/free/free_game.c \
		src/free/free_map.c \
		src/free/free_scene.c \
		src/game/game_loop.c \
		src/interface/button.c \
		src/interface/button_hover.c \
		src/interface/text.c \
		src/inventory/inventory.c \
		src/inventory/inventory_event.c \
		src/items/item_weapon.c \
		src/map/create_map.c \
		src/map/generator.c \
		src/npc/animation_npc.c \
		src/npc/create_npc.c \
		src/npc/draw_npc.c \
		src/npc/movement_npc.c \
		src/npc/update_npc.c \
		src/parser/check_file.c \
		src/parser/get_file.c \
		src/parser/load_file.c \
		src/parser/parse_file.c \
		src/parser/split_string_opt.c \
		src/parser/init/init_button.c \
		src/parser/init/init_hitbox.c \
		src/parser/init/init_player.c \
		src/parser/init/init_particle_spawner.c \
		src/parser/init/init_text.c \
		src/parser/parser_type/parser_button.c \
		src/parser/parser_type/parser_hitbox.c \
		src/parser/parser_type/parser_player.c \
		src/parser/parser_type/parser_particle_spawner.c \
		src/parser/parser_type/parser_text.c \
		src/particle/update_particle.c \
		src/pathfinding/a_star.c \
		src/pathfinding/a_star_check_neighbors.c \
		src/pathfinding/a_star_util.c \
		src/pathfinding/a_star_get_spots.c \
		src/pathfinding/add_neighbors.c \
		src/pathfinding/create_spots.c \
		src/pathfinding/get_path.c \
		src/pathfinding/grid.c \
		src/pathfinding/load_map.c \
		src/pathfinding/reset_a_star.c \
		src/player/player_animation.c \
		src/player/player_event.c \
		src/player/player_input.c \
		src/player/player_item.c \
		src/player/player_movement.c \
		src/player/player_quest.c \
		src/scenes/scene_cave.c \
		src/scenes/scene_how_to_play.c \
		src/scenes/scene_menu.c \
		src/scenes/scene_settings.c \
		src/scenes/scene_hub.c \
		src/scenes/util/create_settings_buttons.c \
		src/scenes/util/reset_cave.c \
		src/shop/anim_shoper.c	\
		src/shop/draw_shop.c 	\
		src/shop/get_item.c 	\
		src/shop/set_new_item.c \
		src/sound/sound.c \
		src/update/update_cave.c \
		src/update/update_how_to_play.c \
		src/update/update_menu_scene.c \
		src/update/update_settings.c \
		src/update/update_hub.c \
		src/util/create_sprite.c \
		src/util/get_float.c \
		src/util/get_save.c \
		src/util/nb_to_string.c \
		src/util/set_save.c \
		src/util/random.c \
		src/weapon/bullet.c \
		src/weapon/weapon_check.c \
		src/weapon/weapon.c \
		src/weapon/weapon_shoot.c \

OBJ = $(SRC:.c=.o)

NAME = my_rpg

CC = gcc

CFLAGS = -W -Wall -Wextra

CPPFLAGS = -I./include

LDFLAGS = -L./lib -lmy -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system -lm

all: $(NAME)

libbuild:
	make all -C ./lib/my/

$(NAME): libbuild $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	make clean -s -C ./lib/my/
	$(RM) $(OBJ)

fclean:	clean
	make fclean -s -C ./lib/my/
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re libbuild