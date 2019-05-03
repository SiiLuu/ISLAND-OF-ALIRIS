/*
** EPITECH PROJECT, 2019
** open_col_files.c
** File description:
** my_defender, main function
*/

#include "rpg.h"
#include "my.h"

int check_map_change(global_t *global, int scn)
{
    int pos_x = (global->gameplay->x + 50);
    int pos_y = (global->gameplay->y + 50);
    int mpos_x = pos_x / 100;
    int mpos_y = pos_y / 100;

    if (scn == 1) {
        scn = check_firecamp(global, mpos_x, mpos_y, scn);
        scn = check_village(global, mpos_x, mpos_y, scn);
        scn = check_castle(global, mpos_x, mpos_y, scn);
        scn = check_volcano(global, mpos_x, mpos_y, scn);
        return (scn);
    }
    else {
        scn = check_leave_builds(global, mpos_x, mpos_y, scn);
    }
    return (scn);
}