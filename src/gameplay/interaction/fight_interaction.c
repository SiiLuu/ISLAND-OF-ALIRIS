/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** interaction with the boss
*/

#include "my.h"
#include "rpg.h"
//2300, 2400 et 600, 6500

void switch_in_fight(global_t *global)
{
    if ((global->gameplay->x > 2300 && global->gameplay->x < 2400) &&
        (global->gameplay->y > 600 && global->gameplay->y < 650) &&
        global->fight->win_vs_final_boss == 0)
        global->scn = 5;
}
