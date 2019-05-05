/*
** EPITECH PROJECT, 2019
** open_col_files.c
** File description:
** my_defender, main function
*/

#include "my.h"
#include "rpg.h"

int check_leave_vol(global_t *global, int mpos_x, int mpos_y, int scn) {
    if (scn == 13)
        if (global->gameplay->map[mpos_y][mpos_x] == 'S') {
            global->gameplay->map = global->gameplay->wmap;
            global->gameplay->x = 1500;
            global->gameplay->y = 600;
            global->gameplay->width = 6000;
            global->gameplay->lenght = 6000;
            sfSprite_setPosition(global->gameplay->sprite_backg,
                                (sfVector2f){0, 0});
            sfSprite_setPosition(global->gameplay->sprite_man,
                                (sfVector2f){1500, 600});
            sfSprite_setTexture(global->gameplay->sprite_backg,
                                global->gameplay->backg, sfTrue);
            scn = 1;
            move_vue(global);
        }
    return (scn);
}

int check_leave_fcas(global_t *global, int mpos_x, int mpos_y, int scn)
{
    if (scn == 15)
        if (global->gameplay->map[mpos_y][mpos_x] == 'S') {
            global->gameplay->map = global->gameplay->wmap;
            global->gameplay->x = 1400;
            global->gameplay->y = 5600;
            global->gameplay->width = 6000;
            global->gameplay->lenght = 6000;
            sfSprite_setPosition(global->gameplay->sprite_backg,
                                (sfVector2f){0, 0});
            sfSprite_setPosition(global->gameplay->sprite_man,
                                (sfVector2f){1300, 5600});
            sfSprite_setTexture(global->gameplay->sprite_backg,
                                global->gameplay->backg, sfTrue);
            scn = 1;
            global->gameplay->camera_y = 4920;
            move_vue(global);
        }
    return (scn);
}