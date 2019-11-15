/*
** EPITECH PROJECT, 2019
** CPool_Day11_2019
** File description:
** Task05 - Applies a function to the data of each nodes than match with dataref
*/

#include <stdlib.h>
#include "my_list.h"

int my_apply_on_matching_nodes(linked_list_t *begin, int (*f)(),
void const *data_ref, int (*cmp)())
{
    linked_list_t *ptr = begin;

    if (begin == NULL)
        return (-1);
    while (ptr != NULL) {
        if (cmp(ptr->data, data_ref) == 0)
            f(ptr->data);
        ptr = ptr->next;
    }
    return (0);
}
