/*
** EPITECH PROJECT, 2018
** my_strlen
** File description:
** task01 day07 library
*/
#include "../../include/my.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}