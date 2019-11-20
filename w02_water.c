/*
** EPITECH PROJECT, 2019
** my_sreensaver_2019
** File description:
** simulate water
*/

#include "w02_water.h"

static void fill_perlin(unsigned int *array, unsigned int *perm,
sfVector2i *size_matrix)
{
    int size = size_matrix->x * size_matrix->y;
    sfVector2f coord;
    double per;

    mix_permutation_table(perm);
    for (int p = 0; p < size; p++) {
        coord.y = p / size_matrix->x;
        coord.x = p - (coord.y * size_matrix->x);
        per = (perlin(coord.x, coord.y, 90, perm) + 1) / 2 * 255;
        array[p] = per;
    }
}

static void init(water_t *water, framebuffer_t *fb)
{
    unsigned int perm[512];
    sfVector2i size = {fb->width, fb->height};

    water->p01 = malloc(sizeof(unsigned int) * fb->width * fb->height);
    //water->p02 = malloc(sizeof(unsigned int) * fb->width * fb->height);
    water->shift = 0;
    for (unsigned int i = 0; i <= 255; i++)
        perm[i] = i;
    fill_perlin(water->p01, perm, &size);
    //size.y = fb->height;
    //size.x = fb->width;
    //fill_perlin(water->p02, perm, &size);
}

static void water_effect(framebuffer_t *fb, water_t *water)
{
    unsigned int size = fb->height * fb->width * 4;
    unsigned int pix_shift;
    sfVector2u coord;

    for (unsigned int p = 0; p < size; p += 4) {
        coord.y = p / (fb->width * 4);
        coord.x = p - (coord.y * fb->width * 4);
        pix_shift = (p / 4) + water->shift;
        //if (coord.x >= fb->width * 4 - water->shift)
        //    pix_shift = (p / 4) - water->shift;
        fb->pixels[p] = water->p01[p / 4];
        fb->pixels[p + 1] = water->p01[p / 4];
        fb->pixels[p + 2] = water->p01[p / 4];
        fb->pixels[p + 3] = 125;
    }
    if (water->shift == fb->width)
        water->shift = 0;
    else
        water->shift++;
}

static void display(window_t *w, sfClock *timer, water_t *water)
{
    if (sfClock_getElapsedTime(timer).microseconds > 2) {
        sfClock_restart(timer);
        //blur(w->fb, 3);
        water_effect(w->fb, water);
    }
    sfRenderWindow_clear(w->window, sfBlack);
    display_framebuffer(w->fb, w->window);
    sfRenderWindow_display(w->window);
}

int run02(void)
{
    sfEvent event;
    window_t *w = create_window(2);
    sfClock *timer = sfClock_create();
    water_t water1;
    water_t water2;

    init(&water1, w->fb);
    init(&water2, w->fb2);
    water_effect(w->fb, &water1);
    water_effect(w->fb2, &water2);
    if (!w)
        return 1;
    while (sfRenderWindow_isOpen(w->window)) {
        display(w, timer, &water1);
        while (sfRenderWindow_pollEvent(w->window, &event))
            event_manager(w, &event);
    }
    destroy_window(w);
    free(water1.p01);
    free(water2.p01);
    sfClock_destroy(timer);
    return 0;
}
