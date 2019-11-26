/*
** EPITECH PROJECT, 2019
** my_screensaver_2019
** File description:
** header
*/

#ifndef H_W09
#define H_W09

#include "my_screensaver.h"

typedef struct limb {
    unsigned int len;
    int shift;
    unsigned int border;
    sfVector2u pos;
    sfVector2i coef;
    sfColor color;
} limb_t;

#endif
