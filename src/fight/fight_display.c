/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** my_rpg, fight_display.c
*/

#include "my.h"
#include "rpg.h"

void display_elementary(global_t *global)
{
    sfRenderWindow_drawSprite(global->window, global->fight->wp1s, NULL);
    sfRenderWindow_drawSprite(global->window, global->fight->boss1s, NULL);
    sfRenderWindow_drawSprite(global->window, global->fight->players, NULL);
    sfRenderWindow_drawSprite(global->window, global->fight->arrows, NULL);
    sfRenderWindow_drawSprite(global->window, global->fight->attack_spes,
                                NULL);
    sfRenderWindow_drawSprite(global->window, global->fight->attacks, NULL);
    draw_fight_info(global);
}

void draw_fight_info_display(global_t *global)
{
    sfText_setCharacterSize(global->fight->stamina1t, 35);
    sfText_setCharacterSize(global->fight->life1t, 35);
    sfText_setCharacterSize(global->fight->stamina, 35);
    sfText_setCharacterSize(global->fight->life, 35);
    sfText_setPosition(global->fight->stamina1t, (sfVector2f){1350, 1000});
    sfText_setPosition(global->fight->life1t, (sfVector2f){900, 1000});
    sfText_setPosition(global->fight->life, (sfVector2f){700, 1000});
    sfText_setPosition(global->fight->stamina, (sfVector2f){1100,1000});
    sfRenderWindow_drawText(global->window, global->fight->stamina1t, NULL);
    sfRenderWindow_drawText(global->window, global->fight->life1t, NULL);
    sfRenderWindow_drawText(global->window, global->fight->stamina, NULL);
    sfRenderWindow_drawText(global->window, global->fight->life, NULL);
}

void draw_fight_info(global_t *global)
{
    sfFont* font = sfFont_createFromFile("resource/font/text.ttf");

    global->fight->life = sfText_create();
    global->fight->life1t = sfText_create();
    global->fight->stamina1t = sfText_create();
    global->fight->stamina = sfText_create();
    sfText_setString(global->fight->life, "Your life : ");
    sfText_setString(global->fight->stamina, "Your mana : ");
    sfText_setString(global->fight->life1t,
                    convert_int_char(global->fight->life1));
    sfText_setString(global->fight->stamina1t,
                    convert_int_char(global->fight->stamina1));
    sfText_setFont(global->fight->stamina1t, font);
    sfText_setFont(global->fight->life1t, font);
    sfText_setFont(global->fight->stamina, font);
    sfText_setFont(global->fight->life, font);
    sfText_setColor(global->fight->life1t, sfBlack);
    sfText_setColor(global->fight->stamina1t, sfBlack);
    sfText_setColor(global->fight->life, sfBlack);
    sfText_setColor(global->fight->stamina, sfBlack);
    draw_fight_info_display(global);
}

void fight_display(global_t *global)
{
    check_turn(global);
    display_elementary(global);
    sfRenderWindow_display(global->window);
}