/*
** EPITECH PROJECT, 2019
** my_screensaver_2019
** File description:
** animated sort
*/

#include "w07_animated_sort.h"

static void display(window_t *w, int *array, qsort_t *qs)
{
    unsigned int width = w->fb->width / (qs->size * 2);
    sfColor c = {255, 255, 255, 255};
    sfVector2u pos_rect = {20, 20};
    sfVector2u size = {width, 0};
    int space_x = w->fb->width / (qs->size * 2);

    sfRenderWindow_clear(w->window, sfBlack);
    framebuffer_clear(w->fb);
    for (int i = 0; i < qs->size; i++) {
        size.y = ((array[i] + 1) % qs->size) * (w->fb->height / qs->size - 2);
        draw_rect(w->fb, &pos_rect, &size, &c);
        pos_rect.x += size.x + space_x;
    }
    display_framebuffer(w->fb, w->window);
    sfRenderWindow_display(w->window);
    while (sfClock_getElapsedTime(w->timer).microseconds < 100000);
    sfClock_restart(w->timer);
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

static void swap(int *a, int *b)
{
    int t = *a;

    *a = *b;
    *b = t;
}

int *quick_sort_disp(int *array, int *idx, const int size, window_t *w)
{
    qsort_t qsort = {array[idx[0]], idx[0], (idx[0] - 1), (idx[1] + 1), size};

    if (idx[0] - 1 == idx[1])
        return;
    while (1) {
        do {
            qsort.cur_left++;
        } while (array[qsort.cur_left] < qsort.pivot);
        do {
            qsort.cur_right--;
        } while (array[qsort.cur_right] > qsort.pivot);
        if (qsort.cur_left >= qsort.cur_right)
            break;
        swap(&array[qsort.cur_left], &array[qsort.cur_right]);
        display(w, array, &qsort);
    }
    //quick_sort_disp(array, idx[0], qsort.cur_right - 1, size, w);
    //quick_sort_disp(array, qsort.cur_right + 1, idx[1], size, w);
}

int run07(program_t *prog)
{
    sfEvent event;
    window_t *w = create_window(1, prog);
    int array[42];
    int idx[2] = {0, 41};

    generate_mixed_array(array, 42);
    if (!w)
        return 1;
    while (sfRenderWindow_isOpen(w->window)) {
        while (sfRenderWindow_pollEvent(w->window, &event))
            event_manager(w, &event, prog);
        quick_sort_disp(array, idx, 42, w);
    }
    destroy_window(w);
    return 0;
}
