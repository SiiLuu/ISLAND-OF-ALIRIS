/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** my_rpg, detect_win.c
*/

#include "my.h"
#include "rpg.h"

char *reward_str2(global_t *global)
{
    static bool final = 0;
    static bool winter = 0;

    if (global->gameplay->boss->win_vs_final_boss == 1 && final == 0) {
        final = 1;
        return ("Cosmic orb obtained !!");
    }
    if (global->gameplay->boss->win_vs_winter_boss == 1 && winter == 0) {
        winter = 1;
        return ("adaptive helmet obtained !!");
    }
    return (NULL);
}

char *reward_str(global_t *global)
{
    static bool desert = 0;
    static bool hl = 0;
    char *string = NULL;

    if ((string = reward_str2(global)) != NULL)
        return (string);
    if (global->gameplay->boss->win_vs_desert_boss == 1 && desert == 0) {
        desert = 1;
        return ("enchanted breastplate obtained !!");
    }
    if (global->gameplay->boss->win_vs_hl_boss == 1 && hl == 0) {
        hl = 1;
        return ("Marauder's ax obtained !!");
    }
    return (NULL);
}

void reward(global_t *global)
{
    sfFont* font = sfFont_createFromFile("resource/font/text.ttf");
    sfText* text = sfText_create();

    sfText_setString(text, reward_str(global));
    sfText_setFont(text, font);
    sfText_setColor(text, sfBlack);
    sfText_setCharacterSize(text, 55);
    sfText_setPosition(text, (sfVector2f){300, 600});
    sfRenderWindow_drawText(global->window, text, NULL);
}

int fight_loop(global_t *global)
{
    while (1) {
        if (dectect_win(global)) {
            move_vue(global);
            if (global->gameplay->boss->win_vs_volc_boss == 1)
                global->scn = 13;
            else
                global->scn = 1;
            return (0);
        }
        if (sfTime_asMilliseconds(sfClock_getElapsedTime(
            global->fight->clocks)) > 100) {
            check_mouse_fight(global);
            sfClock_restart(global->fight->clocks);
        }
        sfRenderWindow_pollEvent(global->window, &global->event);
    }
    return (0);
}