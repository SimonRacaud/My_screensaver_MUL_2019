/*
** EPITECH PROJECT, 2019
** CPool_Day11_2019
** File description:
** Task06 - Return the address of the 1st nodes that data == data_ref
*/

#include <stdlib.h>
#include "my_list.h"

linked_list_t *my_find_node(linked_list_t *begin,
void const *data_ref, int (*cmp)())
{
    linked_list_t *ptr = begin;

    if (begin == NULL)
        return (NULL);
    while (ptr != NULL) {
        if (cmp(ptr->data, data_ref) == 0)
            return (ptr);
        ptr = ptr->next;
    }
    return (NULL);
}
