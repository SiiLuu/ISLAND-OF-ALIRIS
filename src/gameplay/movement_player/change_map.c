/*
** EPITECH PROJECT, 2019
** open_col_files.c
** File description:
** my_defender, main function
*/

#include "rpg.h"
#include "my.h"

int check_village(global_t *global, int mpos_x, int mpos_y, int scn)
{
    if (global->gameplay->map[mpos_y][mpos_x] == 'V' && scn == 1) {
        global->gameplay->x = 1600;
        global->gameplay->y = 1400;
        global->gameplay->width = 4000;
        global->gameplay->lenght = 2000;
        sfSprite_setPosition(global->gameplay->sprite_backg,
                            (sfVector2f){0, 0});
        sfView_reset(global->gameplay->view, (sfFloatRect){0,00,1920,1080});
        sfRenderWindow_setView(global->window, global->gameplay->view);
        sfSprite_setPosition(global->gameplay->sprite_man,
                            (sfVector2f){1600, 1400});
        sfSprite_setTexture(global->gameplay->sprite_backg,
                            global->gameplay->backg_vil, sfTrue);
        global->gameplay->map = global->gameplay->mapc_vil;
        scn = 11;                          
    }
    return (scn);
}

int check_firecamp(global_t *global, int mpos_x, int mpos_y, int scn)
{
    if (global->gameplay->map[mpos_y][mpos_x] == 'P' && scn == 1) {
        global->gameplay->x = 900;
        global->gameplay->y = 900;
        global->gameplay->width = 1920;
        global->gameplay->lenght = 1080;
        sfSprite_setPosition(global->gameplay->sprite_backg,
                            (sfVector2f){0, 0});
        sfView_reset(global->gameplay->view, (sfFloatRect){0,0,1920,1080});
        sfRenderWindow_setView(global->window, global->gameplay->view);
        sfSprite_setPosition(global->gameplay->sprite_man,
                            (sfVector2f){900, 900});
        sfSprite_setTexture(global->gameplay->sprite_backg,
                            global->gameplay->backg_fcp, sfTrue);
        global->gameplay->map = global->gameplay->mapc_fcp;
        scn = 10;
    }
    return (scn);
}

int check_map_change(global_t *global, int scn)
{
    int pos_x = (global->gameplay->x + 50);
    int pos_y = (global->gameplay->y + 50);
    int mpos_x = pos_x / 100;
    int mpos_y = pos_y / 100;

    if (scn == 1) {
        scn = check_firecamp(global, mpos_x, mpos_y, scn);
        //scn = check_village(global, mpos_x, mpos_y, scn);
    }
    else if (scn == 10)
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