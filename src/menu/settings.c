/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** settings
*/

#include "my.h"
#include "rpg.h"

int check_quit(global_t *global)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
        destroy_all_settings(global);
        return (0);
    }
    if (global->event.type == sfEvtClosed) {
        destroy_all_settings(global);
        return (1);
    }
    return (3);
}

sfClock *settings_clock(global_t *global, sfClock *clocks)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(clocks)) > 100) {
        check_plus_minus(global);
        sfClock_restart(clocks);
    }
    return (clocks);
}

int settings_check(global_t *global)
{
    int i = 0;

    if ((i = check_quit(global)) == 0)
        return (0);
    else if (i == 1)
        return (1);
    return (2);
}

int loop_settings(global_t *global, sfClock *clocks)
{
    int i = 0;

    while (sfRenderWindow_isOpen(global->window)) {
        sfRenderWindow_pollEvent(global->window, &global->event);
        clocks = settings_clock(global, clocks);
        i = settings_check(global);
        if (i == 0 || i == 1)
            return (i);
        sfMusic_setVolume(global->menu->settings->musique,
                        (global->menu->settings->nbr_bar * 25));
    }
    return (2);
}

int settings(global_t *global, int x, int y)
{
    sfClock *clocks = sfClock_create();
    int i = 0;

    if (x >= 20 && x <= 180 && y >= 100 && y <= 250) {
        all_display_settings(global);
        i = loop_settings(global, clocks);
        if (i == 0 || i == 1)
            return (i);
        destroy_all_settings(global);
    }
    return (0);
}