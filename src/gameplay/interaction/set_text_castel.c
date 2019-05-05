/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** set text position in the castel
*/

#include "rpg.h"
#include "my.h"

void set_knight_1_text(global_t *global)
{
    sfText_setFont(global->gameplay->pnj->text_knight_1,
    global->gameplay->pnj->font);
    sfText_setCharacterSize(global->gameplay->pnj->text_knight_1, 35);
    sfText_setColor(global->gameplay->pnj->text_knight_1, sfWhite);
    sfText_setPosition(global->gameplay->pnj->text_knight_1,
    (sfVector2f){1750, 2600 + 405});
}

void set_knight_2_text(global_t *global)
{
    sfText_setFont(global->gameplay->pnj->text_knight_2,
    global->gameplay->pnj->font);
    sfText_setCharacterSize(global->gameplay->pnj->text_knight_2, 35);
    sfText_setColor(global->gameplay->pnj->text_knight_2, sfWhite);
    sfText_setPosition(global->gameplay->pnj->text_knight_2,
    (sfVector2f){2010, 2600 + 405});
}

void set_princess_text(global_t *global)
{
    sfText_setFont(global->gameplay->pnj->text_princess,
    global->gameplay->pnj->font);
    sfText_setCharacterSize(global->gameplay->pnj->text_princess, 35);
    sfText_setColor(global->gameplay->pnj->text_princess, sfWhite);
    sfText_setPosition(global->gameplay->pnj->text_princess,
    (sfVector2f){2160, global->gameplay->y + 405});
}