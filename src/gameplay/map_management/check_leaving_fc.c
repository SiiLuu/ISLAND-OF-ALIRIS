/*
** EPITECH PROJECT, 2019
** open_col_files.c
** File description:
** my_defender, main function
*/

#include "rpg.h"
#include "my.h"

int check_leave_pfc(global_t *global, int mpos_x, int mpos_y, int scn)
{
    if (scn == 20)
        if (global->gameplay->map[mpos_y][mpos_x] == 'S') {
            global->gameplay->map = global->gameplay->wmap;
            global->gameplay->x = 300;
            global->gameplay->y = 900;
            global->gameplay->width = 6000;
            global->gameplay->lenght = 6000;
            sfSprite_setPosition(global->gameplay->sprite_backg,
                                (sfVector2f){0, 0});
            sfSprite_setPosition(global->gameplay->sprite_man,
                                (sfVector2f){300, 900});
            sfSprite_setTexture(global->gameplay->sprite_backg,
                                global->gameplay->backg, sfTrue);
            scn = 1;
            move_vue(global);
        }
    return (scn);
}

int check_leave_fcn(global_t *global, int mpos_x, int mpos_y, int scn)
{
    if (scn == 21)
        if (global->gameplay->map[mpos_y][mpos_x] == 'S') {
            global->gameplay->map = global->gameplay->wmap;
            global->gameplay->x = 5300;
            global->gameplay->y = 4300;
            global->gameplay->width = 6000;
            global->gameplay->lenght = 6000;
            sfSprite_setPosition(global->gameplay->sprite_backg,
                                (sfVector2f){0, 0});
            sfSprite_setPosition(global->gameplay->sprite_man,
                                (sfVector2f){5300, 4300});
            sfSprite_setTexture(global->gameplay->sprite_backg,
                                global->gameplay->backg, sfTrue);
            scn = 1;
            move_vue(global);
        }
    return (scn);
}

int check_leave_fcf(global_t *global, int mpos_x, int mpos_y, int scn)
{
    if (scn == 22)
        if (global->gameplay->map[mpos_y][mpos_x] == 'S') {
            global->gameplay->map = global->gameplay->wmap;
            global->gameplay->x = 3100;
            global->gameplay->y = 4700;
            global->gameplay->width = 6000;
            global->gameplay->lenght = 6000;
            sfSprite_setPosition(global->gameplay->sprite_backg,
                                (sfVector2f){0, 0});
            sfSprite_setPosition(global->gameplay->sprite_man,
                                (sfVector2f){3100, 4700});
            sfSprite_setTexture(global->gameplay->sprite_backg,
                                global->gameplay->backg, sfTrue);
            scn = 1;
            move_vue(global);
        }
    return (scn);
}

int check_leave_firecamps(global_t *global, int mpos_x, int mpos_y, int scn)
{
    scn = check_leave_pfc(global, mpos_x, mpos_y, scn);
    scn = check_leave_fcf(global, mpos_x, mpos_y, scn);
    scn = check_leave_fcn(global, mpos_x, mpos_y, scn);
    return (scn);
}