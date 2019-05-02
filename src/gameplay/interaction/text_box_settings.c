/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** text_box_settings
*/

#include "my.h"
#include "rpg.h"

void set_text_box(global_t *global)
{
    global->gameplay->pnj->s_text_box = sfSprite_create();
    global->gameplay->pnj->text_box = sfTexture_createFromFile(\
    "resource/text.png", NULL);
    sfSprite_setTexture(global->gameplay->pnj->s_text_box,
    global->gameplay->pnj->text_box, sfTrue);
    sfSprite_setScale(global->gameplay->pnj->s_text_box, (sfVector2f){3, 1.3});
}

void destroy_textures_quetes(global_t *global)
{
    sfText_destroy(global->gameplay->pnj->text);
    sfSprite_destroy(global->gameplay->pnj->s_text_box);
    sfTexture_destroy(global->gameplay->pnj->text_box);
}