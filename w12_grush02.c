/*
** EPITECH PROJECT, 2019
** my_screensaver_2019
** File description:
** w12_grush02
*/

#include "w12_grush02.h"

static void display_ext(window_t *w, face_t *face)
{
    draw_face(w->fb, &face->face_size, &face->face_pos);
    draw_oval(w->fb, 80, &face->pos_eyes01);
    draw_oval(w->fb, 80, &face->pos_eyes02);
    face->pos_sur01.y = 200 - face->shift_eyes / 4;
    face->pos_sur02.y = 200 - face->shift_eyes / 4;
    draw_arc(w->fb, 90, 15, &face->pos_sur01);
    draw_arc(w->fb, 90, 15, &face->pos_sur02);
}

static void display(window_t *w, face_t *face)
{
    sfVector2i pos_alpha = {w->fb->width / 2 - 280, 900};
    sfVector2i anime_eye01_pos = {0, face->pos_eyes01.y};
    sfVector2i anime_eye02_pos = {0, face->pos_eyes02.y};

    if (sfClock_getElapsedTime(w->timer).microseconds > 10000) {
        sfClock_restart(w->timer);
        face->shift_eyes += face->shift_eyes_mode;
        if (face->shift_eyes >= 40 || face->shift_eyes <= -40)
            face->shift_eyes_mode *= -1;
    }
    anime_eye01_pos.x = w->fb->width / 2 + 200 + face->shift_eyes;
    anime_eye02_pos.x = w->fb->width / 2 - 200 + face->shift_eyes;
    face->shift_mooth += face->shift_mooth_mode;
    if (face->shift_mooth >= 4 || face->shift_mooth <= 1)
    face->shift_mooth_mode *= -1;
    display_ext(w, face);
    draw_circle2(w->fb, &anime_eye01_pos, 8, &face->white);
    draw_circle2(w->fb, &anime_eye02_pos, 8, &face->white);
    draw_smile(w->fb, 200, &face->mooth_pos, face->shift_mooth);
    display_str(w->fb, &pos_alpha, "the end", &face->white);
}

static void init_face(face_t *face, framebuffer_t *fb)
{
    face->shift_eyes = 0;
    face->shift_eyes_mode = 2;
    face->pos_eyes01 = (sfVector2i){fb->width / 2 + 200, 220};
    face->pos_eyes02 = (sfVector2i){fb->width / 2 - 200, 220};
    face->pos_sur01 =  (sfVector2u){fb->width / 2 - 200, 200};
    face->pos_sur02 = (sfVector2u){fb->width / 2 + 200, 200};
    face->shift_mooth = 1;
    face->shift_mooth_mode = 0.09;
    face->mooth_pos = (sfVector2u){fb->width / 2, 400};
    face->face_size = (sfVector2u){800, 500};
    face->face_pos = (sfVector2u){fb->width / 2 - 400, fb->height / 2 + 200};
    face->white = (sfColor){255, 255, 255, 255};
    face->black = (sfColor){0, 0, 0, 255};
}

int run12(program_t *prog)
{
    sfEvent event;
    window_t *w = create_window(1, prog);
    face_t face;

    init_face(&face, w->fb);
    if (!w)
        return 1;
    while (sfRenderWindow_isOpen(w->window)) {
        sfRenderWindow_clear(w->window, sfBlack);
        framebuffer_clear(w->fb);
        display(w, &face);
        display_framebuffer(w->fb, w->window);
        sfRenderWindow_display(w->window);
        while (sfRenderWindow_pollEvent(w->window, &event))
            event_manager(w, &event, prog);
    }
    destroy_window(w);
    return 0;
}
