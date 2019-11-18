/*
** EPITECH PROJECT, 2019
** my_screensaver_2019
** File description:
** header
*/

#ifndef H_W01
#define H_W01

#include "my_screensaver.h"

typedef struct map {
    double *map;
    unsigned int height;
    unsigned int width;
    int altitude;
} map_t;

sfColor select_color(double altitude);
void map_to_framebuffer(framebuffer_t *fb, map_t *map);
void put_tree(framebuffer_t *fb, map_t *map);

#endif
