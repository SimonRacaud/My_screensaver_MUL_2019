/*
** EPITECH PROJECT, 2019
** my_screensaver_2019
** File description:
** header
*/

#ifndef H_W08
#define H_W08

#include "my_screensaver.h"

typedef struct vehicule {
    sfVector2u pos;
    sfColor c;
    sfVector2i velocity;
} vehicule_t;

void move_vehicule(vehicule_t *v, int nb, framebuffer_t *fb);
void change_dir_vehicule(vehicule_t *v, int nb);

#endif
