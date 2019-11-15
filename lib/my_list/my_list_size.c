/*
** EPITECH PROJECT, 2019
** CPool_Day11_2019
** File description:
** Task02 - Return the size of a list
*/

#include "my_list.h"
#include <stdlib.h>

int my_list_size(linked_list_t const *begin)
{
    linked_list_t *ptr;
    int len = 1;

    if (begin == NULL)
        return (0);
    ptr = begin->next;
    while (ptr != NULL) {
        len++;
        ptr = ptr->next;
    }
    return (len);
}
