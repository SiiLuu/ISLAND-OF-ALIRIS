/*
** EPITECH PROJECT, 2019
** rect_in_movement.c
** File description:
** set the rect of the player in movement
*/

#include "my.h"
#include "rpg.h"

void move_rect(gameplay_t *gameplay)
{
    if (gameplay->player_nb == 1)
        move_rect_p1(gameplay);
    if (gameplay->player_nb == 2)
        move_rect_p2(gameplay);
    if (gameplay->player_nb == 3)
        move_rect_p3(gameplay);
    if (gameplay->player_nb == 4)
        move_rect_p4(gameplay);

}

void set_rect_moving(gameplay_t *gameplay)
{
    if (gameplay->player_nb == 1)
        move_rect_p1(gameplay);
    if (gameplay->player_nb == 2)
        move_rect_p2(gameplay);
    if (gameplay->player_nb == 3)
        move_rect_p3(gameplay);
    if (gameplay->player_nb == 4)
        move_rect_p4(gameplay);
}

void set_rect_runing(gameplay_t * gameplay)
{
    if (gameplay->player_nb == 1)
        move_rect_running(gameplay);
    if (gameplay->player_nb == 2)
        move_rect_running_p2(gameplay);
    if (gameplay->player_nb == 3)
        move_rect_running_p3(gameplay);
    if (gameplay->player_nb == 4)
        move_rect_running_p4(gameplay);
}