/*
** EPITECH PROJECT, 2019
** my_screensaver_2019
** File description:
** animated sort
*/

#include "my_screensaver.h"

static void display(window_t *w)
{

    framebuffer_clear(w->fb);
}

int run07(program_t *prog)
{
    sfEvent event;
    window_t *w = create_window(1, prog);

    if (!w)
        return 1;
    while (sfRenderWindow_isOpen(w->window)) {
        sfRenderWindow_clear(w->window, sfBlack);
        display_framebuffer(w->fb, w->window);
        sfRenderWindow_display(w->window);
        display(w);
        while (sfRenderWindow_pollEvent(w->window, &event))
            event_manager(w, &event, prog);
    }
    destroy_window(w);
    return 0;
}
