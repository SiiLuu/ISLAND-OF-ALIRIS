/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** settings
*/

#include "my.h"
#include "rpg.h"

void destroy_all_settings(global_t *global)
{
    sfText_destroy(global->menu->settings->text_music);
    sfFont_destroy(global->menu->settings->font);
    sfSprite_destroy(global->menu->settings->plus);
    sfSprite_destroy(global->menu->settings->minus);
    sfTexture_destroy(global->menu->settings->plust);
    sfTexture_destroy(global->menu->settings->minust);
    sfTexture_destroy(global->menu->settings->bart);
    sfSprite_destroy(global->menu->settings->bar1);
    sfSprite_destroy(global->menu->settings->bar2);
    sfSprite_destroy(global->menu->settings->bar3);
    sfSprite_destroy(global->menu->settings->bar4);
}

void check_plus_minus(global_t *global)
{
    int x = 0;
    int y = 0;

    if (global->event.type == sfEvtMouseButtonPressed) {
        x = global->event.mouseButton.x;
        y = global->event.mouseButton.y;
        if (x >= 704 && x <= 750 && y >= 422 && y <= 470) {
            if (global->menu->settings->nbr_bar > 0)
                global->menu->settings->nbr_bar -= 1;
            all_display_settings(global);
        }
        if (x >= 1104 && x <= 1156 && y >= 420 && y <= 472) {
            if (global->menu->settings->nbr_bar < 4)
                global->menu->settings->nbr_bar += 1;
            all_display_settings(global);
        }
    }
}

void all_display_settings(global_t *global)
{
    sfRenderWindow_drawSprite(global->window, global->menu->wp, NULL);
    display_sound(global);
    display_sound_settings(global);
    display_sound_bar(global);
    sfRenderWindow_display(global->window);
}

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

int settings(global_t *global, int x, int y)
{
    sfClock *clocks = sfClock_create();
    int i = 0;

    if (x >= 20 && x <= 180 && y >= 100 && y <= 250) {
        all_display_settings(global);
        while (sfRenderWindow_isOpen(global->window)) {
            sfRenderWindow_pollEvent(global->window, &global->event);
            if (sfTime_asMilliseconds(sfClock_getElapsedTime(clocks)) > 100) {
                check_plus_minus(global);
                sfClock_restart(clocks);
            }
            if ((i = check_quit(global)) == 0)
                return (0);
            else if (i == 1)
                return (1);
            sfMusic_setVolume(global->menu->settings->musique,
                                (global->menu->settings->nbr_bar * 25));
        }
        destroy_all_settings(global);
    }
    return (0);
}