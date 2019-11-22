/*
** EPITECH PROJECT, 2019
** my_sreensaver_2019
** File description:
** spiral
*/

#include "w06_spiral.h"

static void draw_spiral_mod01(framebuffer_t *fb, sfVector2u *pos, double max,
double r)
{
    sfColor c = {255, 255, 255, 255};
    sfVector2u coord;

    for (double t = 0; t < max; t += 0.01) {
        coord.x = r * (cos(t) + t * sin(t)) + pos->x;
        coord.y = r * (sin(t) - t * cos(t)) + pos->y;
        put_pixel(fb, coord.x, coord.y, &c);
    }
}

static void display(window_t *w, sfVector2u *pos, spiral_t *spiral)
{
    spiral->shift_max += spiral->sens_x;
    spiral->shift_rayon += spiral->sens_y;
    if (spiral->shift_max == 60 || spiral->shift_max == 0) {
        spiral->sens_x = -spiral->sens_x;
    }
    if (spiral->shift_rayon > 20 || spiral->shift_rayon < 1.5) {
        spiral->sens_y = -spiral->sens_y;
    }
    framebuffer_clear(w->fb);
    draw_spiral_mod01(w->fb, pos, spiral->shift_max, spiral->shift_rayon);
}

int run06(program_t *prog)
{
    sfEvent event;
    window_t *w = create_window(1, prog);
    sfVector2u pos = {w->fb->width / 2, w->fb->height / 2};
    spiral_t spiral_config = {50, 2, 1, -0.05};

    if (!w)
        return 1;
    while (sfRenderWindow_isOpen(w->window)) {
        sfRenderWindow_clear(w->window, sfBlack);
        display_framebuffer(w->fb, w->window);
        sfRenderWindow_display(w->window);
        display(w, &pos, &spiral_config);
        while (sfRenderWindow_pollEvent(w->window, &event))
            event_manager(w, &event, prog);
    }
    destroy_window(w);
    return 0;
}
