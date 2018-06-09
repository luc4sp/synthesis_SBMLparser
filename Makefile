##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## 
##

CC	=	gcc

SRC	=	sources/get_file.c	\
		sources/split.c		\
		sources/clean_str.c	\
		sources/requirement.c	\
		sources/help.c		\
		sources/main.c

CFLAGS	=	-I./include/ -g3

OBJ	=	$(SRC:.c=.o)

NAME	=	SBMLparser

all:	$(NAME)

$(NAME):	$(OBJ)
	@$(CC) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

exe:
	gcc $(OBJ) -o $(NAME)

re:	fclean all


