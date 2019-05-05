/*
** EPITECH PROJECT, 2019
** check_enter_builds.c
** File description:
** my_defender, main function
*/

#include "rpg.h"
#include "my.h"

int check_ncastle(global_t *global, int mpos_x, int mpos_y, int scn)
{
    if (scn == 1)
        if (global->gameplay->map[mpos_y][mpos_x] == 'N') {
            global->gameplay->x = 1500;
            global->gameplay->y = 2600;
            global->gameplay->width = 3000;
            global->gameplay->lenght = 3000;
            sfSprite_setPosition(global->gameplay->sprite_backg,
                                (sfVector2f){0, 0});
            sfSprite_setPosition(global->gameplay->sprite_man,
                                (sfVector2f){1500, 2600});
            sfSprite_setTexture(global->gameplay->sprite_backg,
                                global->gameplay->backg_casn, sfTrue);
            global->gameplay->map = global->gameplay->mapc_casn;
            global->gameplay->camera_y = 1920;
            move_vue(global);
            scn = 16;
        }
    return (scn);
}

int check_castle(global_t *global, int mpos_x, int mpos_y, int scn)
{
    if (scn == 1)
        if (global->gameplay->map[mpos_y][mpos_x] == 'C') {
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
    if (scn == 1)
        if (global->gameplay->map[mpos_y][mpos_x] == 'V') {
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

int check_svillage(global_t *global, int mpos_x, int mpos_y, int scn)
{
    if (scn == 1)
        if (global->gameplay->map[mpos_y][mpos_x] == 'K') {
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
                                global->gameplay->backg_viln, sfTrue);
            global->gameplay->map = global->gameplay->mapc_viln;
            global->gameplay->camera_y = 960 - 48;
            move_vue(global);
            scn = 14;
        }
    return (scn);
}

int check_enter_builds(global_t *global, int mpos_x, int mpos_y, int scn)
{
    if (scn == 1) {
        scn = check_firecamp(global, mpos_x, mpos_y, scn);
        scn = check_nfirecamp(global, mpos_x, mpos_y, scn);
        scn = check_tfirecamp(global, mpos_x, mpos_y, scn);
        scn = check_village(global, mpos_x, mpos_y, scn);
        scn = check_svillage(global, mpos_x, mpos_y, scn);
        scn = check_castle(global, mpos_x, mpos_y, scn);
        scn = check_ncastle(global, mpos_x, mpos_y, scn);
        scn = check_fcastle(global, mpos_x, mpos_y, scn);
        scn = check_volcano(global, mpos_x, mpos_y, scn);
        scn = check_out_py(global, mpos_x, mpos_y, scn);
    }
    else if (scn == 17) {
        scn = check_in_py(global, mpos_x, mpos_y, scn);
        scn = check_leave_out_py(global, mpos_x, mpos_y, scn);
    }
    return (scn);
}