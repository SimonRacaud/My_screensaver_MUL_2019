/*
** EPITECH PROJECT, 2019
** my_sreensaver_2019
** File description:
** main
*/

#include "my.h"
#include "my_screensaver.h"

const int (*animations[MAX_ID])(void) =
{
    &run01,
    &run02,
    &run03
};

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
        if (id < 1 || id >= MAX_ID) {
            usage();
        }
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
        if (w->height != e->size.height || w->width != e->size.width) {
            w->height = e->size.height;
            w->width = e->size.width;
        }
    }
}

int run(int id)
{
    int ret = 0;

    srand(time(NULL));
    ret = animations[id - 1]();
    if (ret == 1)
        run(id);
    return 0;
}
