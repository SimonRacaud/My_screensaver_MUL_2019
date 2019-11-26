/*
** EPITECH PROJECT, 2019
** my_sreensaver_2019
** File description:
** basic functions
*/

#include "my.h"
#include "my_screensaver.h"
#include "display.h"

void usage(void)
{
    my_putstr("\033[32mAnimation rendering in a CSFML window.\n\nUSAGE\n");
    my_putstr("\t./my_screensaver [OPTIONS] animation_id\n\tanimation_id\t");
    my_putstr(" ID of the animation to process (between 1 and 8).\n\n");
    my_putstr("OPTIONS\n\t-d\t\tprint the description of all the animations ");
    my_putstr("and quit.\n\t-h\t\tprint the usage and quit.\n\n");
    my_putstr("USER INTERACTIONS\n\tLEFT_ARROW\tswitch to the previous ");
    my_putstr("animation.\n\tRIGHT_ARROW\tswitch to the next animation.\n");
    my_putstr("\tUP_ARROW\tReload the window.\n");
    my_putstr("\tESCAPE\t\tClose the window.\n");
    my_putstr("\033[0m");
}

void description(void)
{
    my_putstr("\n\033[32m");
    for (int i = 0; i < MAX_ID; i++) {
        my_put_nbr(i + 1);
        my_putstr(": ");
        my_putstr(DESCRIPTION[i]);
        my_putstr("\n\n");
    }
    my_putstr("\033[0m");
}

int check_get_id(char *str)
{
    int i = -1;
    int id;

    while (str[++i] != '\0') {
        if (str[i] < '0' || str[i] > '9')
            return -1;
    }
    id = my_getnbr(str);
    if (id < 1 || id > MAX_ID) {
        usage();
        return -1;
    }
    return id;
}
