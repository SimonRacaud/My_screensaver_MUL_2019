/*
** EPITECH PROJECT, 2019
** my_screensaver_2019
** File description:
** Stick man
*/

#include "w09_text.h"
#include "my.h"

static void display(window_t *w, char *text, sfColor *color)
{
    static sfVector2i pos = {10, 10};
    static int idx_str = 0;
    sfInt64 time = sfClock_getElapsedTime(w->timer).microseconds;
    char txt_cpy[115];

    my_strcpy(txt_cpy, text);
    if (idx_str < 115 && time > 50000) {
        sfClock_restart(w->timer);
        idx_str++;
    }
    if (idx_str == 115 && time > 2000000)
        idx_str = 0;
    txt_cpy[idx_str] = '\0';
    display_str(w->fb, &pos, txt_cpy, color);
    display_framebuffer(w->fb, w->window);
    sfRenderWindow_display(w->window);
}

int run09(program_t *prog)
{
    sfEvent event;
    window_t *w = create_window(1, prog);
    char text[115] = "abcdefghijklmnopqrstuvwxyz\n\n";
    sfColor white = {255, 255, 255, 255};

    my_strcat(text, "les sanglots longs\ndes violons\nde l'automne\n");
    my_strcat(text, "blessent mon coeur\nd'une langueur\nmonotone");
    if (!w)
        return 1;
    while (sfRenderWindow_isOpen(w->window)) {
        framebuffer_clear(w->fb);
        display(w, text, &white);
        while (sfRenderWindow_pollEvent(w->window, &event))
            event_manager(w, &event, prog);
    }
    destroy_window(w);
    return 0;
}
