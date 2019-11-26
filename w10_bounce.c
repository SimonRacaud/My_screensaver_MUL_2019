/*
** EPITECH PROJECT, 2019
** my_screensaver_2019
** File description:
** bounce
*/

#include "w10_bounce.h"

static void display(window_t *w, balle_t *balle)
{
    move_balle10(balle, w);
    framebuffer_substract(w->fb, 2);
    draw_circle2(w->fb, &balle->pos, balle->rayon, &balle->color);
}

int run10(program_t *prog)
{
    sfEvent event;
    window_t *w = create_window(1, prog);
    balle_t balle = {{0, 0}, 10, {12, -8}, {255, 255, 255, 255}};

    if (!w)
        return 1;
    while (sfRenderWindow_isOpen(w->window)) {
        sfRenderWindow_clear(w->window, sfBlack);
        display_framebuffer(w->fb, w->window);
        sfRenderWindow_display(w->window);
        display(w, &balle);
        while (sfRenderWindow_pollEvent(w->window, &event))
            event_manager(w, &event, prog);
    }
    destroy_window(w);
    return 0;
}
