/*
** EPITECH PROJECT, 2019
** LIB_nbr_2019
** File description:
** LIB HEADER
*/

#ifndef MY_NBR_H_
#define MY_NBR_H_

#include "../my_str/my_str.h"

char *convert_base(char const *nbr, char const *base_from, char const *base_to);
int my_factorial_it(int nb);
int my_find_prime_sup(int nb);
int my_getnbr_base(char const *str, char const *base);
int my_getnbr(char const *str);
int my_isneg(int n);
int my_is_prime(int nb);
int my_power_rec(int nb, int p);
int my_putnbr_base(int nbr, char const *base);
char *my_putnbr_base_str(int nbr, char const *base);
int my_put_nbr(int nb);
void my_sort_int_array(int *array, int size);
int my_sqrt(int nb);
void my_swap(int *a, int *b);

#endif
