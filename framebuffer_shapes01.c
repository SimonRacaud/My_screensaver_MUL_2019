/*
** EPITECH PROJECT, 2019
** my_sreensaver_2019
** File description:
** framebuffer shapes 01
*/

#include "framebuffer.h"

int draw_square(framebuffer_t *fb, sfVector2u *pos, unsigned int size,
sfColor *color)
{
    for (unsigned int y = pos->y; y < (pos->y + size); y++) {
        for (unsigned int x = pos->x; x < (pos->x + size); x++) {
            put_pixel(fb, x, y, color);
        }
    }
    return 0;
}

int draw_rect(framebuffer_t *fb, sfVector2u *pos, sfVector2u *size,
sfColor *color)
{
    for (unsigned int y = pos->y; y < (pos->y + size->y); y++) {
        for (unsigned int x = pos->x; x < (pos->x + size->x); x++) {
            put_pixel(fb, x, y, color);
        }
    }
    return 0;
}

static void draw_line_ext(sfVector2i **point_a, sfVector2i **point_b,
double *a, double *b)
{
    sfVector2i *temp;

    if (point_a[0]->x - point_b[0]->x != 0) {
        *a = (double)(point_a[0]->y - point_b[0]->y);
        *a /= (point_a[0]->x - point_b[0]->x);
    }
    *b = point_a[0]->y - (*a) * point_a[0]->x;
    if (point_a[0]->x > point_b[0]->x || (*a == 0 && point_a[0]->y >
    point_b[0]->y)) {
        temp = *point_a;
        *point_a = *point_b;
        *point_b = temp;
    }
}

int draw_line(framebuffer_t *fb, sfVector2i *point_a, sfVector2i *point_b,
sfColor *c)
{
    double a = 0;
    double b = 0;
    sfVector2i p;

    draw_line_ext(&point_a, &point_b, &a, &b);
    if (point_a->x == point_b->x) {
        p.x = point_a->x;
        for (p.y = point_a->y; p.y < point_b->y; p.y++)
            put_pixel(fb, p.x, p.y, c);
    } else {
        for (p.x = point_a->x; p.x < point_b->x; p.x++) {
            p.y = a * p.x + b;
            put_pixel(fb, p.x, p.y, c);
        }
    }
    return 0;
}

int draw_circle(framebuffer_t *fb, circle_t *c)
{
    unsigned int x;
    unsigned int y;

    for (double i = -3.1415; i <= 3.1415; i += 0.001) {
        for (double j = c->border; j < c->size; j++) {
            x = (unsigned int)(cos(i) * j) + c->pos.x;
            y = (unsigned int)(sin(i) * j) + c->pos.y;
            put_pixel(fb, x, y, &c->color);
        }
    }
    return 0;
}
