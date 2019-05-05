/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** text in the village
*/

#include "rpg.h"
#include "my.h"

void set_vil_papy_text(global_t *global)
{
    sfText_setFont(global->gameplay->pnj->text_papy,
    global->gameplay->pnj->font);
    sfText_setCharacterSize(global->gameplay->pnj->text_papy, 35);
    sfText_setColor(global->gameplay->pnj->text_papy, sfWhite);
    sfText_setPosition(global->gameplay->pnj->text_papy,
    (sfVector2f){610, global->gameplay->y + 405});
}

void set_vil_garden_text(global_t *global)
{
    sfText_setFont(global->gameplay->pnj->text_pnj_garden,
    global->gameplay->pnj->font);
    sfText_setCharacterSize(global->gameplay->pnj->text_pnj_garden, 35);
    sfText_setColor(global->gameplay->pnj->text_pnj_garden, sfWhite);
    sfText_setPosition(global->gameplay->pnj->text_pnj_garden,
    (sfVector2f){2460, global->gameplay->y + 405});
}

void set_garden_text(global_t *global)
{
    if (global->gameplay->pnj->p_garden == 1) {
        set_text_box(global);
        global->gameplay->pnj->text_pnj_garden = sfText_create();
        sfText_setString(global->gameplay->pnj->text_pnj_garden,
        "My garden is beatiful, isn't it ?");
        set_vil_garden_text(global);
        sfSprite_setPosition(global->gameplay->pnj->s_text_box,
        (sfVector2f){2400, global->gameplay->y + 380});
        sfRenderWindow_drawSprite(global->window,
        global->gameplay->pnj->s_text_box, NULL);
        sfRenderWindow_drawText(global->window,
        global->gameplay->pnj->text_pnj_garden, NULL);
    }
}

void set_text_papy(global_t *global)
{
    sfText_setString(global->gameplay->pnj->text_papy,
    "I come every day to pay tribute to these men\
    \nwho are beaten to try to restore calm on\
    \nthe island of aliris.\n\t\t\t\t\t\t\t\t\t\t\t\t\t(Press tab)");
}

void set_text_papy_1(global_t *global)
{
    sfText_setString(global->gameplay->pnj->text_papy,
    "They all lost their lives in battle against the\
    \nhorrible monsters which occupe the island\
    \nI trust in you ! We need help");
}