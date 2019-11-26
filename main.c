/*
** EPITECH PROJECT, 2019
** my_sreensaver_2019
** File description:
** main
*/

#include "my.h"
#include "my_screensaver.h"

const int (*animations[MAX_ID])(program_t *prog) =
{
    &run01,
    &run02,
    &run03,
    &run04,
    &run05,
    &run06,
    &run07,
    &run08,
    &run09,
    &run10,
    &run11
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
        if (id < 1 || id > MAX_ID) {
            usage();
        } else if (!run(id))
            return 84;
    }
    return 0;
}

int event_manager(window_t *w, sfEvent *e, program_t *prog)
{
    if (e->type == sfEvtClosed || e->key.code == sfKeyEscape) {
        prog->id = 0;
        sfRenderWindow_close(w->window);
    } else if (e->type == sfEvtKeyPressed) {
        if (e->key.code == sfKeyLeft) {
            prog->id--;
            sfRenderWindow_close(w->window);
        } else if (e->key.code == sfKeyRight) {
            prog->id++;
            sfRenderWindow_close(w->window);
        }
        if (e->key.code == sfKeyUp)
            sfRenderWindow_close(w->window);
    }
    if (e->type == sfEvtResized) {
        prog->height = e->size.height;
        prog->width = e->size.width;
    }
    return 0;
}

int run(int id)
{
    program_t prog = {id, W_HEIGHT, W_WIDTH};
    int ret = 0;

    srand(time(NULL));
    do {
        ret = animations[prog.id - 1](&prog);
    } while (prog.id > 0 && prog.id <= MAX_ID);
    return ret;
}
