/*
** EPITECH PROJECT, 2019
** CPool_Day11_2019
** File description:
** Task04 - applie a function to the data of each nodes
*/

#include <stdlib.h>
#include "my_list.h"

int my_apply_on_nodes(linked_list_t *begin, int (*f)(void *))
{
    linked_list_t *ptr = begin;

    if (begin == NULL)
        return (-1);
    while (ptr != NULL) {
        f(ptr->data);
        ptr = ptr->next;
    }
    return (0);
}
