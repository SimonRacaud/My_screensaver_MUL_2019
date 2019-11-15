/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** Task06
*/

#include "my_str.h"

int my_strcmp(char const *s1, char const *s2)
{
    int size;

    if (my_strlen(s1) > my_strlen(s2))
        size = my_strlen(s1);
    else
        size = my_strlen(s2);
    return (my_strncmp(s1, s2, size));
}
