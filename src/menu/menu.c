/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** menu
*/

#include "my.h"
#include "rpg.h"

void sound_modif_check(global_t *global)
{
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

void sound_modif_sprite(global_t *global, int x, int y)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(global->menu->clocks)) >
        150) {
        if (x >= 1750 && x <= 1878 && y >= 100 && y <= 228)
            sound_modif_check(global);
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

int check_mouse_event(global_t *global, int x, int y)
{
    int j = 0;

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
    return (2);
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
        j = check_mouse_event(global, x, y);
        if (j == 1 || j == 0)
            return (j);
        sfRenderWindow_pollEvent(global->window, &global->event);
    }
    return (0);
}