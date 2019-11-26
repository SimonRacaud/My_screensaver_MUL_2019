/*
** EPITECH PROJECT, 2019
** my_screensaver_2019
** File description:
** Tron race
*/

#include "w08_tron_race.h"

static vehicule_t *create_vehicule(unsigned int nbr, framebuffer_t *fb)
{
    vehicule_t *v = malloc(sizeof(vehicule_t) * nbr);
    int random;

    if (v == NULL)
        return NULL;
    for (unsigned int i = 0; i < nbr; i++) {
        random = rand() % (fb->height - 40) + 20;
        v[i].pos.x = 0;
        v[i].pos.y = random;
        v[i].c = (sfColor){255, 255, 255, 255};
        v[i].velocity.x = 6;
        v[i].velocity.y = 0;
    }
    return v;
}

static void display(window_t *w, vehicule_t *bike, int nb_bike)
{
    if (sfClock_getElapsedTime(w->timer).microseconds > 300000) {
        sfClock_restart(w->timer);
        change_dir_vehicule(bike, nb_bike);
    }
    framebuffer_substract(w->fb, 1);
    for (int i = 0; i < nb_bike; i++)
        draw_square(w->fb, &bike[i].pos, 10, &bike[i].c);
    display_framebuffer(w->fb, w->window);
    move_vehicule(bike, nb_bike, w->fb);
    sfRenderWindow_display(w->window);
}

int run08(program_t *prog)
{
    sfEvent event;
    window_t *w = create_window(1, prog);
    unsigned int nb_bike = 2;
    vehicule_t *bike = create_vehicule(nb_bike, w->fb);

    if (!w)
        return 1;
    while (sfRenderWindow_isOpen(w->window)) {
        display(w, bike, nb_bike);
        while (sfRenderWindow_pollEvent(w->window, &event))
            event_manager(w, &event, prog);
    }
    destroy_window(w);
    free(bike);
    return 0;
}
