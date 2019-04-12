/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** settings
*/

#include "my.h"
#include "rpg.h"

void sound_bar(global_t *global, menu_t *menu)
{
    menu->bar1 = sfSprite_create();
    menu->bar2 = sfSprite_create();
    menu->bar3 = sfSprite_create();
    menu->bar4 = sfSprite_create();
    menu->bart = sfTexture_createFromFile("resource/menu/line.png",
                                                NULL);
    sfSprite_setPosition(menu->bar1, (sfVector2f){780, 400});
    sfSprite_setPosition(menu->bar2, (sfVector2f){875, 400});
    sfSprite_setPosition(menu->bar3, (sfVector2f){970, 400});
    sfSprite_setPosition(menu->bar4, (sfVector2f){1067, 400});
    sfSprite_setScale(menu->bar1, (sfVector2f){1, 0.9});
    sfSprite_setScale(menu->bar2, (sfVector2f){1, 0.9});
    sfSprite_setScale(menu->bar3, (sfVector2f){1, 0.9});
    sfSprite_setScale(menu->bar4, (sfVector2f){1, 0.9});
    sfSprite_setTexture(menu->bar1, menu->bart, sfTrue);
    sfSprite_setTexture(menu->bar2, menu->bart, sfTrue);
    sfSprite_setTexture(menu->bar3, menu->bart, sfTrue);
    sfSprite_setTexture(menu->bar4, menu->bart, sfTrue);
}

void display_sound_bar(global_t *global, menu_t *menu)
{
    sound_bar(global, menu);
    if (menu->nbr_bar == 1 || menu->nbr_bar == 2 || menu->nbr_bar == 3
        || menu->nbr_bar == 4)
        sfRenderWindow_drawSprite(global->window, menu->bar1, NULL);
    if (menu->nbr_bar == 2 || menu->nbr_bar == 3 || menu->nbr_bar == 4)
        sfRenderWindow_drawSprite(global->window, menu->bar2, NULL);
    if (menu->nbr_bar == 3 || menu->nbr_bar == 4)
        sfRenderWindow_drawSprite(global->window, menu->bar3, NULL);
    if (menu->nbr_bar == 4)
        sfRenderWindow_drawSprite(global->window, menu->bar4, NULL);
}

void display_sound_settings(global_t *global, menu_t *menu)
{
    menu->plus = sfSprite_create();
    menu->minus = sfSprite_create();
    menu->plust = sfTexture_createFromFile("resource/menu/plus.webp",
                                                NULL);
    menu->minust = sfTexture_createFromFile("resource/menu/minus.webp",
                                                NULL);
    sfSprite_setPosition(menu->plus, (sfVector2f){1080, 400});
    sfSprite_setPosition(menu->minus, (sfVector2f){704, 422});
    sfSprite_setScale(menu->minus, (sfVector2f){0.05, 0.05});
    sfSprite_setScale(menu->plus, (sfVector2f){0.18, 0.18});
    sfSprite_setTexture(menu->plus, menu->plust, sfTrue);
    sfSprite_setTexture(menu->minus, menu->minust, sfTrue);
    sfRenderWindow_drawSprite(global->window, menu->minus, NULL);
    sfRenderWindow_drawSprite(global->window, menu->plus, NULL);
}

void display_score(global_t *global, menu_t *menu)
{
    menu->font = sfFont_createFromFile("resource/font/text.ttf");
    menu->text_music = sfText_create();
    sfText_setString(menu->text_music, "Music :");
    sfText_setFont(menu->text_music, menu->font);
    sfText_setColor(menu->text_music, sfBlack);
    sfText_setCharacterSize(menu->text_music, 50);
    sfText_setPosition(menu->text_music, (sfVector2f){850, 300});
    sfRenderWindow_drawText(global->window, menu->text_music, NULL);
}
