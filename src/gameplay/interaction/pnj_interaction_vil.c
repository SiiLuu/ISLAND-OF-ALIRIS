/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** pnj interaction
*/

#include "my.h"
#include "rpg.h"

void destroy_textures_papy_vil(global_t *global)
{
    sfText_destroy(global->gameplay->pnj->text_papy);
    sfSprite_destroy(global->gameplay->pnj->s_text_box);
    sfTexture_destroy(global->gameplay->pnj->text_box);
}

void set_vil_papy_text(global_t *global)
{
    sfText_setFont(global->gameplay->pnj->text_papy,
    global->gameplay->pnj->font);
    sfText_setCharacterSize(global->gameplay->pnj->text_papy, 35);
    sfText_setColor(global->gameplay->pnj->text_papy, sfWhite);
    sfText_setPosition(global->gameplay->pnj->text_papy,
    (sfVector2f){610, global->gameplay->y + 405});
}

void check_interaction_village(global_t *global)
{
    if (sfKeyboard_isKeyPressed(sfKeyA) &&
        (global->gameplay->x > 500 && global->gameplay->x < 710) &&
        (global->gameplay->y > 590 && global->gameplay->y < 750)) {
        global->gameplay->pnj->vil_papy = 1;
        }
    if (global->gameplay->pnj->vil_papy == 1 &&
        ((global->gameplay->x < 500 || global->gameplay->x > 710) ||
        (global->gameplay->y < 590 || global->gameplay->y > 750))) {
        global->gameplay->pnj->vil_papy = 0;
        global->gameplay->pnj->next_text = 0;
        destroy_textures_papy_vil(global);
        }
}

void set_text_papy(global_t *global)
{
    sfText_setString(global->gameplay->pnj->text_papy,
    "I come every day to pay tribute to these men\
    \nwho are beaten to try to restore calm on\
    \nthe island of aliris.\n\t\t\t\t\t\t\t\t\t\t\t\t\t(Press tab)");
}

void display_text_vill(global_t *global)
{
    if (global->gameplay->pnj->vil_papy == 1) {
        set_text_box(global);
        global->gameplay->pnj->text_papy = sfText_create();
        if (sfKeyboard_isKeyPressed(sfKeyTab))
            global->gameplay->pnj->next_text = 1;
        if (global->gameplay->pnj->next_text == 1) {
            sfText_setString(global->gameplay->pnj->text_papy,
            "They all lost their lives in battle against the\
            \nhorrible monsters which occupe the island\
            \nI trust in you ! We need help");
        }
        else
            set_text_papy(global);
        set_vil_papy_text(global);
        sfSprite_setPosition(global->gameplay->pnj->s_text_box,
        (sfVector2f){550, global->gameplay->y + 380});
        sfRenderWindow_drawSprite(global->window,
        global->gameplay->pnj->s_text_box, NULL);
        sfRenderWindow_drawText(global->window,
        global->gameplay->pnj->text_papy, NULL);
    }
}