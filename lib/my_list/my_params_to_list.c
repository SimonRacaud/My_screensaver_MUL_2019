/*
** EPITECH PROJECT, 2019
** CPool_Day11_2019
** File description:
** Task01 - Create a new list with args parameters
*/

#include <stdlib.h>
#include "my_list.h"

static int add_in_list(linked_list_t **list, char *str)
{
    linked_list_t *el = malloc(sizeof(*el));

    el->data = str;
    el->next = *list;
    *list = el;
    return (0);
}

linked_list_t *my_params_to_list(int ac, char * const *av)
{
    linked_list_t *list = NULL;

    for (int i = 0; i < ac; i++) {
        add_in_list(&list, av[i]);
    }
    return (list);
}
