/*
** EPITECH PROJECT, 2019
** get_map.c
** File description:
** get the map from the file given in parameter to catch the collision
*/

#include "rpg.h"
#include "my.h"

static int get_len_file(gameplay_t *gameplay)
{
    int i = 0;

    while (gameplay->map[i] != NULL) {
        i++;
    }
    return (i - 1);
}

static int get_len_line(gameplay_t *gameplay)
{
    int i = 0;

    for (i = 0; gameplay->buffer[i] != '\n'; i++);
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

static void set_line(gameplay_t *gameplay, int height, int len)
{
    int i = 0;
    int j = 0;
    int k = 0;

    for (i = 0; i != height; i++) {
        for (j = 0; j != len; j++) {
            if (gameplay->buffer[k] == '\n')
                k++;
            gameplay->map[i][j] = gameplay->buffer[k];
            k++;
            if (j + 1 == len)
                gameplay->map[i][j + 2] = '\0';
        }
    }
}

void string_to_tab(gameplay_t *gameplay)
{
    int i = 0;
    int height = get_line_nbr(gameplay->buffer);
    int len = 0;

    if (height > 1)
        len = get_len_line(gameplay);
    else
        len = my_strlen(gameplay->buffer);
    gameplay->map = malloc(sizeof(char *) * (height + 1));
    for (i = 0; i != height; i++) {
        gameplay->map[i] = malloc(sizeof(char) * (len + 1));
    }
    gameplay->map[i] = NULL;
    set_line(gameplay, height, len);
}