/*
** EPITECH PROJECT, 2019
** my_screensaver_2019
** File description:
** header
*/

#ifndef H_FONT
#define H_FONT

#include "my_screensaver.h"
#include "my.h"

static const int space_x = 30;
static const int space_y = 45;

#define MAX_CHAR 28

void set_line_v(framebuffer_t *fb, sfVector2i *position, sfVector2i *coord,
sfColor *color);

void set_line_h(framebuffer_t *fb, sfVector2i *position, sfVector2i *coord,
sfColor *color);

void set_diag_m(framebuffer_t *fb, sfVector2i *position, sfVector2i *coord,
sfColor *color);

void set_diag_d(framebuffer_t *fb, sfVector2i *position, sfVector2i *coord,
sfColor *color);

#endif
