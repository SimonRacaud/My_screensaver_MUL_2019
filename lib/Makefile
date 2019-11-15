##
## EPITECH PROJECT, 2019
## LIB_all_2019
## File description:
## Lib makefile
##

all:	$(LIB)

$(LIB):
	make -C ./my_list
	make -C ./my_misc
	make -C ./my_nbr
	make -C ./my_str

clean:
	make clean -C ./my_list
	make clean -C ./my_misc
	make clean -C ./my_nbr
	make clean -C ./my_str

fclean:
	make fclean -C ./my_list
	make fclean -C ./my_misc
	make fclean -C ./my_nbr
	make fclean -C ./my_str

re:	clean all
