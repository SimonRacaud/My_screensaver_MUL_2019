/*
** EPITECH PROJECT, 2019
** my_sreensaver_2019
** File description:
** main
*/

#include "my.h"
#include "my_sreensaver.h"

static void event_manager(window_t *w, sfEvent *e)
{
    if (e->type == sfEvtClosed)
        sfRenderWindow_close(w->window);
    else if (e->type == sfEvtKeyPressed) {
        if (e->key.code == sfKeyLeft) {
            sfRenderWindow_close(w->window);
        } else if (e->key.code == sfKeyRight) {
            sfRenderWindow_close(w->window);
        }
    }
}

int main(int ac, char **av)
{
    int id = 0;

    if (ac != 2) {
        my_putstr_error(ERR_PARA);
        return 84;
    }
    if (my_strcmp(av[1], "-h") == 0) {
        usage();
    } else if (my_strcmp(av[1], "-d") == 0) {
        description();
    } else {
        id = check_get_id(av[1]);
        if (id == -1)
            return 84;
        if (!run(id))
            return 84;
    }
    return 0;
}

int run(int id)
{
    sfEvent event;
    window_t *w = create_window();
    srand(time(NULL));

    framebuffer_perlin_noise(w->fb);
    if (!w)
        return 1;
    while (sfRenderWindow_isOpen(w->window)) {
        while (sfRenderWindow_pollEvent(w->window, &event))
            event_manager(w, &event);
        sfRenderWindow_clear(w->window, sfBlack);

        display_framebuffer(w->fb, w->window);

        sfRenderWindow_display(w->window);
    }
    destroy_window(w);
    run2(id);
    return 0;
}
