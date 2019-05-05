/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** check when the monster is dead
*/

#include "my.h"
#include "rpg.h"

void check_other_events(global_t *global)
{
    if (global->gameplay->boss->win_vs_desert_boss == 1) {
        sfSprite_setColor(global->gameplay->boss->sp_desert_boss,
                        sfTransparent);
        global->gameplay->map[33][5] = '0';
    }
    if (global->gameplay->boss->win_vs_hl_boss == 1) {
        sfSprite_setColor(global->gameplay->boss->sp_hl_boss, sfTransparent);
        global->gameplay->map[58][4] = '0';
    }
    if (global->gameplay->boss->quest_fboss == 4 &&
        global->gameplay->boss->s_last_quest == 1)
        global->gameplay->map[9][14] = '0';
    if (global->gameplay->pnj->status->girl_quest == 0)
        global->gameplay->map[50][50] = '0';
    else
        global->gameplay->map[50][50] = '5';
}

void check_monster_dead(global_t *global)
{
    if (global->scn == 1) {
        if (global->gameplay->boss->win_vs_final_boss == 1) {
            sfSprite_setColor(global->gameplay->boss->sp_final_boss,
                            sfTransparent);
            global->gameplay->map[5][23] = '0';
            global->gameplay->map[5][24] = '0';
        }
        if (global->gameplay->boss->win_vs_winter_boss == 1) {
            sfSprite_setColor(global->gameplay->boss->sp_winter_boss,
                            sfTransparent);
            global->gameplay->map[31][54] = '0';
        }
        check_other_events(global);
    }
    if (global->scn == 13) {
        if (global->gameplay->boss->win_vs_volc_boss == 1)
        sfSprite_setColor(global->gameplay->boss->sp_volc_boss,
                        sfTransparent);
    }
}