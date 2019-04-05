##
## EPITECH PROJECT, 2019
## makefile
## File description:
## compile my .c in a lib
##

SRC		=	$(wildcard *.c)

OBJ		=	$(SRC:.c=.o)

NAME	=	libmy.a

$(NAME):	$(OBJ)
		@echo "Compiling the lib ..."
		@ar rc $(NAME) $(OBJ)

%.o : %.c
		@echo "Compiling $@..."
		@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: 	fclean all
