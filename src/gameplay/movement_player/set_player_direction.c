/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** player_direction
*/

#include "my.h"
#include "rpg.h"


void set_rect_left(gameplay_t *gameplay)
{
    if (gameplay->player_nb == 1)
        gameplay->rect_man.top = 48;
    if (gameplay->player_nb == 2)
        gameplay->rect_man.top = 48;
    if (gameplay->player_nb == 3)
        gameplay->rect_man.top = 240;
    if (gameplay->player_nb == 4)
        gameplay->rect_man.top = 240;
}

void set_rect_right(gameplay_t *gameplay)
{
    if (gameplay->player_nb == 1)
        gameplay->rect_man.top = 96;
    if (gameplay->player_nb == 2)
        gameplay->rect_man.top = 96;
    if (gameplay->player_nb == 3)
        gameplay->rect_man.top = 288;
    if (gameplay->player_nb == 4)
        gameplay->rect_man.top = 288;
}

void set_rect_top(gameplay_t *gameplay)
{
    if (gameplay->player_nb == 1)
        gameplay->rect_man.top = 144;
    if (gameplay->player_nb == 2)
        gameplay->rect_man.top = 144;
    if (gameplay->player_nb == 3)
        gameplay->rect_man.top = 336;
    if (gameplay->player_nb == 4)
        gameplay->rect_man.top = 336;
}

void set_rect_down(gameplay_t *gameplay)
{
    if (gameplay->player_nb == 1)
        gameplay->rect_man.top = 0;
    if (gameplay->player_nb == 2)
        gameplay->rect_man.top = 0;
    if (gameplay->player_nb == 3)
        gameplay->rect_man.top = 192;
    if (gameplay->player_nb == 4)
        gameplay->rect_man.top = 192;
}