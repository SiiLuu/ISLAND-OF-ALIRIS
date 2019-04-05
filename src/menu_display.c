/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** menu
*/

#include "my.h"

void menu_create(menu_t *menu)
{
    menu->wp = sfSprite_create();
    menu->start1 = sfSprite_create();
    menu->quit1 = sfSprite_create();
    menu->start2 = sfSprite_create();
    menu->sounds = sfSprite_create();
    menu->nosound = sfSprite_create();
    menu->texture7 = sfTexture_createFromFile("resource/menu/sound.png",
                                                NULL);
    menu->texture8 = sfTexture_createFromFile("resource/menu/no_sound.png",
                                                NULL);
    menu->texture6 = sfTexture_createFromFile("resource/menu/s2.png",
                                                NULL);
    menu->texture3 = sfTexture_createFromFile("resource/menu/wp.png",
                                                NULL);
    menu->texture4 = sfTexture_createFromFile("resource/menu/s1.png",
                                                NULL);
    menu->texture5 = sfTexture_createFromFile("resource/menu/q1.png",
                                                NULL);
    menu_set_position(menu);
}

void menu_display(global_t *global, menu_t *menu)
{
    sfRenderWindow_drawSprite(global->window, menu->wp, NULL);
    sfRenderWindow_drawSprite(global->window, menu->start1, NULL);
    sfRenderWindow_drawSprite(global->window, menu->quit1, NULL);
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
    if (global->event.type == sfEvtMouseMoved) {
        global->xmouse = global->event.mouseMove.x;
        global->ymouse = global->event.mouseMove.y;
        if (global->xmouse >= 795 && global->xmouse <= 1050
        && global->ymouse >= 237 && global->ymouse <= 350)
            change_start_btn(global, menu);
        else
            menu_display(global, menu);
    }
}