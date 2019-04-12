/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** settings
*/

#include "my.h"
#include "rpg.h"

void destroy_all_settings(menu_t *menu)
{
    sfText_destroy(menu->text_music);
    sfFont_destroy(menu->font);
    sfSprite_destroy(menu->plus);
    sfSprite_destroy(menu->minus);
    sfTexture_destroy(menu->plust);
    sfTexture_destroy(menu->minust);
    sfTexture_destroy(menu->bart);
    sfSprite_destroy(menu->bar1);
    sfSprite_destroy(menu->bar2);
    sfSprite_destroy(menu->bar3);
    sfSprite_destroy(menu->bar4);
}

void check_plus_minus(global_t *global, menu_t *menu)
{
    if (global->event.type == sfEvtMouseButtonPressed) {
        global->xmouse = global->event.mouseButton.x;
        global->ymouse = global->event.mouseButton.y;
        if (global->xmouse >= 704 && global->xmouse <= 750
            && global->ymouse >= 422 && global->ymouse <= 470) {
            if (menu->nbr_bar > 0)
                menu->nbr_bar -= 1;
            all_display_settings(global, menu);
        }
        if (global->xmouse >= 1104 && global->xmouse <= 1156
            && global->ymouse >= 420 && global->ymouse <= 472) {
            if (menu->nbr_bar < 4)
                menu->nbr_bar += 1;
            all_display_settings(global, menu);
        }
        global->xmouse = 0;
        global->ymouse = 0;
    }
}

void all_display_settings(global_t *global, menu_t *menu)
{
    sfRenderWindow_drawSprite(global->window, menu->wp, NULL);
    display_score(global, menu);
    display_sound_settings(global, menu);
    display_sound_bar(global, menu);
    sfRenderWindow_display(global->window);
}

int settings(global_t *global, menu_t *menu)
{
    sfClock *clocks = sfClock_create();

    if (global->xmouse >= 20 && global->xmouse <= 180
        && global->ymouse >= 100 && global->ymouse <= 250) {
        all_display_settings(global, menu);
        while (sfRenderWindow_isOpen(global->window)) {
            sfRenderWindow_pollEvent(global->window, &global->event);
            if (sfTime_asMilliseconds(sfClock_getElapsedTime(clocks)) > 100) {
                check_plus_minus(global, menu);
                sfClock_restart(clocks);
            }
            if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
                destroy_all_settings(menu);
                return (0);
            }
            if (global->event.type == sfEvtClosed) {
                destroy_all_settings(menu);
                return (1);
            }
            sfMusic_setVolume(menu->musique, (menu->nbr_bar * 25));
        }
        destroy_all_settings(menu);
    }
    return (0);
}