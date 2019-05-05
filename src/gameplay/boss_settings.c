/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** function to set the boss
*/

#include "my.h"
#include "rpg.h"

void set_position_boss(global_t *global)
{
    sfSprite_setTextureRect(global->gameplay->boss->sp_final_boss,
    global->gameplay->boss->rect_final_boss);
    sfSprite_setPosition(global->gameplay->boss->sp_final_boss,
    (sfVector2f){2310, 490});
    sfSprite_setScale(global->gameplay->boss->sp_final_boss,
    (sfVector2f){1.5, 1.5});
    sfSprite_setTextureRect(global->gameplay->boss->sp_winter_boss,
    global->gameplay->boss->rect_winter_boss);
    sfSprite_setPosition(global->gameplay->boss->sp_winter_boss,
    (sfVector2f){5350, 3010});
    sfSprite_setScale(global->gameplay->boss->sp_winter_boss,
    (sfVector2f){1.5, 1.5});
    sfSprite_setTextureRect(global->gameplay->boss->sp_desert_boss,
    global->gameplay->boss->rect_desert_boss);
    sfSprite_setPosition(global->gameplay->boss->sp_desert_boss,
    (sfVector2f){500, 3235});
    sfSprite_setScale(global->gameplay->boss->sp_desert_boss,
    (sfVector2f){1.5, 1.5});
    set_position_boss_volc(global);
}

void set_pnj_position_wm(global_t *global)
{
    sfSprite_setPosition(global->gameplay->pnj->sp_knight_2,
    (sfVector2f){2100, 2700});
    sfSprite_setPosition(global->gameplay->pnj->sp_princess,
    (sfVector2f){2200, 1400});
    sfSprite_setPosition(global->gameplay->pnj->sp_pnj_garden,
    (sfVector2f){2500, 900});
}

void set_pnj_scale_castle(global_t *global)
{
    sfSprite_setScale(global->gameplay->pnj->sp_knight_2,
    (sfVector2f){2.08333, 2.08333});
    sfSprite_setScale(global->gameplay->pnj->sp_princess,
    (sfVector2f){2.08333, 2.08333});
    sfSprite_setScale(global->gameplay->pnj->sp_pnj_garden,
    (sfVector2f){2.08333, 2.08333});
}

void set_position(global_t *global)
{
    init_rect_pnj(global);
    apply_rect_pnj(global);
    set_pnj_position(global);
    set_pnj_scale(global);
    sfSprite_setTextureRect(global->gameplay->pnj->sp_pnj_garden,
    global->gameplay->pnj->rect_pnj_garden);
    sfSprite_setPosition(global->gameplay->sprite_man,
    (sfVector2f){global->gameplay->x, global->gameplay->y});
    sfSprite_setScale(global->gameplay->sprite_man,
    (sfVector2f){2.08333, 2.08333});
    set_position_boss(global);
}