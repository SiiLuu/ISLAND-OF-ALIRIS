/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** menu
*/

#include "my.h"
#include "rpg.h"

void menu_set_position(menu_t *menu)
{
    sfSprite_setPosition(menu->sounds, (sfVector2f){1750, 100});
    sfSprite_setPosition(menu->nosound, (sfVector2f){1750, 100});
    sfSprite_setPosition(menu->wp, (sfVector2f){-25, -25});
    sfSprite_setPosition(menu->start1, (sfVector2f){780, 150});
    sfSprite_setPosition(menu->quit1, (sfVector2f){780, 475});
    sfSprite_setPosition(menu->start2, (sfVector2f){780, 150});
    sfSprite_setPosition(menu->settings, (sfVector2f){20, 100});
    sfSprite_setScale(menu->settings, (sfVector2f){0.30, 0.30});
    sfSprite_setScale(menu->wp, (sfVector2f){0.50, 0.50});
    sfSprite_setScale(menu->start1, (sfVector2f){0.60, 0.60});
    sfSprite_setScale(menu->quit1, (sfVector2f){0.65, 0.65});
    sfSprite_setScale(menu->start2, (sfVector2f){0.60, 0.60});
    sfSprite_setTexture(menu->sounds, menu->soundt, sfTrue);
    sfSprite_setTexture(menu->nosound, menu->no_soundt, sfTrue);
    sfSprite_setTexture(menu->wp, menu->wpt, sfTrue);
    sfSprite_setTexture(menu->start1, menu->start1t, sfTrue);
    sfSprite_setTexture(menu->quit1, menu->quit1t, sfTrue);
    sfSprite_setTexture(menu->start2, menu->start2t, sfTrue);
    sfSprite_setTexture(menu->settings, menu->settingst, sfTrue);
}

void sound_modif_sprite(global_t *global, menu_t *menu, int x, int y)
{
    if (x >= 1750 && x <= 1878 && y >= 100 && y <= 228) {
        if (menu->sound == 1) {
            menu->sound = 0;
            sfRenderWindow_display(global->window);
            sfMusic_play(menu->musique);
        }
        else {
            menu->sound = 1;
            sfRenderWindow_display(global->window);
            sfMusic_pause(menu->musique);
        }
    }
}

void menu_choose_create_display(global_t *global, menu_t *menu, int i)
{
    if (i == 1)
        menu_display(global, menu);
    else {
        menu_create(menu);
        menu_display(global, menu);
    }
}

int menu_start(global_t *global, menu_t *menu, int i)
{
    int x = 0;
    int y = 0;
    
    sfRenderWindow_pollEvent(global->window, &global->event);
    menu_choose_create_display(global, menu, i);
    while (global->event.type != sfEvtClosed) {
        check_mouse(global, menu);
        if (global->event.type == sfEvtMouseButtonPressed) {
            x = global->event.mouseButton.x;
            y = global->event.mouseButton.y;
            sound_modif_sprite(global, menu, x, y);
            if (settings(global, menu, x, y))
                return (0);
            else
                menu_choose_create_display(global, menu, 1);
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