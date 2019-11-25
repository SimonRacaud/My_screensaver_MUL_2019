/*
** EPITECH PROJECT, 2019
** my_screensaver_2019
** File description:
** Tron race
*/

#include "w08_tron_race.h"

void display(window_t *w, vehicule_t *bike)
{
    framebuffer_clear(w->fb);

    display_framebuffer(w->fb, w->window);
    sfRenderWindow_display(w->window);
}

vehicule_t *create_vehicule(unsigned int nbr, framebuffer_t *fb)
{
    vehicule_t *v = malloc(sizeof(vehicule_t) * nbr);
    int random;

    if (v == NULL)
        return NULL;
    for (unsigned int i = 0; i < nbr; i++) {
        random = rand() % fb->height;
        v[i].pos.x = 0;
        v[i].pos.y = random;
        v[i].c = sfColor_fromRGB(random % 255, random % 255, random % 255);
        v[i].velocity.x = 2;
        v[i].velocity.y = 0;
    }
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
        display(w, bike);
        while (sfRenderWindow_pollEvent(w->window, &event))
            event_manager(w, &event, prog);
    }
    destroy_window(w);
    free(bike);
    return 0;
}
