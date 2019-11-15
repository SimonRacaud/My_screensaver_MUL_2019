/*
** EPITECH PROJECT, 2019
** csfml_framebuffer_2019
** File description:
** header
*/

#ifndef H_FB_HEADER
#define H_FB_HEADER

#include <SFML/Graphics.h>
#include <math.h>
#include <stdlib.h>

typedef struct framebuffer {
    sfUint8 *pixels;
    unsigned int width;
    unsigned int height;
    sfTexture *texture;
    sfSprite *sprite;
} framebuffer_t;

typedef struct circle {
    sfVector2u pos;
    sfColor color;
    double size;
    double border;
} circle_t;

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);
void framebuffer_destroy(framebuffer_t *buffer);
void display_framebuffer(framebuffer_t *fb, sfRenderWindow *w);
void framebuffer_perlin_noise(framebuffer_t *fb);

int put_pixel(framebuffer_t *framebuffer, unsigned int x, unsigned int y,
sfColor *color);
int draw_square(framebuffer_t *fb, sfVector2u *pos, unsigned int size,
sfColor *color);
int draw_rect(framebuffer_t *fb, sfVector2u *pos, sfVector2u *size,
sfColor *color);
int draw_line(framebuffer_t *fb, sfVector2i *point_a, sfVector2i *point_b,
sfColor *c);
int draw_circle(framebuffer_t *fb, circle_t *c);
int draw_circle2(framebuffer_t *framebuffer, sfVector2i *center, int radius);

double perlin(double x, double y, int res, unsigned int *perm);
void mix_permutation_table(unsigned int *permutation_table);

#endif
