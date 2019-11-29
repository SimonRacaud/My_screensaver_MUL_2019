/*
** EPITECH PROJECT, 2019
** my_screensaver_2019
** File description:
** w13 spline
*/

#include "my_screensaver.h"

const int nb_points = 6;

static void draw_points(framebuffer_t *fb, sfVector2u *points)
{
    sfColor c = {255, 255, 255, 255};

    for (int i = 0; i < nb_points; i++) {
        draw_square(fb, &points[i], 6, &c);
    }
}

static void init(sfVector2u *points)
{
    points[0] = (sfVector2u){500, 300};
    points[1] = (sfVector2u){700, 400};
    points[2] = (sfVector2u){900, 300};
    points[3] = (sfVector2u){1000, 400};
    points[4] = (sfVector2u){900, 500};
    points[5] = (sfVector2u){600, 800};
}

static void display_ext(window_t *w, sfVector2u *points)
{
    static int sens_idx = 1;
    static int sens_shift = 1;
    static int idx_pt = 0;
    static int shift = 0;

    if (sfClock_getElapsedTime(w->timer).microseconds > 100) {
        sfClock_restart(w->timer);
        idx_pt += sens_idx;
        shift += sens_shift;
        if (idx_pt == nb_points - 1 || idx_pt == 0)
            sens_idx *= -1;
        if (shift == 30 || shift == -30)
            sens_shift = -sens_shift;
    }
    if (idx_pt % 2 != 0) {
        points[idx_pt].x += shift;
        points[idx_pt].y -= shift;
    }
}

static void display(window_t *w, sfVector2u *points)
{
    sfColor c = {255, 0, 0, 255};
    sfVector2u pos;

    display_ext(w, points);
    draw_points(w->fb, points);
    for (double t = 0.0f; t < (double)nb_points; t += 0.001f) {
        pos = get_spline_point(t, points);
        put_pixel(w->fb, pos.x, pos.y, &c);
    }
}

int run13(program_t *prog)
{
    sfEvent event;
    window_t *w = create_window(1, prog);
    sfVector2u points[6];
    sfVector2i pos_txt = {w->fb->width / 2 - 200, w->fb->height - 200};
    sfColor c = {255, 255, 255, 255};

    init(points);
    if (!w)
        return 1;
    while (sfRenderWindow_isOpen(w->window)) {
        framebuffer_clear(w->fb);
        display(w, points);
        display_str(w->fb, &pos_txt, "spline", &c);
        display_framebuffer(w->fb, w->window);
        sfRenderWindow_display(w->window);
        while (sfRenderWindow_pollEvent(w->window, &event))
            event_manager(w, &event, prog);
    }
    destroy_window(w);
    return 0;
}
