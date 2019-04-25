/*
** EPITECH PROJECT, 2019
** collision.c
** File description:
** manage the collision of the player on the map
*/

#include <stdbool.h>
#include "my.h"
#include "rpg.h"

bool manage_col_up(gameplay_t *gameplay, int pos_x, int mpos_y)
{
    int mpos_x = (pos_x + 59) / 100;

    if (mpos_x <= 59) {
        if ((mpos_x == mpos_x / 100) ||
            gameplay->map[mpos_y][mpos_x] == '0')
            return (true);
    }
    return (false);
}

bool manage_col_down(gameplay_t *gameplay, int pos_x, int mpos_y)
{
    int mpos_x = (pos_x + 59) / 100;

    if (mpos_x <= 59) {
        if ((mpos_x == mpos_x / 100) ||
            gameplay->map[mpos_y][mpos_x] == '0')
            return (true);
    }
    return (false);
}

bool manage_col_left(gameplay_t *gameplay, int mpos_x, int pos_y)
{
    int mpos_y = (pos_y + 79) / 100;

    if (mpos_y <= 59) {
        if ((mpos_y == pos_y / 100) ||
            gameplay->map[mpos_y][mpos_x] == '0')
            return (true);
    }
    return (false);
}

bool manage_col_right(gameplay_t *gameplay, int mpos_x, int pos_y)
{
    int mpos_y = (pos_y + 79) / 100;

    if (mpos_y <= 59) {
        if ((mpos_y == pos_y / 100) ||
            gameplay->map[mpos_y][mpos_x] == '0')
            return (true);
    }
    return (false);
}