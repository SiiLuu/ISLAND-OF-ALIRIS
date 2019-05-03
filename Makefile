##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile for the minishell1
##

SRC 	=	src/main.c						\
			src/music.c						\
			src/menu/menu.c					\
			src/menu/menu_display.c			\
			src/menu/settings.c				\
			src/menu/sound_bar.c			\
			src/menu/check_menu.c								\
			src/gameplay/check_collision.c						\
			src/gameplay/manage_collision.c						\
			src/gameplay/character.c							\
			src/gameplay/interaction/pnj_interaction.c			\
			src/gameplay/interaction/fight_interaction.c		\
			src/gameplay/interaction/destroy_sprites.c			\
			src/gameplay/interaction/display_pnj_text.c			\
			src/gameplay/interaction/text_settings.c			\
			src/gameplay/interaction/text_box_settings.c		\
			src/gameplay/interaction/pnj_interaction_vil.c		\
			src/gameplay/map_border.c							\
			src/gameplay/camera_border.c						\
			src/gameplay/buffer_in_array.c						\
			src/gameplay/map_management/change_map.c			\
			src/gameplay/map_management/check_enter_builds.c	\
			src/gameplay/map_management/check_leaving_builds.c	\
			src/gameplay/map_management/check_leave_dungeons.c	\
			src/gameplay/map_management/check_enter_dungeons.c	\
			src/gameplay/map_management/check_enter_fc.c		\
			src/gameplay/map_management/check_leaving_fc.c		\
			src/gameplay/movement_player/open_col_files.c		\
			src/gameplay/movement_player/move_player.c			\
			src/gameplay/movement_player/rect_in_movement.c		\
			src/gameplay/movement_player/set_player_direction.c	\
			src/gameplay/movement_player/set_player_rect.c		\
			src/gameplay/movement_player/set_player_moving.c	\
			src/gameplay/movement_player/set_player_running.c	\
			src/choose_character/choose_character.c				\
			src/choose_character/choose_character_display.c     \
			src/choose_character/choose_text.c                  \
			src/inv/items.c                  \
			src/pause/pause.c               \
			src/pause/draw_pause.c          \
			src/pause/quest.c               \
			src/pause/inv.c                 \
			src/fight/fight.c               \
			src/fight/fight_display.c       \
			src/fight/fight_turn.c          \
			src/fight/fight_init.c          \
			src/fight/music_fight.c         \
			src/fight/change_rect.c         \
			src/fight/select_enemis.c       \
			src/fight/detect_win.c

OBJ 	=	$(SRC:.c=.o)

NAME 	=	my_rpg

CFLAGS += -W -Wall -Wextra -pedantic -I./include

LFLAGS = -L./lib/my -lmy

all:	$(NAME)

$(NAME):	$(OBJ)
		@echo "entering in the $(LFLAGS)..."
		@make -C lib/my
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LFLAGS) -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

%.o : %.c
		@echo "Compiling $@..."
		@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@echo "removing *.o ..."
	@echo "removing my libmy.a ..."
	@rm -f lib/my/*.o
	@rm -f src/*.o
	@rm -f src/fight/*.o
	@rm -f src/menu/*.o
	@rm -f src/pause/*.o
	@rm -f src/inv/*.o
	@rm -f src/choose_character/*.o
	@rm -f src/gameplay/*.o
	@rm -f src/gameplay/interaction/*.o
	@rm -f src/gameplay/movement_player/*.o
	@rm -f lib/my/libmy.a
	@rm -f *.o

fclean:	clean
	@echo "removing $(NAME) ..."
	@rm -f $(NAME)

re: 	fclean all

debug:	CFLAGS += -g3
debug:	fclean all