/*
** EPITECH PROJECT, 2019
** CPool_Day11_2019
** File description:
** Task08 - concat two lists
*/

#include <stdlib.h>
#include "my_list.h"

void my_concat_list(linked_list_t **begin1, linked_list_t *begin2)
{
    linked_list_t *ptr = *begin1;

    while (ptr != NULL) {
        if (ptr->next == NULL) {
            ptr->next = begin2;
            break;
        }
        ptr = ptr->next;
    }
    if (*begin1 == NULL)
        *begin1 = begin2;
}
