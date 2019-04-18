/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** menu
*/

#include "my.h"
#include "rpg.h"

void menu_create(global_t *global)
{
    global->menu->wp = sfSprite_create();
    global->menu->start1 = sfSprite_create();
    global->menu->quit1 = sfSprite_create();
    global->menu->start2 = sfSprite_create();
    global->menu->sounds = sfSprite_create();
    global->menu->nosound = sfSprite_create();
    global->menu->settings = sfSprite_create();
    global->menu->soundt = sfTexture_createFromFile("resource/menu/sound.png",
                                                NULL);
    global->menu->no_soundt = sfTexture_createFromFile("resource/menu/no_sound.png",
                                                NULL);
    global->menu->start2t = sfTexture_createFromFile("resource/menu/s2.png",
                                                NULL);
    global->menu->wpt = sfTexture_createFromFile("resource/menu/wp.jpg",
                                                NULL);
    global->menu->start1t = sfTexture_createFromFile("resource/menu/s1.png",
                                                NULL);
    global->menu->quit1t = sfTexture_createFromFile("resource/menu/q1.png",
                                                NULL);
    global->menu->settingst = sfTexture_createFromFile("resource/menu/settings.png",
                                                NULL);
    menu_set_position(global);
}

void menu_display(global_t *global)
{
    sfRenderWindow_drawSprite(global->window, global->menu->wp, NULL);
    sfRenderWindow_drawSprite(global->window, global->menu->start1, NULL);
    sfRenderWindow_drawSprite(global->window, global->menu->quit1, NULL);
    sfRenderWindow_drawSprite(global->window, global->menu->settings, NULL);
    if (global->menu->sound == 0)
        sfRenderWindow_drawSprite(global->window, global->menu->sounds, NULL);
    else
        sfRenderWindow_drawSprite(global->window, global->menu->nosound, NULL);
    sfRenderWindow_display(global->window);
}

int destroy_menu(global_t *global)
{
    if (global->event.type == sfEvtClosed)
        return (1);
    return (0);
}

void change_start_btn(global_t *global)
{
    sfRenderWindow_drawSprite(global->window, global->menu->start2, NULL);
    sfRenderWindow_display(global->window);
}

void check_mouse(global_t *global)
{
    int xmouse = 0;
    int ymouse = 0;

    sfRenderWindow_pollEvent(global->window, &global->event);
    if (global->event.type == sfEvtMouseMoved) {
        xmouse = global->event.mouseMove.x;
        ymouse = global->event.mouseMove.y;
        if (xmouse >= 795 && xmouse <= 1050
        && ymouse >= 237 && ymouse <= 350)
            change_start_btn(global);
        else
            menu_display(global);
    }
}