/*
** EPITECH PROJECT, 2019
** check_pyramid.c
** File description:
** manage the pyramid (enters, quit)
*/

#include "rpg.h"
#include "my.h"

int check_in_py(global_t *global, int mpos_x, int mpos_y, int scn)
{
    if (scn == 17)
        if (global->gameplay->map[mpos_y][mpos_x] == 'E') {
            global->gameplay->x = 1000;
            global->gameplay->y = 1900;
            global->gameplay->width = 1920;
            global->gameplay->lenght = 2500;
            sfView_reset(global->gameplay->view,
                        (sfFloatRect){0, 0, 1920, 1080});
            sfRenderWindow_setView(global->window, global->gameplay->view);
            sfSprite_setPosition(global->gameplay->sprite_backg,
                                (sfVector2f){0, 0});
            sfSprite_setPosition(global->gameplay->sprite_man,
                                (sfVector2f){1000, 1900});
            sfSprite_setTexture(global->gameplay->sprite_backg,
                                global->gameplay->backg_inpy, sfTrue);
            global->gameplay->map = global->gameplay->mapc_inpy;
            global->gameplay->camera_y = 1420;
            move_vue(global);
            scn = 18;
        }
    return (scn);
}

int check_leave_in_py(global_t *global, int mpos_x, int mpos_y, int scn)
{
    if (scn == 18)
        if (global->gameplay->map[mpos_y][mpos_x] == 'S') {
            global->gameplay->map = global->gameplay->mapc_outpy;
            global->gameplay->x = 1000;
            global->gameplay->y = 500;
            global->gameplay->width = 1920;
            global->gameplay->lenght = 1080;
            sfView_reset(global->gameplay->view,
                        (sfFloatRect){0,00,1920,1080});
            sfRenderWindow_setView(global->window, global->gameplay->view);
            sfSprite_setPosition(global->gameplay->sprite_backg,
                                (sfVector2f){0, 0});
            sfSprite_setPosition(global->gameplay->sprite_man,
                                (sfVector2f){1000, 500});
            sfSprite_setTexture(global->gameplay->sprite_backg,
                                global->gameplay->backg_outpy, sfTrue);
            scn = 17;
            move_vue(global);
        }
    return (scn);
}

int check_out_py(global_t *global, int mpos_x, int mpos_y, int scn)
{
    if (scn == 1)
        if (global->gameplay->map[mpos_y][mpos_x] == 'E') {
            global->gameplay->x = 1000;
            global->gameplay->y = 900;
            global->gameplay->width = 1920;
            global->gameplay->lenght = 1080;
            sfView_reset(global->gameplay->view,
                        (sfFloatRect){0, 0, 1920, 1080});
            sfRenderWindow_setView(global->window, global->gameplay->view);
            sfSprite_setPosition(global->gameplay->sprite_backg,
                                (sfVector2f){0, 0});
            sfSprite_setPosition(global->gameplay->sprite_man,
                                (sfVector2f){1000, 900});
            sfSprite_setTexture(global->gameplay->sprite_backg,
                                global->gameplay->backg_outpy, sfTrue);
            global->gameplay->map = global->gameplay->mapc_outpy;
            global->gameplay->camera_y = 0;
            move_vue(global);
            scn = 17;
        }
    return (scn);
}

int check_leave_out_py(global_t *global, int mpos_x, int mpos_y, int scn)
{
    if (scn == 17)
        if (global->gameplay->map[mpos_y][mpos_x] == 'S') {
            global->gameplay->map = global->gameplay->wmap;
            global->gameplay->x = 100;
            global->gameplay->y = 2900;
            global->gameplay->width = 6000;
            global->gameplay->lenght = 6000;
            sfSprite_setPosition(global->gameplay->sprite_backg,
                                (sfVector2f){0, 0});
            sfSprite_setPosition(global->gameplay->sprite_man,
                                (sfVector2f){100, 2900});
            sfSprite_setTexture(global->gameplay->sprite_backg,
                                global->gameplay->backg, sfTrue);
            scn = 1;
            move_vue(global);
        }
    return (scn);
}