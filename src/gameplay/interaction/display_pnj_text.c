/*
** EPITECH PROJECT, 2019
** print the text
** File description:
** rpg
*/

#include "my.h"
#include "rpg.h"

void display_text_bottom(global_t *global)
{
    if (global->gameplay->pnj->status->p_text_bot == 1) {
        set_text_box(global);
        global->gameplay->pnj->text_bot = sfText_create();
        sfText_setString(global->gameplay->pnj->text_bot,
        "I never go away, my mom forbids me.\nweird things happen down there");
        set_bot_text(global);
        sfSprite_setPosition(global->gameplay->pnj->s_text_box,
        (sfVector2f){4150, global->gameplay->y + 370});
        sfRenderWindow_drawSprite(global->window,
        global->gameplay->pnj->s_text_box, NULL);
        sfRenderWindow_drawText(global->window,
        global->gameplay->pnj->text_bot, NULL);
    }
}
void display_text_pech(global_t *global)
{
    if (global->gameplay->pnj->status->p_text_pech == 1) {
        set_text_box(global);
        global->gameplay->pnj->text_pech = sfText_create();
        sfText_setString(global->gameplay->pnj->text_pech,
        "I love coming here to fish,\nthere are lots of fish. it makes me\
        \nfeel good after difficult fights");
        set_pech_text(global);
        sfSprite_setPosition(global->gameplay->pnj->s_text_box,
        (sfVector2f){3600, 2000 + 470});
        sfRenderWindow_drawSprite(global->window,
        global->gameplay->pnj->s_text_box, NULL);
        sfRenderWindow_drawText(global->window,
        global->gameplay->pnj->text_pech, NULL);
    }
}

void display_text_desert(global_t *global)
{
    if (global->gameplay->pnj->status->p_text_ed == 1) {
        set_text_box(global);
        global->gameplay->pnj->text_ed = sfText_create();
        sfText_setString(global->gameplay->pnj->text_ed,
        "it's too hot in this desert, I can't\
        \neven walk the sand burns. Good Luck to you !");
        set_edesert_text(global);
        sfSprite_setPosition(global->gameplay->pnj->s_text_box,
        (sfVector2f){2620, global->gameplay->y + 380});
        sfRenderWindow_drawSprite(global->window,
        global->gameplay->pnj->s_text_box, NULL);
        sfRenderWindow_drawText(global->window,
        global->gameplay->pnj->text_ed, NULL);
    }
}

void display_text_volc(global_t *global)
{
    if (global->gameplay->pnj->status->q_volc == 1) {
        set_text_box(global);
        global->gameplay->pnj->text_volc = sfText_create();
        if (global->gameplay->boss->quest_fboss < 4) {
            sfText_setString(global->gameplay->pnj->text_volc,
            "You are too weak to enter here.\
            \ncome back later...");
        }
        else
            fight_final_boss(global);
        set_volc_text(global);
        sfSprite_setPosition(global->gameplay->pnj->s_text_box,
        (sfVector2f){1300, global->gameplay->y + 380});
        sfRenderWindow_drawSprite(global->window,
        global->gameplay->pnj->s_text_box, NULL);
        sfRenderWindow_drawText(global->window,
        global->gameplay->pnj->text_volc, NULL);
    }
}

void display_text(global_t *global)
{
    global->gameplay->pnj->font = sfFont_createFromFile(\
    "resource/font/arial.ttf");
    if (global->gameplay->pnj->status->p_text == 1 &&
        global->gameplay->pnj->status->girl_quest == 1) {
        set_text_box(global);
        global->gameplay->pnj->text = sfText_create();
        sfText_setString(global->gameplay->pnj->text,
        "I'm dying of cold! I wanted to explore new areas\
        \nbut I ended up losing myself, I follow you,\
        \nhelp me to go back with my mother");
        set_winter_text(global);
        sfSprite_setPosition(global->gameplay->pnj->s_text_box,
        (sfVector2f){4700, 4950 + 320});
        sfRenderWindow_drawSprite(global->window,
        global->gameplay->pnj->s_text_box, NULL);
        sfRenderWindow_drawText(global->window,
        global->gameplay->pnj->text, NULL);
    }
    different_text(global);
}