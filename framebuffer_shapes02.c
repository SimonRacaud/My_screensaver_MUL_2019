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

void framebuffer_clear(framebuffer_t *fb)
{
    int size = fb->width * fb->height * 4;

    for (int i = 0; i < size; i += 4) {
        fb->pixels[i] = 0;
        fb->pixels[i + 1] = 0;
        fb->pixels[i + 2] = 0;
        fb->pixels[i + 3] = 255;
    }
}
