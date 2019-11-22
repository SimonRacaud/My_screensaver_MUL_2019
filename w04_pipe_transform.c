/*
** EPITECH PROJECT, 2019
** my_screensaver_2019
** File description:
** move the pipe
*/

#include "my_screensaver.h"

static void draw_pipe(framebuffer_t *fb, int *shift, int mode)
{
    int nb_circle = 26;
    sfColor c = {255, 255, 255, 255};
    double space_circle = 3;
    sfVector2u pos = {fb->width - 20, fb->height / 2};
    circle_t circle = {pos, c, 0, 0};

    for (int i = 1; i <= nb_circle; i++) {
        circle.size = (i * i * space_circle) + (*shift * i);
        circle.border = circle.size - 5;
        circle.pos.x += (*shift) + i;
        circle.color.r = c.r - i * 5;
        circle.color.g = c.g - i * 5;
        circle.color.b = c.b - i * 5;
        if (mode > 0)
            circle.color.a = 255 - i / (*shift - 2);
        if ((mode < 0 && circle.size < 0) || mode > 0)
            draw_circle(fb, &circle);
    }
}

static void display(window_t *w)
{
    static int sens = 1;
    static int shift = 0;
    static int mode = 1;

    if (sfClock_getElapsedTime(w->timer).microseconds > 10000) {
        sfClock_restart(w->timer);
        shift += sens;
        if (sens == 1 && shift == 1)
            sens = -1;
        if (sens == -1 && shift == -80) {
            sens = 1;
            mode = -mode;
        }
    }
    framebuffer_clear(w->fb);
    draw_pipe(w->fb, &shift, mode);
}

int run04(program_t *prog)
{
    sfEvent event;
    window_t *w = create_window(1, prog);

    if (!w)
        return 1;
    while (sfRenderWindow_isOpen(w->window)) {
        sfRenderWindow_clear(w->window, sfBlack);
        display_framebuffer(w->fb, w->window);
        sfRenderWindow_display(w->window);
        display(w);
        while (sfRenderWindow_pollEvent(w->window, &event))
            event_manager(w, &event, prog);
    }
    destroy_window(w);
    return 0;
}
