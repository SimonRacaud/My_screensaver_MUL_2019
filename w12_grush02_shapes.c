/*
** EPITECH PROJECT, 2019
** my_screensaver_2019
** File description:
** w12_grush02 shapes
*/

#include "w12_grush02.h"

void draw_face(framebuffer_t *fb, sfVector2u *size, sfVector2u *pos)
{
    sfColor color = {255, 255, 255, 255};
    unsigned int y;
    double val = -28;

    for (unsigned int x = pos->x; x < pos->x + size->x; x++) {
        y = pos->y - (val * val);
        if (pos->y < (val * val))
            y = 0;
        val += 0.07;
        for (unsigned int i = 0; i < y; i++) {
            put_pixel(fb, x, y - i, &color);
        }
    }
}

void draw_arc(framebuffer_t *fb, unsigned int width, unsigned int border,
sfVector2u *pos)
{
    sfColor color = {0, 0, 0, 255};
    unsigned int x;
    unsigned int y;

    for (double t = 0; t >= -3.1416; t -= 0.01) {
        x = pos->x + width * cos(t);
        y = pos->y + width * sin(t) * 0.35;
        for (unsigned int i = 0; i < border; i++) {
            put_pixel(fb, x, y + i, &color);
        }
    }
}

void draw_smile(framebuffer_t *fb, unsigned int width, sfVector2u *pos,
double div)
{
    sfColor color = {0, 0, 0, 255};
    unsigned int x;
    unsigned int y;

    for (double t = 0; t >= -3.1416; t -= 0.001) {
        x = pos->x + width * cos(t);
        y = pos->y - width * sin(t) * 0.5;
        for (unsigned int i = 0; i < (y - pos->y) / div; i++) {
            put_pixel(fb, x, y + i, &color);
        }
    }
}

void draw_oval(framebuffer_t *fb, unsigned int width, sfVector2i *pos)
{
    sfColor color = {0, 0, 0, 255};
    unsigned int x;
    unsigned int y;

    for (double t = 0; t >= -3.1416; t -= 0.01) {
        x = pos->x + width * cos(t);
        y = pos->y + width * sin(t) * 0.3;
        for (int i = 0; i < pos->y - (int)y; i++) {
            put_pixel(fb, x, y + i, &color);
            put_pixel(fb, x, y + i + (pos->y - y), &color);
        }
    }
}
