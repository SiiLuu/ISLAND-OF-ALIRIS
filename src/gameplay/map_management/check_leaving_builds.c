/*
** EPITECH PROJECT, 2019
** open_col_files.c
** File description:
** my_defender, main function
*/

#include "rpg.h"
#include "my.h"

int check_leave_vil(global_t *global, int mpos_x, int mpos_y, int scn)
{
    if (scn == 11)
        if (global->gameplay->map[mpos_y][mpos_x] == 'S') {
            global->gameplay->map = global->gameplay->wmap;
            global->gameplay->x = 600;
            global->gameplay->y = 400;
            global->gameplay->width = 6000;
            global->gameplay->lenght = 6000;
            sfSprite_setPosition(global->gameplay->sprite_backg,
                                (sfVector2f){0, 0});
            sfSprite_setPosition(global->gameplay->sprite_man,
                                (sfVector2f){600, 400});
            sfSprite_setTexture(global->gameplay->sprite_backg,
                                global->gameplay->backg, sfTrue);
            scn = 1;
            global->gameplay->camera_x = 0;
            move_vue(global);
        }
    return (scn);
}

int check_leave_svil(global_t *global, int mpos_x, int mpos_y, int scn)
{
    if (scn == 14)
        if (global->gameplay->map[mpos_y][mpos_x] == 'S') {
            global->gameplay->map = global->gameplay->wmap;
            global->gameplay->x = 5300;
            global->gameplay->y = 5700;
            global->gameplay->width = 6000;
            global->gameplay->lenght = 6000;
            sfSprite_setPosition(global->gameplay->sprite_backg,
                                (sfVector2f){0, 0});
            sfSprite_setPosition(global->gameplay->sprite_man,
                                (sfVector2f){5300, 5700});
            sfSprite_setTexture(global->gameplay->sprite_backg,
                                global->gameplay->backg, sfTrue);
            scn = 1;
            global->gameplay->camera_y = 4920;
            move_vue(global);
        }
    return (scn);
}

int check_leave_cas(global_t *global, int mpos_x, int mpos_y, int scn)
{
    if (scn == 12)
        if (global->gameplay->map[mpos_y][mpos_x] == 'S') {
            global->gameplay->map = global->gameplay->wmap;
            global->gameplay->x = 2400;
            global->gameplay->y = 1100;
            global->gameplay->width = 6000;
            global->gameplay->lenght = 6000;
            sfSprite_setPosition(global->gameplay->sprite_backg,
                                (sfVector2f){0, 0});
            sfSprite_setPosition(global->gameplay->sprite_man,
                                (sfVector2f){2400, 1100});
            sfSprite_setTexture(global->gameplay->sprite_backg,
                                global->gameplay->backg, sfTrue);
            scn = 1;
            move_vue(global);
        }
    return (scn);
}

int check_leave_ncas(global_t *global, int mpos_x, int mpos_y, int scn)
{
    if (scn == 16)
        if (global->gameplay->map[mpos_y][mpos_x] == 'S') {
            global->gameplay->map = global->gameplay->wmap;
            global->gameplay->x = 5400;
            global->gameplay->y = 3900;
            global->gameplay->width = 6000;
            global->gameplay->lenght = 6000;
            sfSprite_setPosition(global->gameplay->sprite_backg,
                                (sfVector2f){0, 0});
            sfSprite_setPosition(global->gameplay->sprite_man,
                                (sfVector2f){5400, 3900});
            sfSprite_setTexture(global->gameplay->sprite_backg,
                                global->gameplay->backg, sfTrue);
            scn = 1;
            global->gameplay->camera_y = 4920 - 48;
            global->gameplay->camera_x = 4080;
            move_vue(global);
        }
    return (scn);
}

int check_leave_builds(global_t *global, int mpos_x, int mpos_y, int scn)
{
    if (scn != 1) {
        scn = check_leave_ncas(global, mpos_x, mpos_y, scn);
        scn = check_leave_cas(global, mpos_x, mpos_y, scn);
        scn = check_leave_fcas(global, mpos_x, mpos_y, scn);
        scn = check_leave_vil(global, mpos_x, mpos_y, scn);
        scn = check_leave_svil(global, mpos_x, mpos_y, scn);
        scn = check_leave_vol(global, mpos_x, mpos_y, scn);
        scn = check_leave_firecamps(global, mpos_x, mpos_y, scn);
        scn = check_leave_in_py(global, mpos_x, mpos_y, scn);
    }
    return (scn);
}