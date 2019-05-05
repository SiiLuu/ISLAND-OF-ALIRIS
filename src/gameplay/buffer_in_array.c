/*
** EPITECH PROJECT, 2019
** get_map.c
** File description:
** get the map from the file given in parameter to catch the collision
*/

#include "rpg.h"
#include "my.h"

static int check_backn(char c, int k)
{
    if (c == '\n')
        return (k + 1);
    return (k);
}

static int get_len_line(char *buffer)
{
    int i = 0;

    for (i = 0; buffer[i] != '\n'; i++);
    return (i);
}

static int get_line_nbr(char *str)
{
    int i = 0;
    int count = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n')
            count++;
    }
    return (count + 1);
}

static char **set_line(char *buffer, char **map, int height, int len)
{
    int i = 0;
    int j = 0;
    int k = 0;

    for (i = 0; i != height; i++) {
        for (j = 0; j != len; j++) {
            k = check_backn(buffer[k], k);
            map[i][j] = buffer[k];
            k++;
        }
        map[i][j] = '\0';
    }
    return (map);
}

char **string_to_tab(char *buffer)
{
    char **map = NULL;
    int i = 0;
    int height = 0;
    int len = 0;

    height = get_line_nbr(buffer);
    if (height > 1)
        len = get_len_line(buffer);
    else
        len = my_strlen(buffer);
    map = malloc(sizeof(char *) * (height + 1));
    for (i = 0; i != height; i++) {
        map[i] = malloc(sizeof(char) * (len + 1));
    }
    map[i] = NULL;
    map = set_line(buffer, map, height, len);
    return (map);
}