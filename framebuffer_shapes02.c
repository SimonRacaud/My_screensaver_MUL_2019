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

int draw_sinusoidal(framebuffer_t *fb, sinusoidal_t *sinu)
{
    sfVector2i coo = sinu->start;
    unsigned int space_y = (sinu->start.y - sinu->coef.y / 2);

    while (coo.x < (int)fb->width) {
        coo.y = sin(sinu->shift + (double)coo.x / sinu->coef.x) * sinu->coef.y;
        coo.y += space_y;
        for (unsigned int i = 0; i < sinu->border; i++)
            put_pixel(fb, coo.x, coo.y + i, &sinu->color);
        coo.x++;
    }
    return 0;
}

int draw_spiral(framebuffer_t *fb, sfVector2u *pos, int r)
{
    sfColor c = {255, 255, 255, 255};
    sfVector2u coord;

    for (double t = 0; t < 50; t += 0.01) {
        coord.x = r * (cos(t) + t * sin(t)) + pos->x;
        coord.y = r * (sin(t) - t * cos(t)) + pos->y;
        put_pixel(fb, coord.x, coord.y, &c);
    }
    return 0;
}
