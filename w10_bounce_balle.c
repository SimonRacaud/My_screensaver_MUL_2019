/*
** EPITECH PROJECT, 2019
** my_screensaver_2019
** File description:
** bounce
*/

#include "w10_bounce.h"

static void check_bounce(balle_t *balle, framebuffer_t *fb)
{
    if (balle->pos.x <= 10 && balle->velocity.x < 0) {
        balle->velocity.x += 2;
        balle->velocity.x *= -1;
    } else if (balle->pos.x >= (int)fb->width - 10 && balle->velocity.x > 0) {
        balle->velocity.x -= 2;
        balle->velocity.x *= -1;
    }
    if (balle->pos.y <= 10 && balle->velocity.y > 0) {
        balle->velocity.y *= -1;
    } else if (balle->pos.y >= (int)fb->height - 70 && balle->velocity.y < 0) {
        balle->velocity.y = balle->velocity.y * (-0.9) - 1;
    }
}

void relaunch_balle(balle_t *balle)
{
    balle->velocity.y = 45;
    balle->velocity.x = 15;
}

void move_balle10(balle_t *balle, window_t *w)
{
    balle->pos.x += balle->velocity.x;
    balle->pos.y -= balle->velocity.y;
    if (balle->velocity.y < 0) {
        balle->velocity.y--;
    } else if (balle->velocity.y > 0) {
        balle->velocity.y--;
    } else {
        if (balle->pos.y != (int)w->fb->height - 10)
            balle->velocity.y--;
    }
    if (sfClock_getElapsedTime(w->timer).microseconds > 2000000) {
        sfClock_restart(w->timer);
        if (balle->velocity.x < 0)
            balle->velocity.x++;
        else if (balle->velocity.x > 0)
            balle->velocity.x--;
        else
            relaunch_balle(balle);
    }
    check_bounce(balle, w->fb);
}
