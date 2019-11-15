##
## EPITECH PROJECT, 2019
## LIB_str_2019
## File description:
## Lib makefile
##

SRC	=	my_advanced_sort_word_array.c	\
		my_putchar.c			\
		my_putstr.c			\
		my_putstr_error.c		\
		my_revstr.c			\
		my_showstr.c			\
		my_show_word_array.c		\
		my_sort_word_array.c		\
		my_strcapitalize.c		\
		my_strcat.c			\
		my_strcmp.c			\
		my_strcpy.c			\
		my_strdup.c			\
		my_str_isalpha.c		\
		my_str_islower.c		\
		my_str_isnum.c			\
		my_str_isprintable.c		\
		my_str_isupper.c		\
		my_strlen.c			\
		my_strlowcase.c			\
		my_strncat.c			\
		my_strncmp.c			\
		my_strncpy.c			\
		my_strstr.c			\
		my_str_to_word_array.c		\
		my_strupcase.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -I../../include

NAME	=	libmy_str.a

NAME_H	=	my_str.h

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
