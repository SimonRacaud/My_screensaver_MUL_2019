/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** Task18
*/

#include <unistd.h>

static void base_conv(int nb, int base, char const *basestr)
{
    int res[100];
    int i = 0;

    while (nb != 0) {
        res[i++] = (nb % base);
        nb /= base;
    }
    for (int j = (i - 1); j >= 0; j--) {
        write(1, &basestr[res[j]], 1);
    }
}

int my_putnbr_base(int nbr, char const *base)
{
    int nb_char = 0;

    if (nbr < 0) {
        write(1, "-", 1);
        nbr = (-nbr);
    }
    while (base[nb_char] != '\0')
        nb_char++;
    base_conv(nbr, nb_char, base);
    return (0);
}
