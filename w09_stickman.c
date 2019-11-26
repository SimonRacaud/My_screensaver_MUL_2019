/*
** EPITECH PROJECT, 2019
** my_screensaver_2019
** File description:
** Stick man
*/

#include "w09_stickman.h"

void draw_sinu(limb_t *limb, framebuffer_t *fb)
{
    sfVector2u coo = limb->pos;

    while (coo.x < limb->pos.x + limb->len) {
        coo.y = sin(limb->shift + (double)coo.x / limb->coef.x) * limb->coef.y;
        coo.y += limb->pos.y;
        for (unsigned int i = 0; i < limb->border; i++) {
            put_pixel(fb, coo.x, coo.y + i, &limb->color);
        }
        coo.x++;
    }
}

static void display(window_t *w, limb_t *arml, limb_t *armr)
{
    sfVector2i pos_head = {w->fb->width / 2, w->fb->height / 3};
    sfVector2u pos_body = {w->fb->width / 2 - 40, w->fb->height / 3 + 80};
    sfVector2u size_body = {80, 250};
    sfColor c_head = {255, 255, 255, 255};

    if (sfClock_getElapsedTime(w->timer).microseconds > 30000) {
        sfClock_restart(w->timer);
        arml->shift++;
        if (arml->shift == (int)arml->len)
            arml->shift = 0;
        armr->shift--;
        if (armr->shift == (int)armr->len)
            armr->shift = 0;
    }
    framebuffer_clear(w->fb);
    draw_circle2(w->fb, &pos_head, 50, &c_head);
    draw_rect(w->fb, &pos_body, &size_body, &c_head);
    draw_sinu(arml, w->fb);
    draw_sinu(armr, w->fb);
    display_framebuffer(w->fb, w->window);
    sfRenderWindow_display(w->window);
}

void init_limb(limb_t *limb, int nb)
{
    limb->len = 400;
    limb->shift = 0;
    limb->border = 4;
    if (nb == 1)
        limb->pos.x = 515;
    else
        limb->pos.x = 1005;
    limb->pos.y = 500;
    limb->coef.x = 30;
    limb->coef.y = 30;
    limb->color = (sfColor){255, 255, 255, 255};
}

int run09(program_t *prog)
{
    sfEvent event;
    window_t *w = create_window(1, prog);
    limb_t arml;
    limb_t armr;

    init_limb(&arml, 1);
    init_limb(&armr, 2);
    if (!w)
        return 1;
    while (sfRenderWindow_isOpen(w->window)) {
        display(w, &arml, &armr);
        while (sfRenderWindow_pollEvent(w->window, &event))
            event_manager(w, &event, prog);
    }
    destroy_window(w);
    return 0;
}
