/*
** EPITECH PROJECT, 2019
** open_col_files.c
** File description:
** my_defender, main function
*/

#include "my.h"
#include "rpg.h"

int check_volcano(global_t *global, int mpos_x, int mpos_y, int scn)
{
    if (global->gameplay->map[mpos_y][mpos_x] == 'F' && scn == 1) {
        global->gameplay->x = 0;
        global->gameplay->y = 2600;
        global->gameplay->width = 2800;
        global->gameplay->lenght = 2800;
        sfSprite_setPosition(global->gameplay->sprite_backg,
                            (sfVector2f){0, 0});
        sfSprite_setPosition(global->gameplay->sprite_man,
                            (sfVector2f){0, 2600});
        sfSprite_setTexture(global->gameplay->sprite_backg,
                            global->gameplay->backg_vol, sfTrue);
        global->gameplay->map = global->gameplay->mapc_vol;
        global->gameplay->camera_y = 1720;
        move_vue(global);
        scn = 13;
    }
    return (scn);
}