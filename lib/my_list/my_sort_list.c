/*
** EPITECH PROJECT, 2019
** CPool_Day11_2019
** File description:
** Task09 - sort list
*/

#include <stdlib.h>
#include "my_list.h"

static void swap_intermediate(linked_list_t **begin, int (*cmp)(),
linked_list_t **ptr)
{
    linked_list_t *tmp;

    if (cmp((*ptr)->next->data, (*ptr)->next->next->data) > 0) {
        tmp = (*ptr)->next;
        (*ptr)->next = (*ptr)->next->next;
        tmp->next = (*ptr)->next->next;
        (*ptr)->next->next = tmp;
        (*ptr) = *begin;
    } else {
        (*ptr) = (*ptr)->next;
    }
}

void my_sort_list(linked_list_t **begin, int (*cmp)())
{
    linked_list_t *ptr = *begin;
    linked_list_t *tmp;

    if (ptr == NULL || ptr->next == NULL)
        return;
    while (ptr->next != NULL) {
        if (ptr == *begin && cmp((*begin)->data, (*begin)->next->data) > 0) {
            tmp = ptr->next;
            ptr->next = ptr->next->next;
            tmp->next = ptr;
            *begin = tmp;
            ptr = *begin;
        }
        if (ptr->next->next == NULL) {
            break;
        }
        swap_intermediate(begin, cmp, &ptr);
    }
}
