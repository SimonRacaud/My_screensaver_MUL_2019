/*
** EPITECH PROJECT, 2019
** my_screensaver_2019
** File description:
** header
*/

#ifndef H_W05
#define H_W05

#include <math.h>
#include "my_screensaver.h"

typedef struct pong {
    sfVector2i vel_balle;
    sfVector2i pos_balle;
    sfColor color_balle;
    sinusoidal_t sin01;
    sinusoidal_t sin02;
} pong_t;

void move_balle(pong_t *pong, framebuffer_t *fb);

#endif
