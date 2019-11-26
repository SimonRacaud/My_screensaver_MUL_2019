/*
** EPITECH PROJECT, 2019
** my_screensaver_2019
** File description:
** header
*/

#ifndef H_W10
#define H_W10

#include "my_screensaver.h"

typedef struct balle {
    sfVector2i pos;
    int rayon;
    sfVector2i velocity;
    sfColor color;
} balle_t;

void move_balle10(balle_t *balle, window_t *w);

#endif
