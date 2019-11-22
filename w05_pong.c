/*
** EPITECH PROJECT, 2019
** my_sreensaver_2019
** File description:
** pong with sinusoidals
*/

#include "w05_pong.h"

static void draw_elements(pong_t *pong, framebuffer_t *fb)
{
    draw_circle2(fb, &pong->pos_balle, 10, &pong->color_balle);
    draw_sinusoidal(fb, &pong->sin01);
    draw_sinusoidal(fb, &pong->sin02);
    pong->sin01.shift += 0.1;
    pong->sin02.shift -= 0.1;
}

static void display(window_t *w, pong_t *pong)
{
    move_balle(pong, w->fb);
    framebuffer_clear(w->fb);
    draw_elements(pong, w->fb);
}

static void init_sinus(pong_t *pong, framebuffer_t *fb)
{
    sfColor color_curve = {255, 255, 255, 255};
    sfVector2i pos_curve1 = {0, 100};
    sfVector2i pos_curve2 = {0, fb->height - 100};
    sfVector2i coef = {100, 50};
    double shift[2] = {0, 20};

    pong->sin01.start = pos_curve1;
    pong->sin01.coef = coef;
    pong->sin01.color = color_curve;
    pong->sin01.border = 8;
    pong->sin01.len = fb->width;
    pong->sin01.shift = shift[0];
    pong->sin02 = pong->sin01;
    pong->sin02.start = pos_curve2;
    pong->sin02.shift = shift[1];
}

static void init_pong(pong_t *pong, program_t *prog, framebuffer_t *fb)
{
    sfVector2i balle_pos = {prog->width / 2, prog->height / 2};
    sfColor color_balle = {255, 255, 255, 255};

    pong->pos_balle = balle_pos;
    pong->color_balle = color_balle;
    pong->vel_balle.x = 0;
    pong->vel_balle.y = 8;
    init_sinus(pong, fb);
}

int run05(program_t *prog)
{
    sfEvent event;
    window_t *w = create_window(1, prog);
    pong_t pong;

    init_pong(&pong, prog, w->fb);
    if (!w)
        return 1;
    while (sfRenderWindow_isOpen(w->window)) {
        sfRenderWindow_clear(w->window, sfBlack);
        display_framebuffer(w->fb, w->window);
        sfRenderWindow_display(w->window);
        display(w, &pong);
        while (sfRenderWindow_pollEvent(w->window, &event))
            event_manager(w, &event, prog);
    }
    destroy_window(w);
    return 0;
}
