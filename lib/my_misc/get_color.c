/*
** EPITECH PROJECT, 2019
** CPool_Day09_2019
** File description:
** Task05 - Returns the color as an int by handling its three RGB components
*/

int get_color(unsigned char red, unsigned char green, unsigned char blue)
{
    int color = (int)red;

    color = color << 8;
    color += (int)green;
    color = color << 8;
    color += (int)blue;
    return (color);
}
