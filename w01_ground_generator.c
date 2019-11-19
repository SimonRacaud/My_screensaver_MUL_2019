/*
** EPITECH PROJECT, 2019
** my_sreensaver_2019
** File description:
** generate a random map with perlin noise
*/

#include "w01_ground_generator.h"

static void generate_map(map_t *map, framebuffer_t *fb)
{
    unsigned int permu_table[512];
    unsigned int size = map->width * map->height;
    double ret;
    sfVector2i coord;

    map->map = malloc(sizeof(double) * size);
    for (unsigned int i = 0; i <= 255; i++)
        permu_table[i] = i;
    mix_permutation_table(permu_table);
    for (unsigned int c = 0; c < size; c++) {
        coord.y = c / map->width;
        coord.x = c - (coord.y * map->width);
        ret = perlin(coord.x, coord.y, 250, permu_table) * 0.85;
        ret += perlin(coord.x, coord.y, 50, permu_table) * 0.10;
        ret += perlin(coord.x, coord.y, 8, permu_table) * 0.05;
        ret = (ret + 1) / 2 * map->altitude;
        map->map[c] = ret;
    }
    map_to_framebuffer(fb, map);
    put_tree(fb, map);
}

static void display(map_t *map, window_t *w, sfClock *timer)
{
    if (sfClock_getElapsedTime(timer).microseconds > 2000000) {
        sfClock_restart(timer);
        free(map->map);
        generate_map(map, w->fb);
    }
    sfRenderWindow_clear(w->window, sfBlack);
    display_framebuffer(w->fb, w->window);
    sfRenderWindow_display(w->window);
}

int run01(void)
{
    sfEvent event;
    window_t *w = create_window(1);
    map_t map = {0, W_HEIGHT, W_WIDTH, 100};
    sfClock *timer = sfClock_create();

    generate_map(&map, w->fb);
    if (!w)
        return 1;
    while (sfRenderWindow_isOpen(w->window)) {
        display(&map, w, timer);
        while (sfRenderWindow_pollEvent(w->window, &event))
            event_manager(w, &event);
    }
    destroy_window(w);
    sfClock_destroy(timer);
    free(map.map);
    return 0;
}
