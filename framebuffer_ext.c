/*
** EPITECH PROJECT, 2019
** my_sreensaver_2019
** File description:
** framebuffer second file
*/

#include "my_screensaver.h"

void framebuffer_clear(framebuffer_t *fb)
{
    int size = fb->width * fb->height * 4;

    for (int i = 0; i < size; i += 4) {
        fb->pixels[i] = 0;
        fb->pixels[i + 1] = 0;
        fb->pixels[i + 2] = 0;
        fb->pixels[i + 3] = 255;
    }
}

void framebuffer_substract(framebuffer_t *fb, int nb)
{
    int size = fb->width * fb->height * 4;
    sfUint32 color;

    for (int i = 0; i < size; i += 4) {
        if (fb->pixels[i] >= nb)
            fb->pixels[i] -= nb;
        if (fb->pixels[i + 1] >= nb)
            fb->pixels[i + 1] -= nb;
        if (fb->pixels[i + 2] >= nb)
            fb->pixels[i + 2] -= nb;
    }
}
