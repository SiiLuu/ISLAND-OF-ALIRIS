/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** text settings
*/

#include "my.h"
#include "rpg.h"

void set_winter_text(global_t *global)
{
    sfText_setFont(global->gameplay->pnj->text, global->gameplay->pnj->font);
    sfText_setCharacterSize(global->gameplay->pnj->text, 35);
    sfText_setColor(global->gameplay->pnj->text, sfWhite);
    sfText_setPosition(global->gameplay->pnj->text,
    (sfVector2f){4760, 4900 + 400});
}

void set_desert_text(global_t *global)
{
    sfText_setFont(global->gameplay->pnj->text_d, global->gameplay->pnj->font);
    sfText_setCharacterSize(global->gameplay->pnj->text_d, 35);
    sfText_setColor(global->gameplay->pnj->text_d, sfWhite);
    sfText_setPosition(global->gameplay->pnj->text_d,
    (sfVector2f){1700, 1900 + 500});
}

void set_edesert_text(global_t *global)
{
    sfText_setFont(global->gameplay->pnj->text_ed,
    global->gameplay->pnj->font);
    sfText_setCharacterSize(global->gameplay->pnj->text_ed, 35);
    sfText_setColor(global->gameplay->pnj->text_ed, sfWhite);
    sfText_setPosition(global->gameplay->pnj->text_ed,
    (sfVector2f){2680, 1990 + 500});
}

void set_pech_text(global_t *global)
{
    sfText_setFont(global->gameplay->pnj->text_pech,
    global->gameplay->pnj->font);
    sfText_setCharacterSize(global->gameplay->pnj->text_pech, 35);
    sfText_setColor(global->gameplay->pnj->text_pech, sfWhite);
    sfText_setPosition(global->gameplay->pnj->text_pech,
    (sfVector2f){3660, 2000 + 500});
}

void set_bot_text(global_t *global)
{
    sfText_setFont(global->gameplay->pnj->text_bot,
    global->gameplay->pnj->font);
    sfText_setCharacterSize(global->gameplay->pnj->text_bot, 35);
    sfText_setColor(global->gameplay->pnj->text_bot, sfWhite);
    sfText_setPosition(global->gameplay->pnj->text_bot,
    (sfVector2f){4210, 4600 + 390});
}