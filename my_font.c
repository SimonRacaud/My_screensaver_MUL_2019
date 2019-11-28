/*
** EPITECH PROJECT, 2019
** my_screensaver_2019
** File description:
** custom font
*/

#include "my_font.h"

const char alphabet[MAX_CHAR][16] =
{
    {
        1, 1, 0, 1, 1, 0,
        1, 0, 1, 1, 0, 1,
        0, 0, 0, 0
    },
    {
        1, 1, 1, 0, 1, 0,
        1, 0, 0, 1, 0, 0,
        0, 0, 1, 2
    },
    {
        1, 0, 1, 1, 0, 1,
        1, 0, 0, 1, 0, 0,
        0, 0, 0, 0
    },
    {
        1, 0, 1, 0, 0, 0,
        1, 0, 0, 1, 0, 0,
        0, 0, 1, 2
    },
    {
        1, 1, 1, 1, 1, 1,
        1, 0, 0, 1, 0, 0,
        0, 0, 0, 0
    },
    {
        1, 1, 0, 1, 1, 0,
        1, 0, 0, 1, 0, 0,
        0, 0, 0, 0
    },
    {
        1, 0, 1, 1, 1, 1,
        1, 0, 0, 1, 0, 1,
        0, 0, 0, 0
    },
    {
        0, 1, 0, 0, 1, 0,
        1, 0, 1, 1, 0, 1,
        0, 0, 0, 0
    },
    {
        0, 0, 0, 0, 0, 0,
        0, 1, 0, 0, 1, 0,
        0, 0, 0, 0
    },
    {
        1, 0, 1, 1, 0, 0,
        0, 1, 0, 1, 1, 0,
        0, 0, 0, 0
    },
    {
        0, 0, 0, 0, 0, 0,
        1, 0, 0, 1, 0, 0,
        2, 1, 0, 0
    },
    {
        0, 0, 1, 0, 0, 1,
        1, 0, 0, 1, 0, 0,
        0, 0, 0, 0
    },
    {
        0, 0, 0, 0, 0, 0,
        1, 0, 1, 1, 0, 1,
        1, 0, 2, 0
    },
    {
        0, 0, 0, 0, 0, 0,
        1, 0, 1, 1, 0, 1,
        1, 0, 0, 1
    },
    {
        1, 0, 1, 1, 0, 1,
        1, 0, 1, 1, 0, 1,
        0, 0, 0, 0
    },
    {
        1, 1, 0, 1, 1, 0,
        1, 0, 1, 1, 0, 0,
        0, 0, 0, 0
    },
    {
        1, 0, 1, 1, 0, 1,
        1, 0, 1, 1, 0, 1,
        0, 0, 0, 1
    },
    {
        1, 1, 0, 1, 1, 0,
        1, 0, 1, 1, 0, 0,
        0, 0, 0, 1
    },
    {
        1, 1, 1, 1, 1, 1,
        1, 0, 0, 0, 0, 1,
        0, 0, 0, 0
    },
    {
        1, 0, 0, 1, 0, 0,
        0, 1, 0, 0, 1, 0,
        0, 0, 0, 0
    },
    {
        0, 0, 1, 0, 0, 1,
        1, 0, 1, 1, 0, 1,
        0, 0, 0, 0
    },
    {
        0, 0, 0, 0, 0, 0,
        1, 0, 1, 0, 0, 0,
        0, 1, 0, 2
    },
    {
        0, 0, 0, 0, 0, 0,
        1, 0, 1, 1, 0, 1,
        0, 2, 0, 1
    },
    {
        0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0,
        1, 2, 2, 1
    },
    {
        0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 1, 0,
        1, 0, 2, 0
    },
    {
        1, 0, 1, 1, 0, 1,
        0, 0, 0, 0, 0, 0,
        0, 2, 2, 0
    },
    {
        0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0,
        2, 0, 0, 0
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

static int get_alpha_code(char c)
{
    if (c == '\'')
        return (MAX_CHAR - 2);
    if (c == ' ')
        return (MAX_CHAR - 1);
    if (c >= 'a' && c <= 'z')
        return c - 'a';
    if (c >= 'A' && c <= 'Z')
        return c - 'A';
    return 24;
}

void display_str(framebuffer_t *fb, sfVector2i *position, char *str,
sfColor *c)
{
    int len = my_strlen(str);
    sfVector2i pos = *position;
    int alpha_code;

    for (int i = 0; i < len; i++) {
        alpha_code = get_alpha_code(str[i]);
        if (alpha_code >= MAX_CHAR) {
            continue;
        } else if (str[i] == '\n') {
            pos.y += space_y * 2 + 40;
            pos.x = position->x;
            continue;
        }
        display_alpha(fb, &pos, alpha_code, c);
        pos.x += space_x * 2 + 10;
    }
}
