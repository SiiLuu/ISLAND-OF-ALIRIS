/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** menu
*/

#include "my.h"
#include "rpg.h"

void menu_create(menu_t *menu)
{
    menu->wp = sfSprite_create();
    menu->start1 = sfSprite_create();
    menu->quit1 = sfSprite_create();
    menu->start2 = sfSprite_create();
    menu->sounds = sfSprite_create();
    menu->nosound = sfSprite_create();
    menu->settings = sfSprite_create();
    menu->soundt = sfTexture_createFromFile("resource/menu/sound.png",
                                                NULL);
    menu->no_soundt = sfTexture_createFromFile("resource/menu/no_sound.png",
                                                NULL);
    menu->start2t = sfTexture_createFromFile("resource/menu/s2.png",
                                                NULL);
    menu->wpt = sfTexture_createFromFile("resource/menu/wp.jpg",
                                                NULL);
    menu->start1t = sfTexture_createFromFile("resource/menu/s1.png",
                                                NULL);
    menu->quit1t = sfTexture_createFromFile("resource/menu/q1.png",
                                                NULL);
    menu->settingst = sfTexture_createFromFile("resource/menu/settings.png",
                                                NULL);
    menu_set_position(menu);
}

void menu_display(global_t *global, menu_t *menu)
{
    sfRenderWindow_drawSprite(global->window, menu->wp, NULL);
    sfRenderWindow_drawSprite(global->window, menu->start1, NULL);
    sfRenderWindow_drawSprite(global->window, menu->quit1, NULL);
    sfRenderWindow_drawSprite(global->window, menu->settings, NULL);
    if (menu->sound == 0)
        sfRenderWindow_drawSprite(global->window, menu->sounds, NULL);
    else
        sfRenderWindow_drawSprite(global->window, menu->nosound, NULL);
    sfRenderWindow_display(global->window);
}

int destroy_menu(global_t *global)
{
    if (global->event.type == sfEvtClosed)
        return (1);
    return (0);
}

void change_start_btn(global_t *global, menu_t *menu)
{
    sfRenderWindow_drawSprite(global->window, menu->start2, NULL);
    sfRenderWindow_display(global->window);
}

void check_mouse(global_t *global, menu_t *menu)
{
    int xmouse = 0;
    int ymouse = 0;

    sfRenderWindow_pollEvent(global->window, &global->event);
    if (global->event.type == sfEvtMouseMoved) {
        xmouse = global->event.mouseMove.x;
        ymouse = global->event.mouseMove.y;
        if (xmouse >= 795 && xmouse <= 1050
        && ymouse >= 237 && ymouse <= 350)
            change_start_btn(global, menu);
        else
            menu_display(global, menu);
    }
}