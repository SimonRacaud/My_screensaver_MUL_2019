/*
** EPITECH PROJECT, 2019
** my_sreensaver_2019
** File description:
** main
*/

#include "my.h"
#include "my_screensaver.h"

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

void event_manager(window_t *w, sfEvent *e)
{
    if (e->type == sfEvtClosed) {
        sfRenderWindow_close(w->window);
    } else if (e->type == sfEvtKeyPressed) {
        if (e->key.code == sfKeyLeft) {
            sfRenderWindow_close(w->window);
        } else if (e->key.code == sfKeyRight) {
            sfRenderWindow_close(w->window);
        }
    }
    if (e->type == sfEvtResized) {
        w->height = e->size.height;
        w->width = e->size.width;
        destroy_framebuffer(w);
        create_framebuffer(w);
    }
}

int run(int id)
{
    srand(time(NULL));

    if (id == 1)
        run01();
    else if (id == 2)
        run02();
    else if (id == 3)
        run03();
    return 0;
}
