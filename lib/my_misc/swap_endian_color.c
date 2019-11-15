/*
** EPITECH PROJECT, 2019
** CPool_Day09_2019
** File description:
** Task06 - changes the endianness of the color
*/

#include "my_misc.h"

int swap_endian_color(int color)
{
    union COLOR color_u;
    int color_rev = 0;

    color_u.c = color;
    for (int i = 0; i < 3; i++) {
        color_rev += color_u.first;
        color_rev = color_rev << 8;
        color_u.c = color_u.c >> 8;
    }
    color_rev += color_u.first;
    return (color_rev);
}
