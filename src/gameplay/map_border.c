/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** map_border.c
*/

#include "rpg.h"
#include "my.h"

void check_position_left(gameplay_t *gameplay)
{
    if (gameplay->x <= 0) {
        gameplay->x = 0;
        sfSprite_setPosition(gameplay->sprite_man, (sfVector2f){gameplay->x,
        gameplay->y});
    }
}

void check_position_right(gameplay_t *gameplay)
{
    if (gameplay->x >= 6000 - 100) {
        gameplay->x = 6000 - 100;
        sfSprite_setPosition(gameplay->sprite_man, (sfVector2f){gameplay->x,
        gameplay->y});
    }
}

void check_position_top(gameplay_t *gameplay)
{
    if (gameplay->y <= 0) {
        gameplay->y = 0;
        sfSprite_setPosition(gameplay->sprite_man, (sfVector2f){gameplay->x,
        gameplay->y});
    }
}

void check_position_down(gameplay_t *gameplay)
{
    if (gameplay->y >= 6000 - 100) {
        gameplay->y = 6000 - 100;
        sfSprite_setPosition(gameplay->sprite_man, (sfVector2f){gameplay->x,
        gameplay->y});
    }
}