/*
** EPITECH PROJECT, 2019
** my_sreensaver_2019
** File description:
** create window
*/

#include "my_screensaver.h"

window_t *create_window(int nb_fb)
{
    window_t *w = malloc(sizeof(window_t));
    sfVideoMode mode = {W_WIDTH, W_HEIGHT, 32};

    w->window = sfRenderWindow_create(mode, TITLE_W, sfClose/* | sfFullscreen*/
    | sfResize, NULL);
    sfRenderWindow_setFramerateLimit(w->window, FRAMERATE);
    w->nb_fb = nb_fb;
    w->width = W_WIDTH;
    w->height = W_HEIGHT;
    if (!w->window || create_framebuffer(w) == -1)
        return NULL;
    return w;
}

int create_framebuffer(window_t *w)
{
    framebuffer_t **fba[4] = {&w->fb, &w->fb2, &w->fb3, &w->fb4};

    for (int i = 0; i < w->nb_fb; i++) {
        *fba[i] = framebuffer_create(w->width, w->height);
        if (*fba[i] == NULL)
            return -1;
    }
    return 0;
}

void destroy_window(window_t *w)
{
    sfRenderWindow_destroy(w->window);
    destroy_framebuffer(w);
    free(w);
}

void destroy_framebuffer(window_t *w)
{
    if (w->nb_fb >= 1) {
        framebuffer_destroy(w->fb);
        w->fb = NULL;
    }
    if (w->nb_fb >= 2)
        framebuffer_destroy(w->fb2);
    if (w->nb_fb >= 3)
        framebuffer_destroy(w->fb3);
    if (w->nb_fb == 4)
        framebuffer_destroy(w->fb4);
}
