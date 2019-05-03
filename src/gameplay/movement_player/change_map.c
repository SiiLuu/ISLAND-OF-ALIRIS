/*
** EPITECH PROJECT, 2019
** open_col_files.c
** File description:
** my_defender, main function
*/

#include "rpg.h"
#include "my.h"

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

int check_castle(global_t *global, int mpos_x, int mpos_y, int scn)
{
    if (global->gameplay->map[mpos_y][mpos_x] == 'C' && scn == 1) {
        global->gameplay->x = 2000;
        global->gameplay->y = 2900;
        global->gameplay->width = 4000;
        global->gameplay->lenght = 3200;
        sfSprite_setPosition(global->gameplay->sprite_backg,
                            (sfVector2f){0, 0});
        sfSprite_setPosition(global->gameplay->sprite_man,
                            (sfVector2f){2000, 2900});
        sfSprite_setTexture(global->gameplay->sprite_backg,
                            global->gameplay->backg_cas, sfTrue);
        global->gameplay->map = global->gameplay->mapc_cas;
        global->gameplay->camera_y = 2120;
        move_vue(global);
        scn = 12;
    }
    return (scn);
}

int check_village(global_t *global, int mpos_x, int mpos_y, int scn)
{
    if (global->gameplay->map[mpos_y][mpos_x] == 'V' && scn == 1) {
        global->gameplay->x = 2000;
        global->gameplay->y = 1800;
        global->gameplay->width = 4000;
        global->gameplay->lenght = 2000;
        sfSprite_setPosition(global->gameplay->sprite_backg,
                            (sfVector2f){0, 0});
        sfView_reset(global->gameplay->view, (sfFloatRect){0,00,1920,1080});
        sfRenderWindow_setView(global->window, global->gameplay->view);
        sfSprite_setPosition(global->gameplay->sprite_man,
                            (sfVector2f){2000, 1800});
        sfSprite_setTexture(global->gameplay->sprite_backg,
                            global->gameplay->backg_vil, sfTrue);
        global->gameplay->map = global->gameplay->mapc_vil;
        global->gameplay->camera_y = 960 - 48;
        move_vue(global);
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
        scn = check_village(global, mpos_x, mpos_y, scn);
        scn = check_castle(global, mpos_x, mpos_y, scn);
        scn = check_volcano(global, mpos_x, mpos_y, scn);
        return (scn);
    }
    if (scn == 10)
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