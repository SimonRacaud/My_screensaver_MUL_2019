/*
** EPITECH PROJECT, 2019
** my_screensaver_2019
** File description:
** animated sort
*/

#include "w07_animated_sort.h"

static void display(window_t *w, qsort_t *qs)
{
    unsigned int lwidth = (w->fb->width / (qs->size + 2)) - 1;
    sfColor *c;
    sfColor white = {255, 255, 255, 255};
    sfColor red = {255, 0, 0, 255};
    sfColor blue = {0, 0, 255, 255};
    sfVector2u pos_rect = {lwidth, 20};
    sfVector2u size = {lwidth, 0};

    sfRenderWindow_clear(w->window, sfBlack);
    framebuffer_clear(w->fb);
    for (int i = 0; i < qs->size; i++) {
        if (i == qs->idx_begin || i == qs->idx_end)
            c = &blue;
        else if (i == qs->cur_right || i == qs->cur_left)
            c = &red;
        else
            c = &white;
        size.y = (qs->array[i] % qs->size) * (w->fb->height / (qs->size + 2));
        draw_rect(w->fb, &pos_rect, &size, c);
        pos_rect.x += size.x + 1;
    }
    display_framebuffer(w->fb, w->window);
    sfRenderWindow_display(w->window);
    //while (sfClock_getElapsedTime(w->timer).microseconds < 1000);
    //sfClock_restart(w->timer);
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

void quick_sort_disp(qsort_t *qs, int idx_begin, int idx_end, window_t *w)
{
    qs->pivot = qs->array[idx_begin];
    qs->cur_left = idx_begin - 1;
    qs->cur_right = idx_end + 1;
    qs->idx_pivot = idx_begin;
    qs->idx_begin = idx_begin;
    qs->idx_end = idx_end;

    if (qs->idx_begin - 1 == qs->idx_end)
        return;
    while (1) {
        do {
            qs->cur_left++;
        } while (qs->array[qs->cur_left] < qs->pivot);
        do {
            qs->cur_right--;
        } while (qs->array[qs->cur_right] > qs->pivot);
        if (qs->cur_left >= qs->cur_right)
            break;
        swap(&qs->array[qs->cur_left], &qs->array[qs->cur_right]);
        display(w, qs);
    }
    quick_sort_disp(qs, qs->idx_begin, qs->cur_right - 1, w);
    quick_sort_disp(qs, qs->cur_right + 1, qs->idx_end, w);
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
    int size_array = 200;
    int array[200];
    qsort_t qsort;

    init_qsort(&qsort, size_array, array);
    generate_mixed_array(array, size_array);
    if (!w)
        return 1;
    while (sfRenderWindow_isOpen(w->window)) {
        while (sfRenderWindow_pollEvent(w->window, &event))
            event_manager(w, &event, prog);
        quick_sort_disp(&qsort, 0, (size_array - 1), w);
    }
    destroy_window(w);
    return 0;
}
