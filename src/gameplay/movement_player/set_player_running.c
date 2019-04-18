/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** movement_player
*/

#include "my.h"
#include "rpg.h"

void move_rect_running(gameplay_t *gameplay)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(gameplay->clocks)) > 70) {
        gameplay->rect_man.left += 48;
        sfClock_restart(gameplay->clocks);
    }
    if (gameplay->rect_man.left > 528)
        gameplay->rect_man.left = 432;
}

void move_rect_running_p2(gameplay_t *gameplay)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(gameplay->clocks)) > 70) {
        gameplay->rect_man.left += 48;
        sfClock_restart(gameplay->clocks);
    }
    if (gameplay->rect_man.left > 240)
        gameplay->rect_man.left = 144;
}

void move_rect_running_p3(gameplay_t *gameplay)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(gameplay->clocks)) > 70) {
        gameplay->rect_man.left += 48;
        sfClock_restart(gameplay->clocks);
    }
    if (gameplay->rect_man.left > 92)
        gameplay->rect_man.left = 0;
}

void move_rect_running_p4(gameplay_t *gameplay)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(gameplay->clocks)) > 70) {
        gameplay->rect_man.left += 48;
        sfClock_restart(gameplay->clocks);
    }
    if (gameplay->rect_man.left > 384)
        gameplay->rect_man.left = 288;
}