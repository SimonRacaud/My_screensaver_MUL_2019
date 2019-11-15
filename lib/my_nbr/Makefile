##
## EPITECH PROJECT, 2019
## LIB_nbr_2019
## File description:
## Lib makefile
##

SRC	=	convert_base.c		\
		my_factorial_it.c	\
		my_find_prime_sup.c	\
		my_getnbr_base.c	\
		my_getnbr.c		\
		my_isneg.c		\
		my_is_prime.c		\
		my_power_rec.c		\
		my_putnbr_base.c	\
		my_putnbr_base_str.c	\
		my_put_nbr.c		\
		my_sort_int_array.c	\
		my_sqrt.c		\
		my_swap.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -I../../include

NAME	=	libmy_nbr.a

NAME_H	=	my_nbr.h

all:	$(NAME)

$(NAME):	$(OBJ)
	@cp $(NAME_H) ../../include/
	ar rc $(NAME) $(OBJ)
	@cp $(NAME) ../

clean:
	@$(RM) $(OBJ)

fclean:	clean
	@$(RM) $(NAME)

re:	clean all
