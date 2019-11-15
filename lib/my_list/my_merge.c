/*
** EPITECH PROJECT, 2019
** CPool_Day11_2019
** File description:
** Task11 - Merge two list and sort its elements
*/

#include "my_list.h"
#include <stdlib.h>

void my_merge(linked_list_t **begin1, linked_list_t **begin2, int (*cmp)())
{
    my_concat_list(begin1, *begin2);
    my_sort_list(begin1, cmp);
}
