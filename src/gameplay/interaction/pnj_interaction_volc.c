/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** interaction with the pnj in the volc
*/

#include "my.h"
#include "rpg.h"

void set_volc_text(global_t *global)
{
    sfText_setFont(global->gameplay->pnj->text_volc,
    global->gameplay->pnj->font);
    sfText_setCharacterSize(global->gameplay->pnj->text_volc, 35);
    sfText_setColor(global->gameplay->pnj->text_volc, sfWhite);
    sfText_setPosition(global->gameplay->pnj->text_volc,
    (sfVector2f){1370, global->gameplay->y + 410});
}

void check_interaction_pnj_volc(global_t *global)
{
    if (sfKeyboard_isKeyPressed(sfKeyA) &&
        (global->gameplay->x > 1400 && global->gameplay->x < 1550) &&
        (global->gameplay->y > 890 && global->gameplay->y < 1150)) {
        global->gameplay->pnj->q_volc = 1;
        }
    if (global->gameplay->pnj->q_volc == 1 &&
        ((global->gameplay->x < 1400 || global->gameplay->x > 1550) ||
        (global->gameplay->y < 890 || global->gameplay->y > 1150))) {
        global->gameplay->pnj->q_volc = 0;
        destroy_textures_quetes_volc(global);
        }
}