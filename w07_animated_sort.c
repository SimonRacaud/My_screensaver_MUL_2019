/*
** EPITECH PROJECT, 2019
** my_screensaver_2019
** File description:
** animated sort
*/

#include "w07_animated_sort.h"

void display(window_t *w, qsort_t *qs)
{
    unsigned int lwidth = (w->fb->width / (qs->size + 2)) - 1;
    sfColor *c;
    sfColor white = {255, 255, 255, 255};
    sfColor red = {255, 0, 0, 255};
    sfVector2u pos_rect = {lwidth, 20};
    sfVector2u size = {lwidth, 0};

    framebuffer_clear(w->fb);
    for (int i = 0; i < qs->size; i++) {
        if (i == qs->idx_begin || i == qs->idx_end)
            c = &red;
        else
            c = &white;
        size.y = (qs->array[i] % qs->size) * (w->fb->height / (qs->size + 2));
        draw_rect(w->fb, &pos_rect, &size, c);
        pos_rect.x += size.x + 1;
    }
    display_framebuffer(w->fb, w->window);
    sfRenderWindow_display(w->window);
}

static void generate_mixed_array(int *array, int size)
{
    int temp;
    int rand_idx;

    for (int i = 0; i < size; i++)
        array[i] = i;
    for (int i = 0; i < size; i++) {
        rand_idx = rand() % size;
        temp = array[i];
        array[i] = array[rand_idx];
        array[rand_idx] = temp;
    }
}

static void init_qsort(qsort_t *qsort, int size, int *array)
{
    qsort->array = array;
    qsort->idx_pivot = 0;
    qsort->size = size;
}

int run07(program_t *prog)
{
    sfEvent event;
    window_t *w = create_window(1, prog);
    int size_array = 50;
    int array[50];
    qsort_t qsort;
    int first = 1;

    init_qsort(&qsort, size_array, array);
    generate_mixed_array(array, size_array);
    if (!w)
        return 1;
    while (sfRenderWindow_isOpen(w->window)) {
        while (sfRenderWindow_pollEvent(w->window, &event))
            event_manager(w, &event, prog);
        if (first--)
            quick_sort_disp(&qsort, 0, (size_array - 1), w);
    }
    destroy_window(w);
    return 0;
}
