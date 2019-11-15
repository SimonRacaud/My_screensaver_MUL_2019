##
## EPITECH PROJECT, 2019
## LIB_list_2019
## File description:
## Lib makefile
##

SRC	=	my_params_to_list.c		\
		my_list_size.c			\
		my_rev_list.c			\
		my_apply_on_nodes.c		\
		my_apply_on_matching_nodes.c	\
		my_find_node.c			\
		my_delete_nodes.c		\
		my_concat_list.c		\
		my_sort_list.c			\
		my_add_in_sorted_list.c		\
		my_merge.c			\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra

NAME	=	libmy_list.a

NAME_H	=	my_list.h

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
