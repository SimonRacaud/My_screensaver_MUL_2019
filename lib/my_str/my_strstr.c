/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** Task05
*/

#include <unistd.h>
#include "my_str.h"

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int len_fd = 0;

    if (to_find[0] == '\0')
        return (str);
    while (to_find[len_fd] != '\0')
        len_fd++;
    while (str[i] != '\0') {
        if (str[i] == to_find[0] && my_strncmp(&str[i], to_find, len_fd) == 0) {
            return (&str[i]);
        }
        i++;
    }
    return (NULL);
}
