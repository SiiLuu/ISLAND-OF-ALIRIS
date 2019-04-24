/*
** EPITECH PROJECT, 2019
** collision.c
** File description:
** manage the collision of the player on the map
*/

#include <stdbool.h>
#include "my.h"
#include "rpg.h"

bool check_collision_up(gameplay_t *gameplay, int distance)
{
    int pos_x = gameplay->x;
    int pos_y = gameplay->y - distance;
    int mpos_x = pos_x / 100;
    int mpos_y = pos_y / 100;

    if (pos_y > 0) {
        if ((gameplay->map[mpos_y][mpos_x] == '0') &&
            manage_col_up(gameplay, pos_x, mpos_y) == true)
            return (true);
    }
    return (false); 
}

bool check_collision_down(gameplay_t *gameplay, int distance)
{
    int pos_x = gameplay->x;
    int pos_y = (gameplay->y + distance) + 99;
    int mpos_x = pos_x / 100;
    int mpos_y = pos_y / 100;

    if (pos_y < 6000) {
        if ((gameplay->map[mpos_y][mpos_x] == '0') &&
            manage_col_down(gameplay, pos_x, mpos_y) == true)
            return (true);
    }
    return (false);
}

bool check_collision_left(gameplay_t *gameplay, int distance)
{
    int pos_x = (gameplay->x - distance);
    int pos_y = gameplay->y;
    int mpos_x = pos_x / 100;
    int mpos_y = pos_y / 100;

    if (pos_x > 0) {
        if (gameplay->map[mpos_y][mpos_x] == '0' &&
            manage_col_left(gameplay, mpos_x, pos_y) == true)
            return (true);
    }
    return (false); 
}

bool check_collision_right(gameplay_t *gameplay, int distance)
{
    int pos_x = (gameplay->x + distance) + 99;
    int pos_y = gameplay->y;
    int mpos_x = pos_x / 100;
    int mpos_y = pos_y / 100;

    if (pos_x < 6000) {
        if (gameplay->map[mpos_y][mpos_x] == '0' &&
        manage_col_right(gameplay, mpos_x, pos_y) == true)
        return (true);
    }
    return (false); 
}