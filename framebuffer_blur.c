/*
** EPITECH PROJECT, 2019
** my_sreensaver_2019
** File description:
** framebuffer blur effect
*/

#include "framebuffer.h"

static sfUint8 average(sfVector2u *center, unsigned int size,
framebuffer_t *fb)
{
    sfVector2u c = {center->x - floor(size / 2), center->y - floor(size / 2)};
    int sum = 0;
    unsigned int pos;

    if (c.y < size || c.x < size || c.y == (fb->width * 4) - size)
        return (0);
    for (unsigned int y = c.y; y < c.y + size; y++) {
        for (unsigned int x = c.x; x < c.x + size; x++) {
            pos = (y * (fb->width * 4)) + x;
            sum += fb->pixels[pos];
        }
    }
    //printf("sum : %d\n", sum);
    return (sum / (size * size));
}

void blur(framebuffer_t *fb, unsigned int coef)
{
    sfVector2u coord = {0, 0};
    unsigned int pos;

    while (coord.y < fb->height - coef) {
        pos = (coord.y * fb->width * 4) + coord.x;
        fb->pixels[pos] = average(&coord, coef, fb);
        coord.x++;
        if (coord.x == (fb->width * 4) - (coef / 2)) {
            coord.x = 0;
            coord.y++;
        }
    }
}
