/*
** EPITECH PROJECT, 2019
** my_sreensaver_2019
** File description:
** framebuffer shapes 02
*/

#include "framebuffer.h"

int draw_circle2(framebuffer_t *framebuffer, sfVector2i *center, int radius,
sfColor *c)
{
    sfVector2i p;
    int r2 = radius * radius;

    if (radius < 0)
        radius = -radius;
    for (p.x = 0; p.x <= radius; p.x++) {
        p.y = sqrt(r2 - (p.x * p.x)) + 0.5;
        for (int y = p.y; y >= 0; y--) {
            put_pixel(framebuffer, center->x + p.x, center->y + y, c);
            put_pixel(framebuffer, center->x - p.x, center->y + y, c);
            put_pixel(framebuffer, center->x + p.x, center->y - y, c);
            put_pixel(framebuffer, center->x - p.x, center->y - y, c);
        }
    }
    return 0;
}
