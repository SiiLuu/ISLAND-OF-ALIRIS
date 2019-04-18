/*
** EPITECH PROJECT, 2019
** 
** File description:
** 
*/

#include "my.h"
#include "rpg.h"

void set_my_rect_p1(gameplay_t *gameplay)
{
    gameplay->rect_man.height = 48;
    gameplay->rect_man.width = 48;
    gameplay->rect_man.left = 432;
    gameplay->rect_man.top = 0;
}

void set_my_rect_p2(gameplay_t *gameplay)
{
    gameplay->rect_man.height = 48;
    gameplay->rect_man.width = 48;
    gameplay->rect_man.left = 144;
    gameplay->rect_man.top = 0;
}

void set_my_rect_p3(gameplay_t *gameplay)
{
    gameplay->rect_man.height = 48;
    gameplay->rect_man.width = 48;
    gameplay->rect_man.left = 0;
    gameplay->rect_man.top = 192;
}

void set_my_rect_p4(gameplay_t *gameplay)
{
    gameplay->rect_man.height = 48;
    gameplay->rect_man.width = 48;
    gameplay->rect_man.left = 288;
    gameplay->rect_man.top = 192;
}