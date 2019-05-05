/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** player_moving
*/

#include "my.h"
#include "rpg.h"

void move_rect_p2(gameplay_t *gameplay)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(gameplay->clocks))
        > 100) {
        gameplay->rect_man.left += 48;
        sfClock_restart(gameplay->clocks);
    }
    if (gameplay->rect_man.left > 240)
        gameplay->rect_man.left = 144;
}

void move_rect_p3(gameplay_t *gameplay)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(gameplay->clocks))
        > 100) {
        gameplay->rect_man.left += 48;
        sfClock_restart(gameplay->clocks);
    }
    if (gameplay->rect_man.left > 92)
        gameplay->rect_man.left = 0;
}

void move_rect_p4(gameplay_t *gameplay)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(gameplay->clocks))
        > 100) {
        gameplay->rect_man.left += 48;
        sfClock_restart(gameplay->clocks);
    }
    if (gameplay->rect_man.left > 384)
        gameplay->rect_man.left = 288;
}

void move_rect_p1(gameplay_t *gameplay)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(gameplay->clocks))
        > 100) {
        gameplay->rect_man.left += 48;
        sfClock_restart(gameplay->clocks);
    }
    if (gameplay->rect_man.left > 528)
        gameplay->rect_man.left = 432;
}