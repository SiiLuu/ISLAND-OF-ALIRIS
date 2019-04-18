/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** settings
*/

#include "my.h"
#include "rpg.h"

void sound_bar(global_t *global)
{
    global->menu->bar1 = sfSprite_create();
    global->menu->bar2 = sfSprite_create();
    global->menu->bar3 = sfSprite_create();
    global->menu->bar4 = sfSprite_create();
    global->menu->bart = sfTexture_createFromFile("resource/menu/line.png",
                                                NULL);
    sfSprite_setPosition(global->menu->bar1, (sfVector2f){780, 400});
    sfSprite_setPosition(global->menu->bar2, (sfVector2f){875, 400});
    sfSprite_setPosition(global->menu->bar3, (sfVector2f){970, 400});
    sfSprite_setPosition(global->menu->bar4, (sfVector2f){1067, 400});
    sfSprite_setScale(global->menu->bar1, (sfVector2f){1, 0.9});
    sfSprite_setScale(global->menu->bar2, (sfVector2f){1, 0.9});
    sfSprite_setScale(global->menu->bar3, (sfVector2f){1, 0.9});
    sfSprite_setScale(global->menu->bar4, (sfVector2f){1, 0.9});
    sfSprite_setTexture(global->menu->bar1, global->menu->bart, sfTrue);
    sfSprite_setTexture(global->menu->bar2, global->menu->bart, sfTrue);
    sfSprite_setTexture(global->menu->bar3, global->menu->bart, sfTrue);
    sfSprite_setTexture(global->menu->bar4, global->menu->bart, sfTrue);
}

void display_sound_bar(global_t *global)
{
    sound_bar(global);
    if (global->menu->nbr_bar == 1 || global->menu->nbr_bar == 2 || global->menu->nbr_bar == 3
        || global->menu->nbr_bar == 4)
        sfRenderWindow_drawSprite(global->window, global->menu->bar1, NULL);
    if (global->menu->nbr_bar == 2 || global->menu->nbr_bar == 3 || global->menu->nbr_bar == 4)
        sfRenderWindow_drawSprite(global->window, global->menu->bar2, NULL);
    if (global->menu->nbr_bar == 3 || global->menu->nbr_bar == 4)
        sfRenderWindow_drawSprite(global->window, global->menu->bar3, NULL);
    if (global->menu->nbr_bar == 4)
        sfRenderWindow_drawSprite(global->window, global->menu->bar4, NULL);
}

void display_sound_settings(global_t *global)
{
    global->menu->plus = sfSprite_create();
    global->menu->minus = sfSprite_create();
    global->menu->plust = sfTexture_createFromFile("resource/menu/plus.webp",
                                                NULL);
    global->menu->minust = sfTexture_createFromFile("resource/menu/minus.webp",
                                                NULL);
    sfSprite_setPosition(global->menu->plus, (sfVector2f){1080, 400});
    sfSprite_setPosition(global->menu->minus, (sfVector2f){704, 422});
    sfSprite_setScale(global->menu->minus, (sfVector2f){0.05, 0.05});
    sfSprite_setScale(global->menu->plus, (sfVector2f){0.18, 0.18});
    sfSprite_setTexture(global->menu->plus, global->menu->plust, sfTrue);
    sfSprite_setTexture(global->menu->minus, global->menu->minust, sfTrue);
    sfRenderWindow_drawSprite(global->window, global->menu->minus, NULL);
    sfRenderWindow_drawSprite(global->window, global->menu->plus, NULL);
}

void display_sound(global_t *global)
{
    global->menu->font = sfFont_createFromFile("resource/font/text.ttf");
    global->menu->text_music = sfText_create();
    sfText_setString(global->menu->text_music, "Music :");
    sfText_setFont(global->menu->text_music, global->menu->font);
    sfText_setColor(global->menu->text_music, sfBlack);
    sfText_setCharacterSize(global->menu->text_music, 50);
    sfText_setPosition(global->menu->text_music, (sfVector2f){850, 300});
    sfRenderWindow_drawText(global->window, global->menu->text_music, NULL);
}
