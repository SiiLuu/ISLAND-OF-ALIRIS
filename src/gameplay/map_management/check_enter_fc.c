/*
** EPITECH PROJECT, 2019
** check_enter_fc.c
** File description:
** manage the firecamps
*/

#include "my.h"
#include "rpg.h"

int check_firecamp(global_t *global, int mpos_x, int mpos_y, int scn)
{
    if (scn == 1)
        if (global->gameplay->map[mpos_y][mpos_x] == 'P') {
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
            scn = 20;
        }
    return (scn);
}

int check_nfirecamp(global_t *global, int mpos_x, int mpos_y, int scn)
{
    if (scn == 1)
        if (global->gameplay->map[mpos_y][mpos_x] == 'G') {
            global->gameplay->x = 1100;
            global->gameplay->y = 900;
            global->gameplay->width = 1920;
            global->gameplay->lenght = 1080;
            sfSprite_setPosition(global->gameplay->sprite_backg,
                                (sfVector2f){0, 0});
            sfView_reset(global->gameplay->view, (sfFloatRect){0,0,1920,1080});
            sfRenderWindow_setView(global->window, global->gameplay->view);
            sfSprite_setPosition(global->gameplay->sprite_man,
                                (sfVector2f){1100, 900});
            sfSprite_setTexture(global->gameplay->sprite_backg,
                                global->gameplay->backg_fcn, sfTrue);
            global->gameplay->map = global->gameplay->mapc_fcn;
            scn = 21;
        }
    return (scn);
}

int check_tfirecamp(global_t *global, int mpos_x, int mpos_y, int scn)
{
    if (scn == 1)
        if (global->gameplay->map[mpos_y][mpos_x] == 'T') {
            global->gameplay->x = 1100;
            global->gameplay->y = 900;
            global->gameplay->width = 1920;
            global->gameplay->lenght = 1080;
            sfSprite_setPosition(global->gameplay->sprite_backg,
                                (sfVector2f){0, 0});
            sfView_reset(global->gameplay->view, (sfFloatRect){0,0,1920,1080});
            sfRenderWindow_setView(global->window, global->gameplay->view);
            sfSprite_setPosition(global->gameplay->sprite_man,
                                (sfVector2f){1100, 900});
            sfSprite_setTexture(global->gameplay->sprite_backg,
                                global->gameplay->backg_fcf, sfTrue);
            global->gameplay->map = global->gameplay->mapc_fcf;
            scn = 22;
        }
    return (scn);
}
