/*
** EPITECH PROJECT, 2019
** my_screensaver_2019
** File description:
** pipe with road
*/

#include "my_screensaver.h"

static void draw_triangle(framebuffer_t *fb, int *shift)
{
    sfVector2i center = {fb->width / 2, fb->height / 2 + 2};
    int space = fb->width / 10 + (*shift * 5);
    sfVector2i down = {space, fb->height};
    sfColor color = {200, 200, 200, 255};

    while (down.x <= (int)fb->width - space) {
        draw_line(fb, &center, &down, &color);
        down.x += (*shift / 2) + 2;
    }
}

static void draw_pipe(framebuffer_t *fb, int *shift)
{
    int nb_circle = 20;
    sfColor c = {255, 255, 255, 255};
    double space_circle = 3;
    sfVector2u pos = {fb->width / 2, fb->height / 2};
    circle_t circle = {pos, c, 0, 0};

    for (int i = 1; i <= nb_circle; i++) {
        circle.size = (i * i * space_circle) + *shift * i;
        circle.border = circle.size - 5;
        circle.color.r -= i;
        circle.color.g -= i;
        circle.color.b -= i;
        draw_circle(fb, &circle);
    }
    draw_triangle(fb, shift);
    (*shift)++;
    if (*shift == space_circle * 2)
        *shift = 0;
}

static void display(window_t *w, int *shift)
{
    framebuffer_clear(w->fb);
    draw_pipe(w->fb, shift);
    sfRenderWindow_clear(w->window, sfBlack);
    display_framebuffer(w->fb, w->window);
    sfRenderWindow_display(w->window);
}

int run03(program_t *prog)
{
    sfEvent event;
    window_t *w = create_window(1, prog);
    int shift = 0;

    if (!w)
        return 1;
    while (sfRenderWindow_isOpen(w->window)) {
        display(w, &shift);
        while (sfRenderWindow_pollEvent(w->window, &event))
            event_manager(w, &event, prog);
    }
    destroy_window(w);
    return 0;
}
