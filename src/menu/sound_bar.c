/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** settings
*/

#include "my.h"
#include "rpg.h"

void sound_bar2(global_t *global)
{
    sfSprite_setScale(global->menu->settings->bar1, (sfVector2f){1, 0.9});
    sfSprite_setScale(global->menu->settings->bar2, (sfVector2f){1, 0.9});
    sfSprite_setScale(global->menu->settings->bar3, (sfVector2f){1, 0.9});
    sfSprite_setScale(global->menu->settings->bar4, (sfVector2f){1, 0.9});
    sfSprite_setTexture(global->menu->settings->bar1,
                        global->menu->settings->bart, sfTrue);
    sfSprite_setTexture(global->menu->settings->bar2,
                        global->menu->settings->bart, sfTrue);
    sfSprite_setTexture(global->menu->settings->bar3,
                        global->menu->settings->bart, sfTrue);
    sfSprite_setTexture(global->menu->settings->bar4,
                        global->menu->settings->bart, sfTrue);
}

void sound_bar(global_t *global)
{
    char *res1 = "resource/menu/line.png";

    global->menu->settings->bar1 = sfSprite_create();
    global->menu->settings->bar2 = sfSprite_create();
    global->menu->settings->bar3 = sfSprite_create();
    global->menu->settings->bar4 = sfSprite_create();
    global->menu->settings->bart = sfTexture_createFromFile(res1, NULL);
    sfSprite_setPosition(global->menu->settings->bar1, (sfVector2f){780, 400});
    sfSprite_setPosition(global->menu->settings->bar2, (sfVector2f){875, 400});
    sfSprite_setPosition(global->menu->settings->bar3, (sfVector2f){970, 400});
    sfSprite_setPosition(global->menu->settings->bar4,
                            (sfVector2f){1067, 400});
    sound_bar2(global);
}

void display_sound_bar(global_t *global)
{
    sound_bar(global);
    if (global->menu->settings->nbr_bar == 1 ||
        global->menu->settings->nbr_bar == 2 ||
        global->menu->settings->nbr_bar == 3
        || global->menu->settings->nbr_bar == 4)
        sfRenderWindow_drawSprite(global->window, global->menu->settings->bar1,
                                    NULL);
    if (global->menu->settings->nbr_bar == 2 ||
        global->menu->settings->nbr_bar == 3 ||
        global->menu->settings->nbr_bar == 4)
        sfRenderWindow_drawSprite(global->window, global->menu->settings->bar2,
                                    NULL);
    if (global->menu->settings->nbr_bar == 3 ||
        global->menu->settings->nbr_bar == 4)
        sfRenderWindow_drawSprite(global->window, global->menu->settings->bar3,
                                    NULL);
    if (global->menu->settings->nbr_bar == 4)
        sfRenderWindow_drawSprite(global->window, global->menu->settings->bar4,
                                    NULL);
}

void display_sound_settings(global_t *global)
{
    char *res1 = "resource/menu/plus.webp";
    char *res2 = "resource/menu/minus.webp";

    global->menu->settings->plus = sfSprite_create();
    global->menu->settings->minus = sfSprite_create();
    global->menu->settings->plust = sfTexture_createFromFile(res1, NULL);
    global->menu->settings->minust = sfTexture_createFromFile(res2, NULL);
    sfSprite_setPosition(global->menu->settings->plus,
                            (sfVector2f){1080, 400});
    sfSprite_setPosition(global->menu->settings->minus,
                            (sfVector2f){704, 422});
    sfSprite_setScale(global->menu->settings->minus, (sfVector2f){0.05, 0.05});
    sfSprite_setScale(global->menu->settings->plus, (sfVector2f){0.18, 0.18});
    sfSprite_setTexture(global->menu->settings->plus,
                        global->menu->settings->plust, sfTrue);
    sfSprite_setTexture(global->menu->settings->minus,
                        global->menu->settings->minust, sfTrue);
    sfRenderWindow_drawSprite(global->window, global->menu->settings->minus,
                                NULL);
    sfRenderWindow_drawSprite(global->window, global->menu->settings->plus,
                                NULL);
}

void display_sound(global_t *global)
{
    char *text = "resource/font/text.ttf";

    global->menu->settings->font = sfFont_createFromFile(text);
    global->menu->settings->text_music = sfText_create();
    sfText_setString(global->menu->settings->text_music, "Music :");
    sfText_setFont(global->menu->settings->text_music,
                    global->menu->settings->font);
    sfText_setColor(global->menu->settings->text_music, sfBlack);
    sfText_setCharacterSize(global->menu->settings->text_music, 50);
    sfText_setPosition(global->menu->settings->text_music,
                        (sfVector2f){850, 300});
    sfRenderWindow_drawText(global->window,
                            global->menu->settings->text_music, NULL);
}
