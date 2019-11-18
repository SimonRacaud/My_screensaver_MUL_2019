##
## EPITECH PROJECT, 2019
## csfml_template_2019
## File description:
## Project makefile
##

SRC	=	main.c			\
		create_window.c		\
		framebuffer_shapes01.c	\
		framebuffer_shapes02.c	\
		framebuffer.c		\
		basic.c			\
		perlin_noise.c		\
		framebuffer_blur.c	\
		w01_ground_generator.c	\
		w01_ground_generator_ext.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_sreeensaver

CFLAGS	+= -Wall -Wextra -I./include -g

all:	$(NAME)

$(NAME):	LIB $(OBJ)
	gcc -o $(NAME) $(OBJ) -L./lib -lmy -l csfml-graphics -lm -l csfml-system
	make clean

LIB:
	make -C ./lib/my

clean:
	rm -f  $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY :        clean fclean re
