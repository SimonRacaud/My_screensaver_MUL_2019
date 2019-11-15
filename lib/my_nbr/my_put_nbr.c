/*
** EPITECH PROJECT, 2019
** CPool_Day03_2019
** File description:
** void
*/

#include "my_nbr.h"

int my_put_nbr(int nb)
{
    int i = 0;
    char c;
    long int lnb = nb;

    if (lnb < 0) {
        my_putchar('-');
        lnb = -lnb;
    }
    while (lnb / my_power_rec(10, i) >= 10) {
        i++;
    }
    while (i >= 0) {
        c = ((lnb / my_power_rec(10, i)) % 10) + '0';
        my_putchar(c);
        i--;
    }
    return (0);
}
