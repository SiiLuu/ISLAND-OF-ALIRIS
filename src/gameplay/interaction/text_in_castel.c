/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** differents text in the castel
*/

#include "my.h"
#include "rpg.h"

void display_text_knight(global_t *global)
{
    if (global->gameplay->pnj->status->p_knight_2 == 1) {
        set_text_box(global);
        global->gameplay->pnj->text_knight_2 = sfText_create();
        sfText_setString(global->gameplay->pnj->text_knight_2,
        "I hope one day a powerfull knight will save\
        \nus from this hostile monsters...");
        set_knight_2_text(global);
        sfSprite_setPosition(global->gameplay->pnj->s_text_box,
        (sfVector2f){1950, 2600 + 380});
        sfRenderWindow_drawSprite(global->window,
        global->gameplay->pnj->s_text_box, NULL);
        sfRenderWindow_drawText(global->window,
        global->gameplay->pnj->text_knight_2, NULL);
    }
}

void display_text_princess(global_t *global)
{
    if (global->gameplay->pnj->status->p_princess == 1) {
        set_text_box(global);
        global->gameplay->pnj->text_princess = sfText_create();
        sfText_setString(global->gameplay->pnj->text_princess,
        "My dad, the king promise a big reward to\
        \nwhoever defeats the boss who stole his gold !");
        set_princess_text(global);
        sfSprite_setPosition(global->gameplay->pnj->s_text_box,
        (sfVector2f){2100, global->gameplay->y + 380});
        sfRenderWindow_drawSprite(global->window,
        global->gameplay->pnj->s_text_box, NULL);
        sfRenderWindow_drawText(global->window,
        global->gameplay->pnj->text_princess, NULL);
    }
}

void display_text_castel(global_t *global)
{
    if (global->gameplay->pnj->status->p_knight_1 == 1) {
        set_text_box(global);
        global->gameplay->pnj->text_knight_1 = sfText_create();
        sfText_setString(global->gameplay->pnj->text_knight_1,
        "Welcome in the castel, we're the most protected\
        \ncity in the aliris island");
        set_knight_1_text(global);
        sfSprite_setPosition(global->gameplay->pnj->s_text_box,
        (sfVector2f){1700, 2600 + 380});
        sfRenderWindow_drawSprite(global->window,
        global->gameplay->pnj->s_text_box, NULL);
        sfRenderWindow_drawText(global->window,
        global->gameplay->pnj->text_knight_1, NULL);
    }
    display_text_knight(global);
    display_text_princess(global);
}