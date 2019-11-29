##
## EPITECH PROJECT, 2019
## csfml_template_2019
## File description:
## Project makefile
##

SRC	=	main.c				\
		create_window.c			\
		framebuffer_shapes01.c		\
		framebuffer_shapes02.c		\
		framebuffer.c			\
		framebuffer_ext.c		\
		basic.c				\
		perlin_noise.c			\
		framebuffer_blur.c		\
		w01_ground_generator.c		\
		w01_ground_generator_ext.c	\
		w02_water.c			\
		w03_pipe.c			\
		w04_pipe_transform.c		\
		w05_pong.c			\
		w05_pong_balle.c		\
		w06_spiral.c			\
		w07_animated_sort.c		\
		quick_sort.c			\
		w07_animated_sort_qsort.c	\
		w08_tron_race.c			\
		w08_tron_race_game.c		\
		w09_text.c			\
		w10_bounce.c			\
		w10_bounce_balle.c		\
		w11_grush01.c			\
		w12_grush02.c			\
		w12_grush02_shapes.c		\
		my_font.c			\
		my_font_lines.c			\
		w13_spline.c			\
		spline.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_screensaver

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
