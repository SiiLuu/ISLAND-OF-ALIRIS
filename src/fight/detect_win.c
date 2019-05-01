/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** my_rpg, detect_win.c
*/

#include "my.h"
#include "rpg.h"


void player_loose_display(global_t *global)
{
    sfSprite_setTextureRect(global->fight->players, global->fight->rect);
    sfRenderWindow_clear(global->window, sfBlack);
    sfRenderWindow_drawSprite(global->window, global->fight->wp1s, NULL);
    sfRenderWindow_drawSprite(global->window, global->fight->boss1s, NULL);
    sfRenderWindow_drawSprite(global->window, global->fight->players, NULL);
}

void player_win_display(global_t *global)
{
    sfSprite_setTextureRect(global->fight->players, global->fight->rect);
    sfSprite_setColor(global->fight->boss1s, sfTransparent);
    sfRenderWindow_clear(global->window, sfBlack);
    sfRenderWindow_drawSprite(global->window, global->fight->wp1s, NULL);
    sfRenderWindow_drawSprite(global->window, global->fight->boss1s, NULL);
    sfRenderWindow_drawSprite(global->window, global->fight->players, NULL);
}

void player_loose(global_t *global)
{
    sfFont* font = sfFont_createFromFile("resource/font/text.ttf");
    sfText* text = sfText_create();
    sfClock *clocks = sfClock_create();

    sfText_setString(text, "GAME OVER");
    sfText_setFont(text, font);
    sfText_setColor(text, sfBlack);
    sfText_setCharacterSize(text, 350);
    sfText_setPosition(text, (sfVector2f){200, 100});
    global->fight->rect.left = 384;
    global->fight->rect.top = 320;
    player_loose_display(global);
    sfRenderWindow_drawText(global->window, text, NULL);
    draw_fight_info(global);
    sfRenderWindow_display(global->window);
    while (sfTime_asMilliseconds(sfClock_getElapsedTime(
            global->fight->clocks)) < 10000);
    sfFont_destroy(font);
    sfText_destroy(text);
    sfClock_destroy(clocks);
}

void player_win(global_t *global)
{
    sfFont* font = sfFont_createFromFile("resource/font/text.ttf");
    sfText* text = sfText_create();
    sfClock *clocks = sfClock_create();

    sfText_setString(text, "VICTORY !");
    sfText_setFont(text, font);
    sfText_setColor(text, sfBlack);
    sfText_setCharacterSize(text, 350);
    sfText_setPosition(text, (sfVector2f){300, 100});
    global->fight->rect.left = 448;
    global->fight->rect.top = 64;
    player_win_display(global);
    sfRenderWindow_drawText(global->window, text, NULL);
    draw_fight_info(global);
    sfRenderWindow_display(global->window);
    while (sfTime_asMilliseconds(sfClock_getElapsedTime(
            global->fight->clocks)) < 5000);
    sfFont_destroy(font);
    sfText_destroy(text);
    sfClock_destroy(clocks);
}

int dectect_win(global_t *global)
{
    if (global->fight->life1 <= 0) {
        player_loose(global);
        exit (0);
    }
    if (global->fight->life2 <= 0) {
        global->fight->win_vs_final_boss = 1;
        player_win(global);
        return (1);
    }
    return (0);
}