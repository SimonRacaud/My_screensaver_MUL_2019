/*
** EPITECH PROJECT, 2019
** my_sreensaver_2019
** File description:
** simulate water
*/

//#include "w03_pipe.h"
#include "my_screensaver.h"

static void draw_triangle(framebuffer_t *fb)
{
    sfVector2i center = {fb->width / 2, fb->height / 2 + 2};
    int space = fb->width / 8;
    sfVector2i down = {space, fb->height};
    sfVector2i top = {0, 0};
    sfColor color = {200, 0, 0, 255};

    while (down.x < (int)fb->width - space) {
        draw_line(fb, &center, &down, &color);
        down.x += 5;
    }
    draw_line(fb, &center, &top, &color);
    top.x = fb->width;
    draw_line(fb, &center, &top, &color);
}

static void draw_pipe(framebuffer_t *fb, int *shift)
{
    int nb_circle = 38;
    sfColor c = {255 - nb_circle, 0, 0, 255};
    int space_circle = 3;
    sfVector2u pos = {fb->width / 2, fb->height / 2};
    circle_t circle = {pos, c, 0, 0};

    for (int i = 1; i <= nb_circle; i++) {
        circle.size = (i * i * space_circle) + *shift * i;
        circle.border = circle.size - 5;
        circle.color.r -= i;
        draw_circle(fb, &circle);
    }
    (*shift)++;
    if (*shift == space_circle * 2)
        *shift = 0;
    draw_triangle(fb);
}

static void display(window_t *w, sfClock *timer, int *shift)
{
    if (sfClock_getElapsedTime(timer).microseconds > 0) {
        sfClock_restart(timer);
        framebuffer_clear(w->fb);
        draw_pipe(w->fb, shift);
    }
    sfRenderWindow_clear(w->window, sfBlack);
    display_framebuffer(w->fb, w->window);
    sfRenderWindow_display(w->window);
}

int run03(void)
{
    sfEvent event;
    window_t *w = create_window(1);
    sfClock *timer = sfClock_create();
    int shift = 0;

    if (!w)
        return 1;
    while (sfRenderWindow_isOpen(w->window)) {
        while (sfRenderWindow_pollEvent(w->window, &event))
            event_manager(w, &event);
        if (w->fb != NULL)
            display(w, timer, &shift);
    }
    destroy_window(w);
    sfClock_destroy(timer);
    return 0;
}
