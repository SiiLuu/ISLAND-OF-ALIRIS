/*
** EPITECH PROJECT, 2019
** main fonction
** File description:
** my_defender, main function
*/

#include "my.h"
#include "rpg.h"

void create_item(global_t *global)
{
    global->gameplay->item->boots = sfSprite_create();
    global->gameplay->item->bootst = sfTexture_createFromFile(
        "resource/menu/boots.png", NULL);
    sfSprite_setTexture(global->gameplay->item->boots,
        global->gameplay->item->bootst, sfTrue);
    sfSprite_setPosition(global->gameplay->item->boots,
        (sfVector2f){217, 280});
    sfSprite_setScale(global->gameplay->item->boots,
        (sfVector2f){3, 2.7});
}

void draw_item(global_t *global)
{
    sfRenderWindow_drawSprite(global->window,
        global->gameplay->item->boots, NULL);
}