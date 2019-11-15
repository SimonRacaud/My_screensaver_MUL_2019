##
## EPITECH PROJECT, 2019
## LIB_misc_2019
## File description:
## Lib makefile
##

SRC	=	get_color.c		\
		my_showmem.c		\
		swap_endian_color.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra

NAME	=	libmy_misc.a

NAME_H	=	my_misc.h

all:	$(NAME)

$(NAME): $(OBJ)
	@cp $(NAME_H) ../../include/
	ar rc $(NAME) $(OBJ)
	@cp $(NAME) ../

clean:
	@$(RM) $(OBJ)

fclean:	clean
	@$(RM) $(NAME)

re:	clean all
