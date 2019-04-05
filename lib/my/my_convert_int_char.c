/*
** EPITECH PROJECT, 2018
** my_convert_int_to_char.c
** File description:
** my_convert_int_to_char.c
*/

#include <stdlib.h>
#include <stdio.h>

char *convert_int_char(unsigned nbr)
{
    int s = 0;
    int i = nbr;
    char *str = NULL;

    while (i != 0) {
        i /= 10;
        s++;
    }
    str = malloc(sizeof(char) * (s + 1));
    for (i = s - 1 ; i >= 0 ; i--, nbr /= 10)
        str[i] = nbr % 10 + '0';
    str[s] = '\0';
    return (str);
}
