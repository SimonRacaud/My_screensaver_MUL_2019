/*
** EPITECH PROJECT, 2019
** my_sreensaver_2019
** File description:
** pong with sinusoidals - balle manager
*/

#include "w05_pong.h"

static void bounce(sfVector2i *vel_balle, char axis, int delta_cuve)
{
    if (axis == 'X') {
        if (vel_balle->y > 0) {
            vel_balle->x = delta_cuve;
        } else {
            vel_balle->x = -delta_cuve;
        }
        vel_balle->y = -vel_balle->y;
    } else if (axis == 'Y') {
        vel_balle->x = -vel_balle->x;
    }
}

static int get_pos_y_curve(int pos_x_balle, sinusoidal_t *sinus)
{
    double pos = sin(sinus->shift + (double)pos_x_balle / sinus->coef.x);

    return (pos * sinus->coef.y) + (sinus->start.y - sinus->coef.y / 2);
}

static void check_curve(sfVector2i *pos_balle, sfVector2i *vel_balle,
sinusoidal_t *sinus, char type)
{
    int pos_curve_y = get_pos_y_curve(pos_balle->x, sinus);
    int delta_cuve = get_pos_y_curve(pos_balle->x + 30, sinus) - pos_curve_y;

    if (type == 'U') {
        if (pos_balle->y <= pos_curve_y + 15 && vel_balle->y < 0)
            bounce(vel_balle, 'X', delta_cuve);
    } else {
        if (pos_balle->y >= pos_curve_y - 15 && vel_balle->y > 0)
            bounce(vel_balle, 'X', delta_cuve);
    }
}

static void check_collision(pong_t *pong, framebuffer_t *fb)
{
    if (pong->pos_balle.x >= (int)fb->width || pong->pos_balle.x <= 0) {
        bounce(&pong->vel_balle, 'Y', 0);
        return;
    }
    if (pong->pos_balle.y <= pong->sin01.start.y + pong->sin01.coef.y)
        check_curve(&pong->pos_balle, &pong->vel_balle, &pong->sin01, 'U');
    if (pong->pos_balle.y >= pong->sin02.start.y - 2 * pong->sin02.coef.y)
        check_curve(&pong->pos_balle, &pong->vel_balle, &pong->sin02, 'D');
}

void move_balle(pong_t *pong, framebuffer_t *fb)
{
    pong->pos_balle.x += pong->vel_balle.x;
    pong->pos_balle.y += pong->vel_balle.y;
    check_collision(pong, fb);
}
