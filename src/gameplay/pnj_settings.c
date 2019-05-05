/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** function to configure my pnj
*/

#include "my.h"
#include "rpg.h"

void pnj_textures(global_t *global)
{
    sfSprite_setTexture(global->gameplay->pnj->sp_knight_2,
    global->gameplay->pnj->knight_2, sfTrue);
    sfSprite_setTexture(global->gameplay->pnj->sp_princess,
    global->gameplay->pnj->princess, sfTrue);
    sfSprite_setTexture(global->gameplay->pnj->sp_pnj_garden,
    global->gameplay->pnj->pnj_garden, sfTrue);
    sfSprite_setTexture(global->gameplay->boss->sp_final_boss,
    global->gameplay->boss->final_boss, sfTrue);
    sfSprite_setTexture(global->gameplay->boss->sp_volc_boss,
    global->gameplay->boss->volc_boss, sfTrue);
    sfSprite_setTexture(global->gameplay->boss->sp_winter_boss,
    global->gameplay->boss->winter_boss, sfTrue);
    sfSprite_setTexture(global->gameplay->boss->sp_desert_boss,
    global->gameplay->boss->desert_boss, sfTrue);
    sfSprite_setTexture(global->gameplay->boss->sp_hl_boss,
    global->gameplay->boss->hl_boss, sfTrue);
    sfSprite_setTexture(global->gameplay->sprite_backg,
    global->gameplay->backg, sfTrue);
    sfSprite_setTexture(global->gameplay->sprite_man,
    global->gameplay->man, sfTrue);
}

void set_textures(global_t *global)
{
    sfSprite_setTexture(global->gameplay->pnj->sprite_pnj_ed,
    global->gameplay->pnj->pnj_ed, sfTrue);
    sfSprite_setTexture(global->gameplay->pnj->sprite_pnj_d,
    global->gameplay->pnj->pnj_d, sfTrue);
    sfSprite_setTexture(global->gameplay->pnj->sprite_pnj_1,
    global->gameplay->pnj->pnj_1, sfTrue);
    sfSprite_setTexture(global->gameplay->pnj->sprite_pnj_pech,
    global->gameplay->pnj->pnj_pech, sfTrue);
    sfSprite_setTexture(global->gameplay->pnj->sprite_pnj_bot,
    global->gameplay->pnj->pnj_bot, sfTrue);
    sfSprite_setTexture(global->gameplay->pnj->sp_pnj_volc,
    global->gameplay->pnj->pnj_volc, sfTrue);
    sfSprite_setTexture(global->gameplay->pnj->sp_vil_old,
    global->gameplay->pnj->vil_old, sfTrue);
    sfSprite_setTexture(global->gameplay->pnj->sp_chest_1,
    global->gameplay->pnj->chest_1, sfTrue);
    sfSprite_setTexture(global->gameplay->pnj->sp_knight_1,
    global->gameplay->pnj->knight_1, sfTrue);
    pnj_textures(global);
}

void set_pnj_scale(global_t *global)
{
    sfSprite_setScale(global->gameplay->pnj->sprite_pnj_d,
    (sfVector2f){2.08333, 2.08333});
    sfSprite_setScale(global->gameplay->pnj->sprite_pnj_1,
    (sfVector2f){2.08333, 2.08333});
    sfSprite_setScale(global->gameplay->pnj->sprite_pnj_ed,
    (sfVector2f){2.08333, 2.08333});
    sfSprite_setScale(global->gameplay->pnj->sprite_pnj_pech,
    (sfVector2f){2.08333, 2.08333});
    sfSprite_setScale(global->gameplay->pnj->sprite_pnj_bot,
    (sfVector2f){2.08333, 2.08333});
    sfSprite_setScale(global->gameplay->pnj->sp_vil_old,
    (sfVector2f){2.08333, 2.08333});
    sfSprite_setScale(global->gameplay->pnj->sp_pnj_volc,
    (sfVector2f){2.08333, 2.08333});
    sfSprite_setScale(global->gameplay->pnj->sp_chest_1,
    (sfVector2f){2.08333, 2.08333});
    sfSprite_setScale(global->gameplay->pnj->sp_knight_1,
    (sfVector2f){2.08333, 2.08333});
    set_pnj_scale_castle(global);
}

void apply_rect_pnj(global_t *global)
{
    sfSprite_setTextureRect(global->gameplay->pnj->sprite_pnj_d,
    global->gameplay->pnj->rect_pnj_d);
    sfSprite_setTextureRect(global->gameplay->pnj->sprite_pnj_1,
    global->gameplay->pnj->rect_pnj_1);
    sfSprite_setTextureRect(global->gameplay->pnj->sprite_pnj_ed,
    global->gameplay->pnj->rect_pnj_ed);
    sfSprite_setTextureRect(global->gameplay->pnj->sprite_pnj_pech,
    global->gameplay->pnj->rect_pnj_pech);
    sfSprite_setTextureRect(global->gameplay->pnj->sprite_pnj_bot,
    global->gameplay->pnj->rect_pnj_bot);
    sfSprite_setTextureRect(global->gameplay->pnj->sp_vil_old,
    global->gameplay->pnj->rect_vil_old);
    sfSprite_setTextureRect(global->gameplay->pnj->sp_pnj_volc,
    global->gameplay->pnj->rect_pnj_volc);
    sfSprite_setTextureRect(global->gameplay->pnj->sp_knight_1,
    global->gameplay->pnj->rect_knight_1);
    sfSprite_setTextureRect(global->gameplay->pnj->sp_knight_2,
    global->gameplay->pnj->rect_knight_2);
    sfSprite_setTextureRect(global->gameplay->pnj->sp_princess,
    global->gameplay->pnj->rect_princess);
}

void set_pnj_position(global_t *global)
{
    sfSprite_setPosition(global->gameplay->pnj->sprite_pnj_1,
    (sfVector2f){5010, 5000});
    sfSprite_setPosition(global->gameplay->pnj->sprite_pnj_d,
    (sfVector2f){1790, 1900});
    sfSprite_setPosition(global->gameplay->pnj->sprite_pnj_ed,
    (sfVector2f){2790, 2095});
    sfSprite_setPosition(global->gameplay->pnj->sprite_pnj_pech,
    (sfVector2f){3710, 2000});
    sfSprite_setPosition(global->gameplay->pnj->sprite_pnj_bot,
    (sfVector2f){4310, 4600});
    sfSprite_setPosition(global->gameplay->pnj->sp_vil_old,
    (sfVector2f){600, 600});
    sfSprite_setPosition(global->gameplay->pnj->sp_pnj_volc,
    (sfVector2f){1500, 1000});
    sfSprite_setPosition(global->gameplay->pnj->sp_chest_1,
    (sfVector2f){1305, 600});
    sfSprite_setPosition(global->gameplay->pnj->sp_knight_1,
    (sfVector2f){1800, 2700});
    set_pnj_position_wm(global);
}