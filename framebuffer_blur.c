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

    for (unsigned int y = c.y; y < c.y + size; y++) {
        for (unsigned int x = c.x; x < c.x + size; x++) {
            pos = (y * fb->width) + x;
            sum += fb->pixels[pos];
        }
    }
    //printf("sum : %d\n", sum);
    return (sum / (size * size));
}

void blur(framebuffer_t *fb, unsigned int coef)
{
    sfVector2u coord = {coef / 2, coef / 2};
    sfVector2u coord_end = {fb->width - (coef / 2), fb->height - (coef / 2)};
    unsigned int pos;

    while (pos < (fb->width * fb->height) - coef) {
        pos = (coord.y * fb->width) + coord.x;
        //printf("%d %u - %u %u\n", fb->pixels[pos], pos, coord.x, coord.y);
        fb->pixels[pos] = average(&coord, coef, fb);
        coord.x++;
        if (coord.x == fb->width) {
            coord.x = coef;
            coord.y++;
        }
    }
}
