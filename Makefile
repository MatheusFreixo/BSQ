##
## EPITECH PROJECT, 2022
## BSQ
## File description:
## Makefile
##

SRC	=	./src/bsq.c	\
		./src/my_algorithm_bsq.c	\
		./src/my_new_map.c	\
		./src/usage.c

OBJ	=	$(SRC:.c=.o)

LIBRARY	=	./lib/my/

LIB	=	libmy.a

FLAG	=	-Wall -o

NAME	=	bsq

all:	$(NAME)

$(NAME):	$(OBJ)
		make -C $(LIBRARY)
		gcc $(FLAG) $(NAME) $(OBJ) $(LIB)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(LIB)

re: fclean all
