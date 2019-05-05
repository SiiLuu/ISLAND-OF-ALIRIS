/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** menu
*/

#include "my.h"
#include "rpg.h"

void menu_create2(global_t *global)
{
    global->menu->start2t = sfTexture_createFromFile("resource/menu/s2.png",
                                                NULL);
    global->menu->wpt = sfTexture_createFromFile("resource/m.jpg",
                                                NULL);
    global->menu->start1t = sfTexture_createFromFile("resource/menu/s1.png",
                                                NULL);
    global->menu->quit1t = sfTexture_createFromFile("resource/menu/q1.png",
                                                NULL);
}

void menu_set_position(global_t *global)
{
    sfSprite_setPosition(global->menu->sounds, (sfVector2f){1750, 100});
    sfSprite_setPosition(global->menu->nosound, (sfVector2f){1750, 100});
    sfSprite_setPosition(global->menu->start1, (sfVector2f){780, 150});
    sfSprite_setPosition(global->menu->quit1, (sfVector2f){780, 475});
    sfSprite_setPosition(global->menu->start2, (sfVector2f){780, 150});
    sfSprite_setPosition(global->menu->settingsa, (sfVector2f){20, 100});
    sfSprite_setScale(global->menu->settingsa, (sfVector2f){0.30, 0.30});
    sfSprite_setScale(global->menu->wp, (sfVector2f){1.00, 1.1});
    sfSprite_setScale(global->menu->start1, (sfVector2f){0.60, 0.60});
    sfSprite_setScale(global->menu->quit1, (sfVector2f){0.65, 0.65});
    sfSprite_setScale(global->menu->start2, (sfVector2f){0.60, 0.60});
    sfSprite_setTexture(global->menu->sounds, global->menu->soundt, sfTrue);
    sfSprite_setTexture(global->menu->nosound,
                        global->menu->no_soundt, sfTrue);
    sfSprite_setTexture(global->menu->wp, global->menu->wpt, sfTrue);
    sfSprite_setTexture(global->menu->start1, global->menu->start1t, sfTrue);
    sfSprite_setTexture(global->menu->quit1, global->menu->quit1t, sfTrue);
    sfSprite_setTexture(global->menu->start2, global->menu->start2t, sfTrue);
    sfSprite_setTexture(global->menu->settingsa,
                        global->menu->settings->settingst, sfTrue);
}