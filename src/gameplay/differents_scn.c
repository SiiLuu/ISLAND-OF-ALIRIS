/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** chose the scene
*/

#include "my.h"
#include "rpg.h"

void scn_1(global_t *global)
{
    if (global->gameplay->pnj->status->girl_quest == 1)
        sfRenderWindow_drawSprite(global->window,
        global->gameplay->pnj->sprite_pnj_1, NULL);
    draw_sprites_scn_1(global);
    switch_in_fight(global);
    display_text(global);
}

void scn_10(global_t *global)
{
    sfSprite_setTextureRect(global->gameplay->pnj->sp_chest_1,
    global->gameplay->pnj->rect_chest_1);
    sfRenderWindow_drawSprite(global->window,
    global->gameplay->pnj->sp_chest_1, NULL);
    display_text_fcp(global);

}

void scn_11(global_t *global)
{
    sfRenderWindow_drawSprite(global->window,
    global->gameplay->pnj->sp_vil_old, NULL);
    sfRenderWindow_drawSprite(global->window,
    global->gameplay->pnj->sp_pnj_garden, NULL);
    display_text_vill(global);
}

void scn_12(global_t *global)
{
    sfRenderWindow_drawSprite(global->window,
    global->gameplay->pnj->sp_knight_1, NULL);
    sfRenderWindow_drawSprite(global->window,
    global->gameplay->pnj->sp_knight_2, NULL);
    sfRenderWindow_drawSprite(global->window,
    global->gameplay->pnj->sp_princess, NULL);
    display_text_castel(global);
}

void scn_13(global_t *global)
{
    fight_in_volc(global);
    sfRenderWindow_drawSprite(global->window,
    global->gameplay->boss->sp_volc_boss, NULL);
}