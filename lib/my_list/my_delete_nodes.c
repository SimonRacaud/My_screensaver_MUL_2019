/*
** EPITECH PROJECT, 2019
** CPool_Day11_2019
** File description:
** Task07 - Removes all nodes containing data equal to the reference data
*/

#include <stdlib.h>
#include "my_list.h"

static void delete_inter_node(linked_list_t **ptr, linked_list_t *prev,
linked_list_t **next)
{
    prev->next = (*ptr)->next;
    *next = (*ptr)->next;
    free(*ptr);
    *ptr = *next;
}

static void delete_first_node(linked_list_t **ptr, linked_list_t **next,
linked_list_t **begin)
{
    *begin = (*ptr)->next;
    *next = (*ptr)->next;
    free(*ptr);
    *ptr = *next;
}

int my_delete_nodes(linked_list_t **begin, void const *data_ref, int (*cmp)())
{
    linked_list_t *ptr = *begin;
    linked_list_t *prev = NULL;
    linked_list_t *next = NULL;

    if (*begin == NULL)
        return (-1);
    while (ptr != NULL) {
        if (cmp(ptr->data, data_ref) == 0 && prev != NULL) {
            delete_inter_node(&ptr, prev, &next);
        } else if (cmp(ptr->data, data_ref) == 0) {
            delete_first_node(&ptr, &next, begin);
        } else {
            prev = ptr;
            ptr = ptr->next;
        }
    }
    return (0);
}
