/*
** EPITECH PROJECT, 2019
** my_sreensaver_2019
** File description:
** pong with sinusoidals - balle manager
*/

#include "w05_pong.h"

static void bounce(sfVector2i *vel_balle, char axis, int coef, int delta_cuve)
{
    if (axis == 'X') {
        if (/*(vel_balle->y > 0 && delta_cuve > 0) ||*/ (vel_balle->y < 0 && delta_cuve > 0)) {
            vel_balle->x = (double)ABS((50 - coef)) / 8.0 * (-1);
        } else {
            vel_balle->x = (double)(ABS((50 - coef)) / 8.0);
        }
        printf("ALPHA coef %d / %d %d\n", vel_balle->x, delta_cuve, ABS(50 - coef) / 10);
        vel_balle->y = -vel_balle->y;
    } else if (axis == 'Y') {
        vel_balle->x = -vel_balle->x;
    }
}

static void check_curve(sfVector2i *pos_balle, sfVector2i *vel_balle,
sinusoidal_t *sinus, char type)
{
    double temp = sin(sinus->shift + (double)pos_balle->x / sinus->coef.x);
    int pos_curve_y = temp * sinus->coef.y;
    double t2 = sin(sinus->shift + (double)pos_balle->x + 5 / sinus->coef.x);
    int center_crv = (sinus->start.y - sinus->coef.y / 2);
    int delta_cuve = (t2 * sinus->coef.y) - pos_curve_y;

    pos_curve_y += center_crv;
    if (type == 'U') {
        if (pos_balle->y <= pos_curve_y && vel_balle->y < 0)
            bounce(vel_balle, 'X', center_crv - pos_curve_y, delta_cuve);
    } else {
        if (pos_balle->y >= pos_curve_y && vel_balle->y > 0)
            bounce(vel_balle, 'X', center_crv - pos_curve_y, delta_cuve);
    }
}

static void check_collision(pong_t *pong, framebuffer_t *fb)
{
    if (pong->pos_balle.x >= fb->width || pong->pos_balle.x <= 0) {
        bounce(&pong->vel_balle, 'Y', 0, 0);
        return;
    }
    if (pong->pos_balle.y <= pong->sin01.start.y + pong->sin01.coef.y) {
        check_curve(&pong->pos_balle, &pong->vel_balle, &pong->sin01, 'U');
    }
    if (pong->pos_balle.y >= pong->sin02.start.y - 2 * pong->sin02.coef.y) {
        check_curve(&pong->pos_balle, &pong->vel_balle, &pong->sin02, 'D');
    }
}

void move_balle(pong_t *pong, framebuffer_t *fb)
{
    pong->pos_balle.x += pong->vel_balle.x;
    pong->pos_balle.y += pong->vel_balle.y;
    check_collision(pong, fb);
}
