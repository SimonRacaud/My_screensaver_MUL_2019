/*
** EPITECH PROJECT, 2019
** my_screensaver_2019
** File description:
** custom font
*/

#include "my_font.h"

void set_line_v(framebuffer_t *fb, sfVector2i *position, sfVector2i *coord,
sfColor *color)
{
    sfVector2i p[2];

    p[0].x = position->x + space_x * coord->x;
    p[0].y = position->y + space_y * coord->y;
    p[1].x = position->x + space_x * coord->x;
    p[1].y = position->y + space_y * (coord->y + 1);
    draw_line(fb, &p[0], &p[1], color);
}

void set_line_h(framebuffer_t *fb, sfVector2i *position, sfVector2i *coord,
sfColor *color)
{
    sfVector2i p[2];

    p[0].x = position->x + space_x * coord->y;
    p[0].y = position->y + space_y * coord->x;
    p[1].x = position->x + space_x * (coord->y + 1);
    p[1].y = position->y + space_y * coord->x;
    draw_line(fb, &p[0], &p[1], color);
}

void set_diag_m(framebuffer_t *fb, sfVector2i *position, sfVector2i *coord,
sfColor *color)
{
    sfVector2i p[2];

    p[0].x = position->x + space_x * coord->y;
    p[0].y = position->y + space_y * coord->x;
    p[1].x = position->x + space_x * (coord->y + 1);
    p[1].y = position->y + space_y * (coord->x + 1);
    draw_line(fb, &p[0], &p[1], color);
}

void set_diag_d(framebuffer_t *fb, sfVector2i *position, sfVector2i *coord,
sfColor *color)
{
    sfVector2i p[2];

    p[0].x = position->x + space_x * (coord->y + 1);
    p[0].y = position->y + space_y * coord->x;
    p[1].x = position->x + space_x * coord->y;
    p[1].y = position->y + space_y * (coord->x + 1);
    draw_line(fb, &p[0], &p[1], color);
}
