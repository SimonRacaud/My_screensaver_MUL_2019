/*
** EPITECH PROJECT, 2019
** my_screensaver_2019
** File description:
** Tron race
*/

#include "w08_tron_race.h"

static void bounce(vehicule_t *bike, framebuffer_t *fb)
{
    if (bike->pos.x < 20 && bike->velocity.x < 0) {
        bike->velocity.y = bike->velocity.x;
        bike->velocity.x = 0;
    } else if (bike->pos.x > fb->width - 20 && bike->velocity.x > 0) {
        bike->velocity.y = bike->velocity.x;
        bike->velocity.x = 0;
    }
    if (bike->pos.y < 20 && bike->velocity.y < 0) {
        bike->velocity.x = -bike->velocity.y;
        bike->velocity.y = 0;
    } else if (bike->pos.y > fb->height - 100 && bike->velocity.y > 0) {
        bike->velocity.x = -bike->velocity.y;
        bike->velocity.y = 0;
    }
}

static void check_crash(vehicule_t *bike, framebuffer_t *fb)
{
    unsigned int coord = ((bike->pos.y + 5) * fb->width * 4 + bike->pos.x * 4);

    if ((bike->velocity.x > 0 && fb->pixels[coord + 44] > 80) ||
    (!(bike->velocity.x > 0) && fb->pixels[coord] > 80)) {
        bike->pos.y = rand() % (fb->height - 20) + 10;
        bike->pos.x = 0;
        bike->velocity.x = 6;
        bike->velocity.y = 0;
        framebuffer_substract(fb, 180);
    }
}

void move_vehicule(vehicule_t *v, int nb, framebuffer_t *fb)
{
    for (int i = 0; i < nb; i++) {
        bounce(v + i, fb);
        v[i].pos.x += v[i].velocity.x;
        v[i].pos.y += v[i].velocity.y;
        check_crash(v + i, fb);
    }
}

void change_dir_vehicule(vehicule_t *v, int nb)
{
    int random;
    int temp;

    for (int i = 0; i < nb; i++) {
        random = rand() % 2;
        if (random == 1) {
            temp = v[i].velocity.x;
            v[i].velocity.x = -v[i].velocity.y;
            v[i].velocity.y = -temp;
        }
    }
}
