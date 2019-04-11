/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** settings
*/

#include "my.h"

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

int settings(global_t *global, menu_t *menu)
{
    if (global->xmouse >= 20 && global->xmouse <= 180
        && global->ymouse >= 100 && global->ymouse <= 250) {
        sfRenderWindow_drawSprite(global->window, menu->wp, NULL);
        display_score(global, menu);
        display_sound_settings(global, menu);
        sfRenderWindow_display(global->window);
        while (1){
            sfRenderWindow_pollEvent(global->window, &global->event);
            if (global->event.type == sfEvtClosed) {
                sfText_destroy(menu->text_music);
                sfFont_destroy(menu->font);
                return (1);
            }
        }
        sfText_destroy(menu->text_music);
        sfFont_destroy(menu->font);
    }
    return (0);
}