/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** Task21
*/

#include "my_misc.h"
#include <unistd.h>

static void disp_lastchar(char const *str, int index, int nb)
{
    for (int i = nb; i > 0; i--) {
        if (str[index - i] < 32 || str[index - i] > 126)
            write(1, ".", 1);
        else
            write(1, &str[index - i], 1);
    }
}

static void base_conv(int nb, int base, char const *basestr, int lennb)
{
    int res[100];
    int i = 0;

    while (nb != 0) {
        res[i++] = (nb % base);
        nb /= base;
    }
    for (int j = 0; j < (lennb - i); j++)
        write(1, "0", 1);
    for (int j = (i - 1); j >= 0; j--)
        write(1, &basestr[res[j]], 1);
}

static void disp_asciihex(int *adr, char const *str, int nb)
{
    for (int i = 0; i < nb; i++) {
        base_conv(str[*adr], 16, "0123456789abcdef", 2);
        if (*adr % 2 != 0)
            write(1, " ", 1);
        (*adr)++;
    }
    for (int i = 0; i < (16 - nb); i++) {
        for (int j = 0; j < 2; j++)
            write(1, " ", 1);
        if (i % 2 != 0)
            write(1, " ", 1);
    }
    if (nb % 2 != 0)
        write(1, " ", 1);
}

static void disp(int *adr, char const *str, int nb)
{
    base_conv(*adr, 16, "0123456789abcdef", 8);
    write(1, ": ", 2);
    disp_asciihex(adr, str, nb);
    disp_lastchar(str, *adr, nb);
    write(1, "\n", 1);
}

int my_showmem(char const *str, int size)
{
    int adr = 0;

    for (int i = 0; i < (size / 16); i++)
        disp(&adr, str, 16);
    if (size % 16 != 0) {
        disp(&adr, str, (size % 16));
    }
    return (0);
}
