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
    char *res1 = "resource/menu/no_sound.png";
    char *res2 = "resource/menu/settings.png";

    global->menu->wp = sfSprite_create();
    global->menu->start1 = sfSprite_create();
    global->menu->quit1 = sfSprite_create();
    global->menu->start2 = sfSprite_create();
    global->menu->sounds = sfSprite_create();
    global->menu->nosound = sfSprite_create();
    global->menu->settingsa = sfSprite_create();
    global->menu->soundt = sfTexture_createFromFile("resource/menu/sound.png",
                                                NULL);
    global->menu->no_soundt = sfTexture_createFromFile(res1, NULL);
    global->menu->settings->settingst = sfTexture_createFromFile(res2, NULL);
    menu_create2(global);
    menu_set_position(global);
}

void menu_display(global_t *global)
{
    sfRenderWindow_drawSprite(global->window, global->menu->wp, NULL);
    sfRenderWindow_drawSprite(global->window, global->menu->start1, NULL);
    sfRenderWindow_drawSprite(global->window, global->menu->quit1, NULL);
    sfRenderWindow_drawSprite(global->window, global->menu->settingsa, NULL);
    if (global->menu->settings->sound == 0)
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