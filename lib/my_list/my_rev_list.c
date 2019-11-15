/*
** EPITECH PROJECT, 2019
** CPool_Day11_2019
** File description:
** Task03 - reverses order of a list
*/

#include "my_list.h"
#include <stdlib.h>

void my_rev_list(linked_list_t **begin)
{
    linked_list_t *prev = NULL;
    linked_list_t *ptr = *begin;
    linked_list_t *next;

    if (ptr != NULL)
    {
        while (ptr->next != NULL) {
            next = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = next;
        }
        ptr->next = prev;
        *begin = ptr;
    }
}
