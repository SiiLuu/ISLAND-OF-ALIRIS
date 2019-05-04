/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** my_rpg, detect_win.c
*/

#include "my.h"
#include "rpg.h"

char *reward_str(global_t *global)
{
    if (global->gameplay->boss->win_vs_final_boss == 1)
        return("Lava boots obtained !!");
    if (global->gameplay->boss->win_vs_winter_boss == 1)
        return("Marauder's ax obtained !!");
    if (global->gameplay->boss->win_vs_desert_boss == 1)
        return("adaptive helmet obtained !!");
    if (global->gameplay->boss->win_vs_hl_boss == 1)
        return("enchanted breastplate obtained !!");
    return ("ERROR");
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