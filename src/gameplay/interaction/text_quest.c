/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** text for the quest
*/
#include "my.h"
#include "rpg.h"

void starting_quest(global_t *global)
{
    sfText_setString(global->gameplay->pnj->text_d,
    "It's been several days since my daughter\
    \nleft and I still have no news.\
    \ncould you help me to find her?");
}


void display_text_quest(global_t *global)
{
    if (global->gameplay->pnj->p_text_d == 1) {
        set_text_box(global);
        global->gameplay->pnj->text_d = sfText_create();
        if (global->gameplay->pnj->quest_complete == 1) {
            sfText_setString(global->gameplay->pnj->text_d,
            "Thank you !! my daughter is finally back\
            \nI am happy to see her again!");
        }
        else {
            starting_quest(global);
        }
        set_desert_text(global);
        sfSprite_setPosition(global->gameplay->pnj->s_text_box,
        (sfVector2f){1640, global->gameplay->y + 380});
        sfRenderWindow_drawSprite(global->window,
        global->gameplay->pnj->s_text_box, NULL);
        sfRenderWindow_drawText(global->window,
        global->gameplay->pnj->text_d, NULL);
    }
}

void fight_final_boss(global_t *global)
{
    sfText_setString(global->gameplay->pnj->text_volc,
    "You are too weak to enter here.\
    \ncome back ... wait what ?! Ok sir you're\
    \npretty strong to go here, Good luck !");
    global->gameplay->boss->s_last_quest = 1;
}