/*
** EPITECH PROJECT, 2019
** my_sreensaver_2019
** File description:
** generate a random map sub-functions
*/

#include "w01_ground_generator.h"

sfColor select_color(double altitude)
{
    sfColor water = {28, 163, 236, 255};
    sfColor sand = {200, 190, 40, 255};
    sfColor ground[2] = {{57, 118, 40, 255}, {36, 96, 36, 255}};
    sfColor mountain[2] = {{104, 91, 47, 255}, {90, 80, 40, 255}};
    sfColor snow = {255, 255, 255, 255};

    if (altitude <= 37)
        return water;
    if (altitude <= 40)
        return sand;
    if (altitude <= 58)
        return ground[0];
    if (altitude <= 62)
        return ground[1];
    if (altitude <= 66)
        return mountain[0];
    if (altitude <= 72)
        return mountain[1];
    return snow;
}

void map_to_framebuffer(framebuffer_t *fb, map_t *map)
{
    sfUint8 pix;
    sfColor c;
    int idx = 0;

    for (unsigned int y = 0; y < map->height; y++) {
        for (unsigned int x = 0; x < map->width; x++) {
            idx = y * map->width + x;
            pix = map->map[idx];
            c = select_color(pix);
            put_pixel(fb, x, y, &c);
        }
    }
}

void put_tree(framebuffer_t *fb, map_t *map)
{
    int size = fb->width * fb->height;
    sfVector2i pos;
    sfColor tree = {5, 60, 5, 255};

    for (int i = 0; i < size; i += 8) {
        if (rand() % 20 == 1 && map->map[i] > 43 && map->map[i] < 55) {
            pos.y = i / fb->width;
            pos.x = i - (pos.y * fb->width);
            draw_circle2(fb, &pos, 2, &tree);
        }
    }
}
