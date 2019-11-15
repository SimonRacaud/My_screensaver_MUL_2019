/*
** EPITECH PROJECT, 2019
** my_sreensaver_2019
** File description:
** create window
*/

#include "my_sreensaver.h"

window_t *create_window(void)
{
    window_t *w = malloc(sizeof(window_t));
    sfVideoMode mode = {FB_WIDTH, FB_HEIGHT, 32};

    w->window = sfRenderWindow_create(mode, TITLE_W, sfClose/* | sfFullscreen*/,
    NULL);
    sfRenderWindow_setFramerateLimit(w->window, FRAMERATE);
    w->fb = framebuffer_create(FB_WIDTH, FB_HEIGHT);
    w->fb2 = framebuffer_create(FB_WIDTH, FB_HEIGHT);
    w->fb3 = framebuffer_create(FB_WIDTH, FB_HEIGHT);
    if (!w->window)
        return NULL;
    return w;
}

void destroy_window(window_t *w)
{
    sfRenderWindow_destroy(w->window);
    framebuffer_destroy(w->fb);
}
