/*
** EPITECH PROJECT, 2019
** my_screensaver_2019
** File description:
** header
*/

#ifndef H_W07
#define H_W07

#include "my_screensaver.h"

typedef struct qsort {
    int *array;
    int pivot;
    int idx_begin;
    int idx_end;
    int size;
} qsort_t;

void quick_sort_disp(qsort_t *qs, int idx_begin, int idx_end, window_t *w);
void display(window_t *w, qsort_t *qs, int idx_begin, int idx_end);

#endif
