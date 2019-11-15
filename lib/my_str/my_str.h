/*
** EPITECH PROJECT, 2019
** LIB_STR_2019
** File description:
** LIB HEADER
*/

#ifndef MY_STR_H_
#define MY_STR_H_

#include "../my_nbr/my_nbr.h"

int my_advanced_sort_word_array(char **tab,
int (*cmp)(char const *, char const *));

int my_putstr(char const *str);

void my_putchar(char c);

void my_putstr_error(char *str);

char *my_revstr(char *str);

int my_showstr(char const *str);

int my_show_word_array(char * const *tab);

int my_sort_word_array(char **tab);

char *my_strcapitalize(char *str);

char *my_strcat(char *dest, char const *src);

int my_strcmp(char const *s1, char const *s2);

char *my_strcpy(char *dest, char const *src);

char *my_strdup(char const *src);

int my_str_isalpha(char const *str);

int my_str_islower(char const *str);

int my_str_isnum(char const *str);

int my_str_isprintable(char const *str);

int my_str_isupper(char const *str);

int my_strlen(char const *str);

char *my_strlowcase(char *str);

char *my_strncat(char *dest, char const *src, int nb);

char *my_strncpy(char *dest, char const *src, int n);

int my_strncmp(char const *s1, char const *s2, int n);

char *my_strstr(char *str, char const *to_find);

char **my_str_to_word_array(char const *str);

char *my_strupcase(char *str);

#endif
