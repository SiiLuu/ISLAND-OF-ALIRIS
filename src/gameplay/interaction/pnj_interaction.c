/*
** EPITECH PROJECT, 2019
** rpg_2018
** File description:
** interaction with non playable player
*/

#include "my.h"
#include "rpg.h"

void different_text(global_t *global)
{
    display_text_desert(global);
    display_text_pech(global);
    display_text_bottom(global);
    display_text_quest(global);
    display_text_volc(global);
}

void check_interaction_4(global_t *global)
{
    if (global->gameplay->pnj->p_text_pech == 1 &&
        ((global->gameplay->x < 3630 || global->gameplay->x > 3800) ||
        (global->gameplay->y < 2090 || global->gameplay->y > 2200))) {
        global->gameplay->pnj->p_text_pech = 0;
        destroy_textures_quetes_pech(global);
        }
    if (global->gameplay->pnj->p_text_bot == 1 &&
        ((global->gameplay->x < 4200 || global->gameplay->x > 4350) ||
        (global->gameplay->y < 4450 || global->gameplay->y > 4650))) {
        global->gameplay->pnj->p_text_bot = 0;
        destroy_textures_quetes_bot(global);
        }
    check_interaction_pnj_volc(global);
}

void check_interaction_3(global_t *global)
{
    if (global->gameplay->pnj->p_text == 1 &&
        (global->gameplay->y < 4850 || global->gameplay->y > 5000)) {
        global->gameplay->pnj->p_text = 0;
        destroy_textures_quetes(global);
        }
    if (global->gameplay->pnj->p_text_d == 1 &&
        ((global->gameplay->y < 1850 || global->gameplay->y > 2050) ||
        (global->gameplay->x < 1700 || global->gameplay->x > 1900))) {
        global->gameplay->pnj->p_text_d = 0;
        destroy_textures_quetes_d(global);
        }
    if (global->gameplay->pnj->p_text_ed == 1 &&
        ((global->gameplay->y < 1990 || global->gameplay->y > 2200) ||
        (global->gameplay->x < 2600 || global->gameplay->x > 2950))) {
        global->gameplay->pnj->p_text_ed = 0;
        destroy_textures_quetes_ed(global);
        }
}

void check_interaction_2(global_t *global)
{
    if (sfKeyboard_isKeyPressed(sfKeyA) &&
        (global->gameplay->x > 2600 && global->gameplay->x < 2950) &&
        (global->gameplay->y > 1990 && global->gameplay->y < 2200)) {
        global->gameplay->pnj->p_text_ed = 1;
        }
    if (sfKeyboard_isKeyPressed(sfKeyA) &&
        (global->gameplay->x > 3630 && global->gameplay->x < 3800) &&
        (global->gameplay->y > 2090 && global->gameplay->y < 2200)) {
        global->gameplay->pnj->p_text_pech = 1;
        }
    if (sfKeyboard_isKeyPressed(sfKeyA) &&
        (global->gameplay->x > 4200 && global->gameplay->x < 4350) &&
        (global->gameplay->y > 4450 && global->gameplay->y < 4650)) {
        global->gameplay->pnj->p_text_bot = 1;
        }
    check_interaction_3(global);
    check_interaction_4(global);
}

void check_interaction(global_t *global)
{
    if (sfKeyboard_isKeyPressed(sfKeyA) &&
        (global->gameplay->x > 4900 && global->gameplay->x < 5100) &&
        (global->gameplay->y > 4800 && global->gameplay->y < 5000)) {
        global->gameplay->pnj->p_text = 1;
        global->gameplay->pnj->quest_complete = 1;
        }
    if (sfKeyboard_isKeyPressed(sfKeyA) &&
        (global->gameplay->x > 1700 && global->gameplay->x < 1900) &&
        (global->gameplay->y > 1850 && global->gameplay->y < 2050)) {
        global->gameplay->pnj->p_text_d = 1;
        global->gameplay->pnj->girl_quest = 1;
        }
    if (sfKeyboard_isKeyPressed(sfKeyA) &&
        (global->gameplay->x > 1700 && global->gameplay->x < 1810) &&
        (global->gameplay->y > 1950 && global->gameplay->y < 2100) &&
        (global->gameplay->pnj->quest_complete == 1))
        global->gameplay->pnj->girl_quest = 0;
    check_interaction_2(global);
}