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
    int pos_x = gameplay->x / 100;
    int pos_y = gameplay->y / 100;

    printf("gmx = %d && gmy = %d\n", gameplay->x, gameplay->y);
    printf("x = %d && y = %d\n", pos_x, pos_y);
    if (gameplay->map[pos_y - 1][pos_x] == '0' || 
        ((gameplay->y - distance > (pos_y) * 100) &&
        gameplay->map[pos_y - 1][pos_x] != '0'))
        return (true);
    return (false); 
}

bool check_collision_left(gameplay_t *gameplay, int distance)
{
    int pos_x = gameplay->x / 100;
    int pos_y = gameplay->y / 100;

    printf("gmx = %d && gmy = %d\n", gameplay->x, gameplay->y);
    printf("x = %d && y = %d\n", pos_x, pos_y);
    if  ((gameplay->map[pos_y][pos_x - 1] == '0' || 
        ((gameplay->x - distance > pos_x * 100) &&
        gameplay->map[pos_y][pos_x - 1] != '0'))) /*&&
        ((manage_col_left(gameplay) == true) || pos_x == 0))*/
        return (true);
    return (false); 
}

bool manage_col_left(gameplay_t *gameplay)
{
    int pos_x = gameplay->x / 100;
    int pos_y = gameplay->y / 100;

    if  ((gameplay->y + 100) >= ((pos_y + 1) * 100) + 6) {
        if (gameplay->map[pos_y + 1][pos_x - 1] != '0')
            return (false);
        else
            return (true);
    }
    return (true);

}

bool manage_col_right(gameplay_t *gameplay)
{
    int pos_x = gameplay->x / 100;
    int pos_y = gameplay->y / 100;

    if  ((gameplay->y + 100) >= ((pos_y + 1) * 100) + 6) {
        if (gameplay->map[pos_y + 1][pos_x + 1] != '0')
            return (false);
        else
            return (true);
    }
    return (true);

}

bool check_collision_right(gameplay_t *gameplay, int distance)
{
    int pos_x = gameplay->x / 100;
    int pos_y = gameplay->y / 100;

    printf("gmx = %d && gmy = %d\n", gameplay->x, gameplay->y);
    printf("x = %d && y = %d\n", pos_x, pos_y);
    if ((gameplay->map[pos_y][pos_x + 1] == '0' || 
        ((gameplay->y - distance > (pos_y) * 100) &&
        gameplay->map[pos_y][pos_x + 1] != '0')))/* &&
        ((manage_col_right(gameplay) == true) || pos_x == 60))*/
        return (true);
    return (false); 
}

bool check_collision_down(gameplay_t *gameplay, int distance)
{
    int pos_x = gameplay->x / 100;
    int pos_y = gameplay->y / 100;

    printf("gmx = %d && gmy = %d\n", gameplay->x, gameplay->y);
    printf("x = %d && y = %d\n", pos_x, pos_y);
    if (gameplay->map[pos_y + 1][pos_x] == '0' || 
        ((gameplay->y - distance > (pos_y) * 100) &&
        gameplay->map[pos_y + 1][pos_x] != '0'))
        return (true);
    return (false); 
}