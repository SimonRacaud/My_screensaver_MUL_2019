/*
** EPITECH PROJECT, 2019
** LIB_misc_2019
** File description:
** LIB HEADER
*/

#ifndef MY_MISC_H_
#define MY_MISC_H_

union COLOR {
    int c;
    unsigned char first;
};

int get_color(unsigned char red, unsigned char green, unsigned char blue);

int swap_endian_color(int color);

int my_showmem(char const *str, int size);

#endif
