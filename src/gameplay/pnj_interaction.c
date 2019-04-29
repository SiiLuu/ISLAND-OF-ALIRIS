/*
** EPITECH PROJECT, 2019
** rpg_2018
** File description:
** interaction with non playable player
*/

#include "my.h"
#include "rpg.h"

void display_score(global_t *global)
{
    global->gameplay->pnj->font = sfFont_createFromFile("resource/font/arial.ttf");
    global->gameplay->pnj->text = sfText_create();
    global->gameplay->pnj->s_text_box = sfSprite_create();
    global->gameplay->pnj->text_box = sfTexture_createFromFile("resource/text.png", NULL);
    sfSprite_setTexture(global->gameplay->pnj->s_text_box, global->gameplay->pnj->text_box, sfTrue);
    sfText_setString(global->gameplay->pnj->text, "Je meurs de froid !\
    je voulais explorer de\nnouvelles regions mais j'ai fini\npar me perdre,\
    aide moi a rentrer chez moi !");
    sfText_setFont(global->gameplay->pnj->text, global->gameplay->pnj->font);
    sfText_setCharacterSize(global->gameplay->pnj->text, 35);
    sfText_setColor(global->gameplay->pnj->text, sfWhite);
    sfText_setPosition(global->gameplay->pnj->text, (sfVector2f){4760, 4900 + 400});
    sfSprite_setScale(global->gameplay->pnj->s_text_box, (sfVector2f){3, 1.3});
    sfSprite_setPosition(global->gameplay->pnj->s_text_box, (sfVector2f){4700, 4950 + 320});
    sfRenderWindow_drawSprite(global->window, global->gameplay->pnj->s_text_box, NULL);
    sfRenderWindow_drawText(global->window, global->gameplay->pnj->text, NULL);
}

int check_interaction(global_t *global)
{
    if (sfKeyboard_isKeyPressed(sfKeyA) &&
        (global->gameplay->x > 4900 && global->gameplay->x < 5100) &&
        (global->gameplay->y > 4800 && global->gameplay->y < 5000))
        global->gameplay->pnj->p_text = 1;
    if (global->gameplay->pnj->p_text == 1 &&
        (global->gameplay->y < 4850 || global->gameplay->y > 5000)) {
        global->gameplay->pnj->p_text = 0;
        sfText_destroy(global->gameplay->pnj->text);
        sfFont_destroy(global->gameplay->pnj->font);
        sfSprite_destroy(global->gameplay->pnj->s_text_box);
        sfTexture_destroy(global->gameplay->pnj->text_box);
        }
}