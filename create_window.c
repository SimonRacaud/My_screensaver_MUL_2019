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
    sfVideoMode mode = {FB_WIDTH, FB_HEIGHT, 32};

    w->window = sfRenderWindow_create(mode, TITLE_W, sfClose/* | sfFullscreen*/,
    NULL);
    sfRenderWindow_setFramerateLimit(w->window, FRAMERATE);
    w->nb_fb = nb_fb;
    if (nb_fb == 1) {
        w->fb = framebuffer_create(FB_WIDTH, FB_HEIGHT);
        if (w->fb == NULL)
            return NULL;
    } else if (nb_fb == 2) {
        w->fb2 = framebuffer_create(FB_WIDTH, FB_HEIGHT);
    }
    if (nb_fb == 3) {
        w->fb3 = framebuffer_create(FB_WIDTH, FB_HEIGHT);
    } else if (nb_fb == 4) {
        w->fb4 = framebuffer_create(FB_WIDTH, FB_HEIGHT);
    }
    if (!w->window)
        return NULL;
    return w;
}

void destroy_window(window_t *w)
{
    sfRenderWindow_destroy(w->window);
    if (w->nb_fb == 1)
        framebuffer_destroy(w->fb);
    else if (w->nb_fb == 2)
        framebuffer_destroy(w->fb2);
    else {
        if (w->nb_fb == 3)
            framebuffer_destroy(w->fb3);
        else
            framebuffer_destroy(w->fb4);
    }
}
