/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** menu
*/

#include "my.h"
#include "rpg.h"

void menu_set_position(global_t *global)
{
    sfSprite_setPosition(global->menu->sounds, (sfVector2f){1750, 100});
    sfSprite_setPosition(global->menu->nosound, (sfVector2f){1750, 100});
    sfSprite_setPosition(global->menu->wp, (sfVector2f){-25, -25});
    sfSprite_setPosition(global->menu->start1, (sfVector2f){780, 150});
    sfSprite_setPosition(global->menu->quit1, (sfVector2f){780, 475});
    sfSprite_setPosition(global->menu->start2, (sfVector2f){780, 150});
    sfSprite_setPosition(global->menu->settings, (sfVector2f){20, 100});
    sfSprite_setScale(global->menu->settings, (sfVector2f){0.30, 0.30});
    sfSprite_setScale(global->menu->wp, (sfVector2f){0.50, 0.50});
    sfSprite_setScale(global->menu->start1, (sfVector2f){0.60, 0.60});
    sfSprite_setScale(global->menu->quit1, (sfVector2f){0.65, 0.65});
    sfSprite_setScale(global->menu->start2, (sfVector2f){0.60, 0.60});
    sfSprite_setTexture(global->menu->sounds, global->menu->soundt, sfTrue);
    sfSprite_setTexture(global->menu->nosound, global->menu->no_soundt, sfTrue);
    sfSprite_setTexture(global->menu->wp, global->menu->wpt, sfTrue);
    sfSprite_setTexture(global->menu->start1, global->menu->start1t, sfTrue);
    sfSprite_setTexture(global->menu->quit1, global->menu->quit1t, sfTrue);
    sfSprite_setTexture(global->menu->start2, global->menu->start2t, sfTrue);
    sfSprite_setTexture(global->menu->settings, global->menu->settingst, sfTrue);
}

void sound_modif_sprite(global_t *global, int x, int y)
{
    if (x >= 1750 && x <= 1878 && y >= 100 && y <= 228) {
        if (global->menu->sound == 1) {
            global->menu->sound = 0;
            sfRenderWindow_display(global->window);
            sfMusic_play(global->menu->musique);
        }
        else {
            global->menu->sound = 1;
            sfRenderWindow_display(global->window);
            sfMusic_pause(global->menu->musique);
        }
    }
}

void menu_choose_create_display(global_t *global, int i)
{
    if (i == 1)
        menu_display(global);
    else {
        menu_create(global);
        menu_display(global);
    }
}

int menu_start(global_t *global, int i)
{
    int x = 0;
    int y = 0;
    
    sfRenderWindow_pollEvent(global->window, &global->event);
    menu_choose_create_display(global, i);
    while (global->event.type != sfEvtClosed) {
        check_mouse(global);
        if (global->event.type == sfEvtMouseButtonPressed) {
            x = global->event.mouseButton.x;
            y = global->event.mouseButton.y;
            sound_modif_sprite(global, x, y);
            if (settings(global, x, y))
                return (0);
            else
                menu_choose_create_display(global, 1);
            if (x >= 795 && x <= 1050 && y >= 237 && y <= 350)
                return (0);
            if (x >= 800 && x <= 1050 && y >= 562 && y <= 694) {
                if (destroy_menu(global) == 1)
                    return (0);
                return (1);
            }
        }
        sfRenderWindow_pollEvent(global->window, &global->event);
    }
    return (0);
}