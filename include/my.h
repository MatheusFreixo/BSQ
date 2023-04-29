/*
** EPITECH PROJECT, 2022
** MY.H
** File description:
** ...
*/
#ifndef MY_H
    #define MY_H

    #include <unistd.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <fcntl.h>
    #include <sys/stat.h>

void my_putchar(char c);

int my_put_nbr(int nb);

int my_putstr(char const *str);

char **my_str_to_word_array(char const *str, char c);

int my_strlen(char const *str);

char *my_strncpy(char *dest, char const *src, int n);

int my_getnbr(char *str);

int my_strcmp(char const *s1, char const *s2);

#endif
