/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** rect for the pnj
*/

#include "my.h"
#include "rpg.h"

void int_pnj_rect_castel(global_t *global)
{
    global->gameplay->pnj->rect_princess.height = 48;
    global->gameplay->pnj->rect_princess.width = 48;
    global->gameplay->pnj->rect_princess.left = 480;
    global->gameplay->pnj->rect_princess.top = 0;
    global->gameplay->pnj->rect_pnj_garden.height = 48;
    global->gameplay->pnj->rect_pnj_garden.width = 48;
    global->gameplay->pnj->rect_pnj_garden.left = 192;
    global->gameplay->pnj->rect_pnj_garden.top = 192;
}

void init_pnj_rect(global_t *global)
{
    global->gameplay->pnj->rect_pnj_volc.height = 48;
    global->gameplay->pnj->rect_pnj_volc.width = 48;
    global->gameplay->pnj->rect_pnj_volc.left = 48;
    global->gameplay->pnj->rect_pnj_volc.top = 240;
    global->gameplay->pnj->rect_chest_1.height = 48;
    global->gameplay->pnj->rect_chest_1.width = 48;
    global->gameplay->pnj->rect_chest_1.left = 48;
    global->gameplay->pnj->rect_chest_1.top = 0;
    global->gameplay->boss->rect_volc_boss.height = 96;
    global->gameplay->boss->rect_volc_boss.width = 96;
    global->gameplay->boss->rect_volc_boss.left = 96;
    global->gameplay->boss->rect_volc_boss.top = 192;
    global->gameplay->pnj->rect_knight_1.height = 48;
    global->gameplay->pnj->rect_knight_1.width = 48;
    global->gameplay->pnj->rect_knight_1.left = 336;
    global->gameplay->pnj->rect_knight_1.top = 192;
    global->gameplay->pnj->rect_knight_2.height = 48;
    global->gameplay->pnj->rect_knight_2.width = 48;
    global->gameplay->pnj->rect_knight_2.left = 480;
    global->gameplay->pnj->rect_knight_2.top = 192;
    int_pnj_rect_castel(global);
}

void init_rect_boss(global_t *global)
{
    global->gameplay->boss->rect_final_boss.height = 120;
    global->gameplay->boss->rect_final_boss.width = 120;
    global->gameplay->boss->rect_final_boss.left = 120;
    global->gameplay->boss->rect_final_boss.top = 240;
    global->gameplay->boss->rect_winter_boss.height = 120;
    global->gameplay->boss->rect_winter_boss.width = 120;
    global->gameplay->boss->rect_winter_boss.left = 120;
    global->gameplay->boss->rect_winter_boss.top = 120;
    global->gameplay->boss->rect_desert_boss.height = 120;
    global->gameplay->boss->rect_desert_boss.width = 120;
    global->gameplay->boss->rect_desert_boss.left = 120;
    global->gameplay->boss->rect_desert_boss.top = 0;
    global->gameplay->boss->rect_hl_boss.height = 120;
    global->gameplay->boss->rect_hl_boss.width = 120;
    global->gameplay->boss->rect_hl_boss.left = 120;
    global->gameplay->boss->rect_hl_boss.top = 360;
    global->gameplay->pnj->rect_vil_old.height = 48;
    global->gameplay->pnj->rect_vil_old.width = 48;
    global->gameplay->pnj->rect_vil_old.left = 336;
    global->gameplay->pnj->rect_vil_old.top = 192;
    init_pnj_rect(global);
}

void init_rect_pnj(global_t *global)
{
    global->gameplay->pnj->rect_pnj_1.height = 48;
    global->gameplay->pnj->rect_pnj_1.width = 48;
    global->gameplay->pnj->rect_pnj_1.left = 480;
    global->gameplay->pnj->rect_pnj_1.top = 144;
    global->gameplay->pnj->rect_pnj_d.height = 48;
    global->gameplay->pnj->rect_pnj_d.width = 48;
    global->gameplay->pnj->rect_pnj_d.left = 336;
    global->gameplay->pnj->rect_pnj_d.top = 192;
    global->gameplay->pnj->rect_pnj_ed.height = 48;
    global->gameplay->pnj->rect_pnj_ed.width = 48;
    global->gameplay->pnj->rect_pnj_ed.left = 48;
    global->gameplay->pnj->rect_pnj_ed.top = 96;
    global->gameplay->pnj->rect_pnj_pech.height = 48;
    global->gameplay->pnj->rect_pnj_pech.width = 48;
    global->gameplay->pnj->rect_pnj_pech.left = 48;
    global->gameplay->pnj->rect_pnj_pech.top = 192;
    global->gameplay->pnj->rect_pnj_bot.height = 48;
    global->gameplay->pnj->rect_pnj_bot.width = 48;
    global->gameplay->pnj->rect_pnj_bot.left = 480;
    global->gameplay->pnj->rect_pnj_bot.top = 240;
    init_rect_boss(global);
}