/*
** EPITECH PROJECT, 2019
** my_screensaver_2019
** File description:
** custom font
*/

#include "my_font.h"

const char alphabet[6][16] =
{
    { // D
        1, 0, 1, 0, 0, 0,
        1, 0, 0, 1, 0, 0,
        0, 0, 1, 2
    },
    { // E
        1, 1, 1, 1, 1, 1,
        1, 0, 0, 1, 0, 0,
        0, 0, 0, 0
    },
    { // H
        0, 1, 0, 0, 1, 0,
        1, 0, 1, 1, 0, 1,
        0, 0, 0, 0
    },
    { // N
        0, 0, 0, 0, 0, 0,
        1, 0, 1, 1, 0, 1,
        1, 0, 0, 1
    },
    { // T
        1, 0, 0, 1, 0, 0,
        0, 1, 0, 0, 1, 0,
        0, 0, 0, 0
    },
    {
        0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0,
        0, 0, 0, 0
    }
};

void display_alpha(framebuffer_t *fb, sfVector2i *position,
int alpha_code, sfColor *color)
{
    sfVector2i coord = {0, 0};
    int j = 12;

    for (int i = 0; i < 6; i++) {
        if (alphabet[alpha_code][i + 6] == 1)
            set_line_v(fb, position, &coord, color);
        if (alphabet[alpha_code][i] == 1)
            set_line_h(fb, position, &coord, color);
        if (coord.x != 2 && alphabet[alpha_code][j] == 1)
            set_diag_m(fb, position, &coord, color);
        if (coord.x != 2 && alphabet[alpha_code][j] == 2)
            set_diag_d(fb, position, &coord, color);
        coord.x++;
        if (coord.x == 3) {
            coord.x = 0;
            coord.y++;
        }
        if (coord.x != 2)
            j++;
    }
}

void display_str(framebuffer_t *fb, sfVector2i *position, char *str,
sfColor *c)
{
    int len = my_strlen(str);
    sfVector2i pos = *position;
    int alpha_code = 0;

    for (int i = 0; i < len; i++) {
        if (str[i] == 'd')
            alpha_code = 0;
        if (str[i] == 'e')
            alpha_code = 1;
        if (str[i] == 'h')
            alpha_code = 2;
        if (str[i] == 'n')
            alpha_code = 3;
        if (str[i] == 't')
            alpha_code = 4;
        if (str[i] == ' ')
            alpha_code = 5;
        display_alpha(fb, &pos, alpha_code, c);
        pos.x += space_x * 2 + 10;
    }
}
