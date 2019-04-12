##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile for the minishell1
##

SRC 	=	src/main.c\
			src/music.c\
			src/menu/menu.c\
			src/menu/menu_display.c\
			src/menu/settings.c\
			src/menu/sound_bar.c\
			src/gameplay/character.c

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
	@rm -f src/menu/*.o
	@rm -f lib/my/libmy.a
	@rm -f *.o

fclean:	clean
	@echo "removing $(NAME) ..."
	@rm -f $(NAME)

re: 	fclean all

debug:	CFLAGS += -g3
debug:	fclean all