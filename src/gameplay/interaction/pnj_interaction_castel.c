/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** interaction in the castel
*/

#include "my.h"
#include "rpg.h"

void interaction_princess(global_t *global)
{
    if (sfKeyboard_isKeyPressed(sfKeyA) &&
        (global->gameplay->x > 2150 && global->gameplay->x < 2300) &&
        (global->gameplay->y > 1399 && global->gameplay->y < 1520)) {
        global->gameplay->pnj->status->p_princess = 1;
        }
    if (global->gameplay->pnj->status->p_princess == 1 &&
        ((global->gameplay->x < 2150 || global->gameplay->x > 2300) ||
        (global->gameplay->y < 1399 || global->gameplay->y > 1520))) {
        global->gameplay->pnj->status->p_princess = 0;
        destroy_textures_princess(global);
        }
}

void interaction_knight(global_t *global)
{
    if (sfKeyboard_isKeyPressed(sfKeyA) &&
        (global->gameplay->x > 2050 && global->gameplay->x < 2200) &&
        (global->gameplay->y > 2650 && global->gameplay->y < 2850)) {
        global->gameplay->pnj->status->p_knight_2 = 1;
        }
    if (global->gameplay->pnj->status->p_knight_2 == 1 &&
        ((global->gameplay->x < 2050 || global->gameplay->x > 2200) ||
        (global->gameplay->y < 2650 || global->gameplay->y > 2850))) {
        global->gameplay->pnj->status->p_knight_2 = 0;
        destroy_textures_knight_2(global);
        }
}

void check_interaction_castel(global_t *global)
{
    if (sfKeyboard_isKeyPressed(sfKeyA) &&
        (global->gameplay->x > 1700 && global->gameplay->x < 1850) &&
        (global->gameplay->y > 2650 && global->gameplay->y < 2850)) {
        global->gameplay->pnj->status->p_knight_1 = 1;
        }
    if (global->gameplay->pnj->status->p_knight_1 == 1 &&
        ((global->gameplay->x < 1700 || global->gameplay->x > 1850) ||
        (global->gameplay->y < 2650 || global->gameplay->y > 2850))) {
        global->gameplay->pnj->status->p_knight_1 = 0;
        destroy_textures_knight_1(global);
        }
    interaction_knight(global);
    interaction_princess(global);
}