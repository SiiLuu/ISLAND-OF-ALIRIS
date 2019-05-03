/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** my_rpg, change_rect.c
*/

#include "my.h"
#include "rpg.h"

void change_rect_fight(global_t *global)
{
    if (global->gameplay->player_nb == 1) {
        if (global->fight->rect.left >= 528)
            global->fight->rect.left = 432;
        global->fight->rect.left += 48;
    }
    if (global->gameplay->player_nb == 2) {
        if (global->fight->rect.left >= 240)
            global->fight->rect.left = 144;
        global->fight->rect.left += 48;
    }
    if (global->gameplay->player_nb == 3) {
        if (global->fight->rect.left >= 92)
            global->fight->rect.left = 0;
        global->fight->rect.left += 48;
    }
    if (global->gameplay->player_nb == 4) {
        if (global->fight->rect.left >= 380)
            global->fight->rect.left = 288;
        global->fight->rect.left += 48;
    }
}