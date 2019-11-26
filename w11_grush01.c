/*
** EPITECH PROJECT, 2019
** my_screensaver_2019
** File description:
** w11_grush01
*/

#include "w11_grush01.h"

static void init_perm_table(unsigned int *table)
{
    for (int i = 0; i <= 255; i++)
        table[i] = i;
    mix_permutation_table(table);
}

static void draw_sublighting(framebuffer_t *fb, unsigned int posx,
unsigned int posy, unsigned int b_size)
{
    sfColor white = {255, 255, 255, 255};
    unsigned int perm[512];
    sfVector2u coord;
    double per[3];
    unsigned int size = rand() % ((fb->height - posy + 1) / (7 - b_size));

    init_perm_table(perm);
    for (coord.y = posy; coord.y < posy + size; coord.y++) {
        per[0] = (perlin(coord.y, 0, 400, perm) + 1) / 2 * 2000;
        per[1] = (perlin(coord.y, 0, 40, perm) + 1) / 2 * 200;
        per[2] = (perlin(coord.y, 0, 10, perm) + 1) / 2 * 100;
        if (coord.y == posy)
            posx = posx - (per[0] * 0.6 + per[1] * 0.3 + per[2] * 0.1);
        coord.x = per[0] * 0.6 + per[1] * 0.3 + per[2] * 0.1 + posx;
        for (unsigned int border = 0; border < b_size; border++)
            put_pixel(fb, coord.x + border, coord.y, &white);
        if (b_size > 1 && (coord.y + 1) % 100 == 0 && rand() % 2 == 1)
            draw_sublighting(fb, coord.x, coord.y, b_size - 2);
    }
}

static void draw_lighting(framebuffer_t *fb, unsigned int posx,
unsigned int posy, unsigned int b_size)
{
    sfColor white = {255, 255, 255, 255};
    unsigned int perm[512];
    sfVector2u coord;
    double per[3];

    init_perm_table(perm);
    for (coord.y = posy; coord.y < fb->height; coord.y++) {
        per[0] = (perlin(coord.y, 0, 400, perm) + 1) / 2 * 1500;
        per[1] = (perlin(coord.y, 0, 40, perm) + 1) / 2 * 200;
        per[2] = (perlin(coord.y, 0, 10, perm) + 1) / 2 * 100;
        if (coord.y == posy)
            posx = posx - (per[0] * 0.6 + per[1] * 0.3 + per[2] * 0.1);
        coord.x = per[0] * 0.6 + per[1] * 0.3 + per[2] * 0.1 + posx;
        for (unsigned int border = 0; border < b_size; border++)
            put_pixel(fb, coord.x + border, coord.y, &white);
        if (coord.y % 100 == 0 && rand() % 4 == 1)
            draw_sublighting(fb, coord.x, coord.y, b_size - 1);
    }
}

static void lighting(window_t *w, int dis_timer)
{
    unsigned int posx;

    if (dis_timer || sfClock_getElapsedTime(w->timer).microseconds > 1500000) {
        sfClock_restart(w->timer);
        for (int i = 1; i <= 5; i++) {
            posx = w->fb->width / 6 * i;
            draw_lighting(w->fb, posx, 0, 4);
        }
    }
}

int run11(program_t *prog)
{
    sfEvent event;
    window_t *w = create_window(1, prog);

    if (!w)
        return 1;
    lighting(w, 1);
    while (sfRenderWindow_isOpen(w->window)) {
        sfRenderWindow_clear(w->window, sfBlack);
        display_framebuffer(w->fb, w->window);
        sfRenderWindow_display(w->window);
        framebuffer_substract(w->fb, 5);
        lighting(w, 0);
        while (sfRenderWindow_pollEvent(w->window, &event))
            event_manager(w, &event, prog);
    }
    destroy_window(w);
    return 0;
}
