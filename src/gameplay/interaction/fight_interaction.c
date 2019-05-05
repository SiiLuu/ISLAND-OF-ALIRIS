/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** interaction with the boss
*/

#include "my.h"
#include "rpg.h"

void fight_in_volc(global_t *global)
{
    if ((global->gameplay->x > 1150 && global->gameplay->x < 1350) &&
        (global->gameplay->y > 1300 && global->gameplay->y < 1500) &&
        global->gameplay->boss->win_vs_volc_boss == 0) {
            global->fight->enemis = 5;
            global->scn = 5;
        }
}

void fight_in_highland(global_t *global)
{
    if ((global->gameplay->x > 290 && global->gameplay->x < 450) &&
        (global->gameplay->y > 5700 && global->gameplay->y < 5850) &&
        global->gameplay->boss->win_vs_hl_boss == 0) {
            global->fight->enemis = 4;
            global->scn = 5;
        }
}

void switch_in_fight(global_t *global)
{
    if ((global->gameplay->x > 2200 && global->gameplay->x < 2400) &&
        (global->gameplay->y > 550 && global->gameplay->y < 650) &&
        global->gameplay->boss->win_vs_final_boss == 0) {
            global->fight->enemis = 1;
            global->scn = 5;
        }
    if ((global->gameplay->x > 390 && global->gameplay->x < 650) &&
        (global->gameplay->y > 3150 && global->gameplay->y < 3420) &&
        global->gameplay->boss->win_vs_desert_boss == 0) {
            global->fight->enemis = 2;
            global->scn = 5;
        }
    if ((global->gameplay->x > 5250 && global->gameplay->x < 5400) &&
        (global->gameplay->y > 2950 && global->gameplay->y < 3150) &&
        global->gameplay->boss->win_vs_winter_boss == 0) {
            global->fight->enemis = 3;
            global->scn = 5;
        }
    fight_in_highland(global);
}