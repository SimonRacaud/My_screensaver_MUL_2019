/*
** EPITECH PROJECT, 2019
** my_screensaver_2019
** File description:
** header
*/

#ifndef H_W12
#define H_W12

#include "my_screensaver.h"

typedef struct face {
    int shift_eyes;
    int shift_eyes_mode;
    sfVector2i pos_eyes01;
    sfVector2i pos_eyes02;
    sfVector2i pos_beyes01;
    sfVector2i pos_beyes02;
    sfVector2u pos_sur01;
    sfVector2u pos_sur02;
    double shift_mooth;
    double shift_mooth_mode;
    sfVector2u mooth_pos;
    sfVector2u face_size;
    sfVector2u face_pos;
    sfColor white;
    sfColor black;
} face_t;

void draw_face(framebuffer_t *fb, sfVector2u *size, sfVector2u *pos);
void draw_arc(framebuffer_t *fb, unsigned int width, unsigned int border,
sfVector2u *pos);
void draw_smile(framebuffer_t *fb, unsigned int width, sfVector2u *pos,
double div);
void draw_oval(framebuffer_t *fb, unsigned int width, sfVector2i *pos);

#endif
