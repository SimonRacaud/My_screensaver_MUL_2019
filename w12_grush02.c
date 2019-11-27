/*
** EPITECH PROJECT, 2019
** my_screensaver_2019
** File description:
** w11_grush01
*/

#include "w12_grush02.h"

void draw_face(framebuffer_t *fb, sfVector2u *size, sfVector2u *pos)
{
    sfColor color = {255, 255, 255, 255};
    unsigned int y;
    unsigned int val = -10;

    for (unsigned int x = pos->x; x < pos->x + size->x; x++) {
        y = pos->y + -(val * val);
        //for (unsigned int i = pos->y; i < y; i++) {
            put_pixel(fb, x, y , &color);
        //}
    }
}

void draw_arc(framebuffer_t *fb, unsigned int width, unsigned int border,
sfVector2u *pos)
{
    sfColor color = {255, 255, 255, 255};
    unsigned int x;
    unsigned int y;

    for (double t = 0; t >= -3.1416; t -= 0.01) {
        x = pos->x + width * cos(t);
        y = pos->y + width * sin(t) * 0.5;
        for (unsigned int i = 0; i < border; i++) {
            put_pixel(fb, x, y + i, &color);
        }
    }
}

void draw_smile(framebuffer_t *fb, unsigned int width, sfVector2u *pos,
double div)
{
    sfColor color = {255, 255, 255, 255};
    unsigned int x;
    unsigned int y;

    for (double t = 0; t >= -3.1416; t -= 0.001) {
        x = pos->x + width * cos(t);
        y = pos->y - width * sin(t) * 0.5;
        for (unsigned int i = 0; i < (y - pos->y) / div; i++) {
            put_pixel(fb, x, y + i, &color);
        }
    }
}
/*
void draw_oval(framebuffer_t *fb, unsigned int width, sfVector2u *pos)
{
    sfColor color = {255, 255, 255, 255};
    unsigned int x;
    unsigned int y;

    for (double t = 0; t >= -3.1416; t -= 0.01) {
        x = pos->x + width * cos(t);
        y = pos->y + width * sin(t) * 0.5;
        for (unsigned int i = 0; i < pos->y - y; i++) {
            put_pixel(fb, x, y + i, &color);
        }
    }
}*/

static int display(window_t *w, int *shift_eyes, int *shift_eyes_mode)
{
    sfVector2i pos_eyes01 = {w->fb->width / 2 + 200, 220};
    sfVector2i pos_eyes02 = {w->fb->width / 2 - 200, 220};
    sfVector2u pos_sur01 = {w->fb->width / 2 - 200, 200};
    sfVector2u pos_sur02 = {w->fb->width / 2 + 200, 200};
    sfColor white = {255, 255, 255, 255};

    if (sfClock_getElapsedTime(w->timer).microseconds > 10000) {
        sfClock_restart(w->timer);
        (*shift_eyes) += *shift_eyes_mode;
        if ((*shift_eyes) >= 50 || (*shift_eyes) <= -50)
            *shift_eyes_mode *= -1;
    }
    pos_eyes01.x += *shift_eyes;
    pos_eyes02.x += *shift_eyes;
    draw_circle2(w->fb, &pos_eyes01, 10, &white);
    draw_circle2(w->fb, &pos_eyes02, 10, &white);
    pos_sur01.y -= *shift_eyes / 2 + 10;
    pos_sur02.y -= *shift_eyes / 2 + 10;
    draw_arc(w->fb, 100, 20, &pos_sur01);
    draw_arc(w->fb, 100, 20, &pos_sur02);
}

int run12(program_t *prog)
{
    sfEvent event;
    window_t *w = create_window(1, prog);
    int shift_eyes = 0;
    int shift_eyes_mode = 2;
    double shift_mooth = 1;
    double shift_mooth_mode = 0.1;
    //sfVector2u face_size = {200, 600};
    //sfVector2u face_pos = {100, 900};
    sfVector2u smile_pos = {w->fb->width / 2, 400};

    //draw_face(w->fb, &face_size, &face_pos);
    if (!w)
        return 1;
    while (sfRenderWindow_isOpen(w->window)) {
        sfRenderWindow_clear(w->window, sfBlack);
        display_framebuffer(w->fb, w->window);
        sfRenderWindow_display(w->window);
        framebuffer_clear(w->fb);
        display(w, &shift_eyes, &shift_eyes_mode);
        draw_smile(w->fb, 200, &smile_pos, shift_mooth);
        shift_mooth += shift_mooth_mode;
        if (shift_mooth >= 4 || shift_mooth <= 1)
            shift_mooth_mode *= -1;
        while (sfRenderWindow_pollEvent(w->window, &event))
            event_manager(w, &event, prog);
    }
    destroy_window(w);
    return 0;
}
