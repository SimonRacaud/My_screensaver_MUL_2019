/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** Task18
*/

int my_putchar(char c);

static void base_conv(int nb, int base, char const *basestr)
{
    int res[100];
    int i = 0;

    while (nb != 0) {
        res[i++] = (nb % base);
        nb /= base;
    }
    for (int j = (i - 1); j >= 0; j--) {
        my_putchar(basestr[res[j]]);
    }
}

int my_putnbr_base(int nbr, char const *base)
{
    int nb_char = 0;

    if (nbr < 0) {
        my_putchar('-');
        nbr = (-nbr);
    }
    while (base[nb_char] != '\0')
        nb_char++;
    base_conv(nbr, nb_char, base);
    return (0);
}
