/*
** EPITECH PROJECT, 2019
** 
** File description:
** 
*/

#include "my.h"
#include "rpg.h"

void set_my_rect_p1(global_t *global)
{
    global->gameplay->rect_man.height = 48;
    global->gameplay->rect_man.width = 48;
    global->gameplay->rect_man.left = 432;
    global->gameplay->rect_man.top = 0;
}

void set_my_rect_p2(global_t *global)
{
    global->gameplay->rect_man.height = 48;
    global->gameplay->rect_man.width = 48;
    global->gameplay->rect_man.left = 144;
    global->gameplay->rect_man.top = 0;
}

void set_my_rect_p3(global_t *global)
{
    global->gameplay->rect_man.height = 48;
    global->gameplay->rect_man.width = 48;
    global->gameplay->rect_man.left = 0;
    global->gameplay->rect_man.top = 192;
}

void set_my_rect_p4(global_t *global)
{
    global->gameplay->rect_man.height = 48;
    global->gameplay->rect_man.width = 48;
    global->gameplay->rect_man.left = 288;
    global->gameplay->rect_man.top = 192;
}