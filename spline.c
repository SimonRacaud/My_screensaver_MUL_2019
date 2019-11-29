/*
** EPITECH PROJECT, 2019
** my_screensaver_2019
** File description:
** spline
*/

#include "framebuffer.h"

static const int nb_points = 6;

static void calc_pos(double *s, int *p, sfVector2u *points, sfVector2u *pos)
{
    pos->x = points[p[0]].x * s[0] + points[p[1]].x * s[1];
    pos->x += points[p[2]].x * s[2] + points[p[3]].x * s[3];
    pos->x /= 2;
    pos->y = points[p[0]].y * s[0] + points[p[1]].y * s[1];
    pos->y += points[p[2]].y * s[2] + points[p[3]].y * s[3];
    pos->y /= 2;
}

sfVector2u get_spline_point(double t, sfVector2u *points)
{
    int p[4];
    double s[4];
    double t_deci = t - (int)t;
    double tt = t_deci * t_deci;
    double ttt = tt * t_deci;
    sfVector2u pos;

    p[1] = (int)t;
    p[2] = (p[1] + 1) % nb_points;
    p[3] = (p[2] + 1) % nb_points;
    p[0] = (p[1] >= 1) ? (p[1] - 1) : (nb_points - 1);
    s[0] = -ttt + 2 * tt - t_deci;
    s[1] = 3 * ttt - 5 * tt + 2;
    s[2] = -3 * ttt + 4 * tt + t_deci;
    s[3] = ttt - tt;
    calc_pos(s, p, points, &pos);
    return pos;
}

void draw_spline(framebuffer_t *fb, sfVector2u *points)
{
    sfColor c = {255, 0, 0, 255};
    sfVector2u pos;

    for (double t = 0.0f; t < (double)nb_points; t += 0.001f) {
        pos = get_spline_point(t, points);
        put_pixel(fb, pos.x, pos.y, &c);
    }
}
