##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile for the minishell1
##

SRC 	=	src/main.c\
			src/menu.c\
			src/music.c\
			src/menu_display.c

OBJ 	=	$(SRC:.c=.o)

NAME 	=	my_rpg

CFLAGS += -W -Wall -Wextra -g3 -pedantic -I./include

LFLAGS = -L./lib/my -lmy

all:	$(NAME)

$(NAME):	$(OBJ)
		make -C lib/my
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LFLAGS) -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio
clean:
	rm -f lib/my/*.o
	rm -f src/*.o
	rm -f lib/my/libmy.a
	rm -f *.o

fclean:	clean
	rm -f $(NAME)

re: 	fclean all