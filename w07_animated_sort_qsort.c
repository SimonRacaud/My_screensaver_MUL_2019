/*
** EPITECH PROJECT, 2019
** my_screensaver_2019
** File description:
** animated sort
*/

#include "w07_animated_sort.h"

static void swap(int *a, int *b)
{
    int t = *a;

    *a = *b;
    *b = t;
}

void quick_sort_disp(qsort_t *qs, int idx_begin, int idx_end, window_t *w)
{
    int pivot = qs->array[idx_begin];
    int cur_left = idx_begin - 1;
    int cur_right = idx_end + 1;

    if (idx_begin >= idx_end)
        return;
    while (1) {
        do {
            cur_left++;
        } while (qs->array[cur_left] < pivot);
        do {
            cur_right--;
        } while (qs->array[cur_right] > pivot);
        if (cur_left >= cur_right)
            break;
        swap(&qs->array[cur_left], &qs->array[cur_right]);
        display(w, qs, idx_begin, idx_end);
    }
    quick_sort_disp(qs, idx_begin, cur_right, w);
    quick_sort_disp(qs, cur_right + 1, idx_end, w);
}
