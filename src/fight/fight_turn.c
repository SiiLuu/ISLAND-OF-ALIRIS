/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** my_rpg, fight.c
*/

#include "my.h"
#include "rpg.h"

void turn_boss(global_t *global)
{
    sfFont* font = sfFont_createFromFile("resource/font/text.ttf");
    sfText* text = sfText_create();
    sfClock *clocks = sfClock_create();
    static bool x = 0;

    sfText_setString(text, "You took 10hp");
    global->fight->life1 -= 10;
    sfText_setFont(text, font);
    sfText_setColor(text, sfBlack);
    sfText_setCharacterSize(text, 50);
    sfText_setPosition(text, (sfVector2f){750, 300});
    display_elementary(global);
    if (x == 1)
        sfRenderWindow_drawText(global->window, text, NULL);
    sfRenderWindow_display(global->window);
    while (sfTime_asMilliseconds(sfClock_getElapsedTime(
            global->fight->clocks)) < 3000);
    sfFont_destroy(font);
    sfText_destroy(text);
    sfClock_destroy(clocks);
    x = 1;
}

sfText *turn_player_text(global_t *global, sfText* text)
{
    if (global->fight->stamina_used == 1) {
        global->fight->stamina_used = 0;
        sfText_setString(text, "Critical ! Your attack deals 25hp");
        global->fight->life2 -= 25;
    } else {
        sfText_setString(text, "Your attack deals 10hp");
        global->fight->life2 -= 10;
    }
    return (text);
}

void turn_player(global_t *global)
{
    sfFont* font = sfFont_createFromFile("resource/font/text.ttf");
    sfText* text = sfText_create();
    sfClock *clocks = sfClock_create();

    text = turn_player_text(global, text);
    sfText_setFont(text, font);
    sfText_setColor(text, sfBlack);
    sfText_setCharacterSize(text, 50);
    sfText_setPosition(text, (sfVector2f){650, 300});
    display_elementary(global);
    sfRenderWindow_drawText(global->window, text, NULL);
    sfRenderWindow_display(global->window);
    while (sfTime_asMilliseconds(sfClock_getElapsedTime(
            global->fight->clocks)) < 1500);
    sfFont_destroy(font);
    sfText_destroy(text);
    sfClock_destroy(clocks);
}

void check_turn(global_t *global)
{
    if (global->fight->turn == 0) {
        sfSprite_setPosition(global->fight->arrows, (sfVector2f){1090, 700});
        turn_boss(global);
        global->fight->turn = 0;
    }
    else if (global->fight->turn == 1) {
        sfSprite_setPosition(global->fight->arrows, (sfVector2f){0, 700});
        turn_player(global);
        wait(global);
    }
}

void choose_who_create(global_t *global)
{
    sfTexture_destroy(global->fight->playert);
    if (global->gameplay->player_nb == 1)
        global->fight->playert = sfTexture_createFromFile(
            "resource/Sprite player/Actor1_4.png", NULL);
    if (global->gameplay->player_nb == 4)
        global->fight->playert = sfTexture_createFromFile(
            "resource/Sprite player/Actor1_7.png", NULL);
    if (global->gameplay->player_nb == 2)
        global->fight->playert = sfTexture_createFromFile(
            "resource/Sprite player/Actor2_2.png", NULL);
    if (global->gameplay->player_nb == 3)
        global->fight->playert = sfTexture_createFromFile(
            "resource/Sprite player/Actor2_5.png", NULL);
    sfSprite_setScale(global->fight->players, (sfVector2f){1.90, 1.90});
}