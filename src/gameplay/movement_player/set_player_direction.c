/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** player_direction
*/

#include "my.h"
#include "rpg.h"

void set_rect_left(global_t *global)
{
    if (global->gameplay->player_nb == 1)
        global->gameplay->rect_man.top = 48;
    if (global->gameplay->player_nb == 2)
        global->gameplay->rect_man.top = 48;
    if (global->gameplay->player_nb == 3)
        global->gameplay->rect_man.top = 240;
    if (global->gameplay->player_nb == 4)
        global->gameplay->rect_man.top = 240;
}

void set_rect_right(global_t *global)
{
    if (global->gameplay->player_nb == 1)
        global->gameplay->rect_man.top = 96;
    if (global->gameplay->player_nb == 2)
        global->gameplay->rect_man.top = 96;
    if (global->gameplay->player_nb == 3)
        global->gameplay->rect_man.top = 288;
    if (global->gameplay->player_nb == 4)
        global->gameplay->rect_man.top = 288;
}

void set_rect_top(global_t *global)
{
    if (global->gameplay->player_nb == 1)
        global->gameplay->rect_man.top = 144;
    if (global->gameplay->player_nb == 2)
        global->gameplay->rect_man.top = 144;
    if (global->gameplay->player_nb == 3)
        global->gameplay->rect_man.top = 336;
    if (global->gameplay->player_nb == 4)
        global->gameplay->rect_man.top = 336;
}

void set_rect_down(global_t *global)
{
    if (global->gameplay->player_nb == 1)
        global->gameplay->rect_man.top = 0;
    if (global->gameplay->player_nb == 2)
        global->gameplay->rect_man.top = 0;
    if (global->gameplay->player_nb == 3)
        global->gameplay->rect_man.top = 192;
    if (global->gameplay->player_nb == 4)
        global->gameplay->rect_man.top = 192;
}