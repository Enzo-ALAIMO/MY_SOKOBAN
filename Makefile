##
## EPITECH PROJECT, 2020
## Projects
## File description:
## Makefile
##

SRC = 	$(wildcard ./sources/*.c)

OBJ = $(SRC:.c=.o)

NAME = my_sokoban

CFLAGS =  -Wall -W -Wextra

CPPFLAGS = -I./

all:	$(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) sokoban.h -lncurses -g3

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
.PHONY: all clean fclean re
