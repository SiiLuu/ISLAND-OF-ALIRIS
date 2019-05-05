/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** map_border.c
*/

#include "rpg.h"
#include "my.h"

void check_position_left(global_t *global)
{
    if (global->gameplay->x <= 0) {
        global->gameplay->x = 0;
        sfSprite_setPosition(global->gameplay->sprite_man,
        (sfVector2f){global->gameplay->x,
        global->gameplay->y});
    }
}

void check_position_right(global_t *global)
{
    if (global->gameplay->x >= global->gameplay->width - 100) {
        global->gameplay->x = global->gameplay->width - 100;
        sfSprite_setPosition(global->gameplay->sprite_man,
        (sfVector2f){global->gameplay->x,
        global->gameplay->y});
    }
}

void check_position_top(global_t *global)
{
    if (global->gameplay->y <= 0) {
        global->gameplay->y = 0;
        sfSprite_setPosition(global->gameplay->sprite_man,
        (sfVector2f){global->gameplay->x,
        global->gameplay->y});
    }
}

void check_position_down(global_t *global)
{
    if (global->gameplay->y >= global->gameplay->lenght - 100) {
        global->gameplay->y = global->gameplay->lenght - 100;
        sfSprite_setPosition(global->gameplay->sprite_man,
        (sfVector2f){global->gameplay->x,
        global->gameplay->y});
    }
}