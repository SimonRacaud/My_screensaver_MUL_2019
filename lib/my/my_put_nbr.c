/*
** EPITECH PROJECT, 2019
** CPool_Day03_2019
** File description:
** void
*/

void my_putchar(char c);
static int poww3(int x, int n);

int my_put_nbr(int nb)
{
    int i = 0;
    char c;
    long int lnb = nb;

    if (lnb < 0) {
        my_putchar('-');
        lnb = -lnb;
    }
    while (lnb / poww3(10, i) >= 10) {
        i++;
    }
    while (i >= 0) {
        c = ((lnb / poww3(10, i)) % 10) + '0';
        my_putchar(c);
        i--;
    }
    return (0);
}
static int poww3(int x, int n)
{
    if (n == 0) {
        return (1);
    } else {
        return (x * poww3(x, n-1));
    }
}
