/*
** EPITECH PROJECT, 2019
** main fonction
** File description:
** my_defender, main function
*/

#include "my.h"
#include "rpg.h"

void pause_create(global_t *global)
{
    global->pause->back = sfSprite_create();
    global->pause->st_inv->wp_inv = sfSprite_create();
    global->pause->inv = sfSprite_create();
    global->pause->backt = sfTexture_createFromFile("resource/menu/menu.jpg", NULL);
    global->pause->st_inv->wp_invt = sfTexture_createFromFile("resource/menu/menu_pause.jpg", NULL);
    global->pause->invt = sfTexture_createFromFile("resource/menu/s1.png", NULL);
    sfSprite_setTexture(global->pause->back, global->pause->backt, sfTrue);
    sfSprite_setTexture(global->pause->inv, global->pause->invt, sfTrue);
    sfSprite_setTexture(global->pause->st_inv->wp_inv, global->pause->st_inv->wp_invt, sfTrue);
    sfSprite_setScale(global->pause->inv, (sfVector2f){0.60, 0.60});
}

int but_is_c(sfEvent event, sfSprite *spr)
{
    sfVector2f target_pos;
    int x = event.mouseButton.x;
    int y = event.mouseButton.y;

    target_pos = sfSprite_getPosition(spr);
    if (x >= target_pos.x + 20 &&
        x <= target_pos.x + 260 &&
        y >= target_pos.y + 90 &&
        y <= target_pos.y + 200)
        return (1);
    return (0);
}