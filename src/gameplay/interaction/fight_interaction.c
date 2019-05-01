/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** interaction with the boss
*/

#include "my.h"
#include "rpg.h"

void switch_in_fight(global_t *global)
{
    if ((global->gameplay->x > 2300 && global->gameplay->x < 2400) &&
        (global->gameplay->y > 600 && global->gameplay->y < 650) &&
        global->gameplay->boss->win_vs_final_boss == 0) {
            global->fight->enemis = 1;
            global->scn = 5;
        }
    if ((global->gameplay->x > 5250 && global->gameplay->x < 5400) &&
        (global->gameplay->y > 2950 && global->gameplay->y < 3150) &&
        global->gameplay->boss->win_vs_winter_boss == 0) {
            global->fight->enemis = 3;
            global->scn = 5;
        }
}
