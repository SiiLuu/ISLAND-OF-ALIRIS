/*
** EPITECH PROJECT, 2018
** my_defender
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

void sound_modif_sprite(global_t *global, int x, int y)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(global->menu->clocks)) >
        150) {
        if (x >= 1750 && x <= 1878 && y >= 100 && y <= 228) {
            if (global->menu->settings->sound == 1) {
                global->menu->settings->sound = 0;
                sfRenderWindow_display(global->window);
                sfMusic_play(global->menu->settings->musique);
            }
            else {
                global->menu->settings->sound = 1;
                sfRenderWindow_display(global->window);
                sfMusic_pause(global->menu->settings->musique);
            }
        }
        sfClock_restart(global->menu->clocks);
    }
}

void menu_choose_create_display(global_t *global, int i)
{
    sfRenderWindow_pollEvent(global->window, &global->event);
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
    int j = 0;

    menu_choose_create_display(global, i);
    global->menu->clocks = sfClock_create();
    while (global->event.type != sfEvtClosed) {
        check_mouse(global);
        if (global->event.type == sfEvtMouseButtonPressed) {
            x = global->event.mouseButton.x;
            y = global->event.mouseButton.y;
            if ((j = check_menu(global, x, y)) == 1)
                return (1);
            else if (j == 0) {
                choose_character(global);
                return (0);
            }
        }
        sfRenderWindow_pollEvent(global->window, &global->event);
    }
    return (0);
}