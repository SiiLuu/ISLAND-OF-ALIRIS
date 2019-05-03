/*
** EPITECH PROJECT, 2019
** check_enter_builds.c
** File description:
** my_defender, main function
*/

#include "rpg.h"
#include "my.h"

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