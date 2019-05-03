/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** my_rpg, fight.c
*/

#include "my.h"
#include "rpg.h"

void select_enemis(global_t *global)
{
    if (global->fight->enemis == 1) {
        global->fight->boss1t = sfTexture_createFromFile(
        "resource/fight/Darklord-final.png", NULL);
        global->fight->wp1t = sfTexture_createFromFile(
        "resource/fight/Ruins3.png", NULL);
    }
    if (global->fight->enemis == 2) {
        global->fight->boss1t = sfTexture_createFromFile(
        "resource/fight/Dragon.png", NULL);
        global->fight->wp1t = sfTexture_createFromFile(
        "resource/fight/Wasteland.png", NULL);
    }
    if (global->fight->enemis == 3) {
        global->fight->boss1t = sfTexture_createFromFile(
        "resource/fight/God.png", NULL);
        global->fight->wp1t = sfTexture_createFromFile(
        "resource/fight/IceCave.png", NULL);
    }
    if (global->fight->enemis == 4) {
        global->fight->boss1t = sfTexture_createFromFile(
        "resource/fight/Evilgod.png", NULL);
        global->fight->wp1t = sfTexture_createFromFile(
        "resource/fight/Dirt2.png", NULL);
    }
}

void fight_choose_player2(global_t *global)
{
    if (global->gameplay->player_nb == 2) {
        global->fight->rect.height = 48;
        global->fight->rect.width = 48;
        global->fight->rect.left = 144;
        global->fight->rect.top = 48;
        sfSprite_setTextureRect(global->fight->players, global->fight->rect);
    }
    if (global->gameplay->player_nb == 3) {
        global->fight->rect.height = 48;
        global->fight->rect.width = 48;
        global->fight->rect.left = 0;
        global->fight->rect.top = 240;
        sfSprite_setTextureRect(global->fight->players, global->fight->rect);
    }
    if (global->gameplay->player_nb == 4) {
        global->fight->rect.height = 48;
        global->fight->rect.width = 48;
        global->fight->rect.left = 288;
        global->fight->rect.top = 240;
        sfSprite_setTextureRect(global->fight->players, global->fight->rect);
    }
}

void fight_choose_player(global_t *global)
{
    if (global->gameplay->player_nb == 1 || global->gameplay->player_nb == 4) {
        global->fight->playert = sfTexture_createFromFile(
                "resource/Sprite player/Actor.png", NULL);
        sfSprite_setTexture(global->fight->players,
                        global->fight->playert, sfTrue);
    }
    if (global->gameplay->player_nb == 2 || global->gameplay->player_nb == 3) {
        global->fight->playert = sfTexture_createFromFile(
                "resource/Sprite player/player2and3.png", NULL);
        sfSprite_setTexture(global->fight->players,
                        global->fight->playert, sfTrue);
    }
    if (global->gameplay->player_nb == 1) {
        global->fight->rect.height = 48;
        global->fight->rect.width = 48;
        global->fight->rect.left = 432;
        global->fight->rect.top = 48;
        sfSprite_setTextureRect(global->fight->players, global->fight->rect);
    }
    fight_choose_player2(global);
}

int check_event_fight(global_t *global, int x, int y)
{
    if (x >= 1500 && x <= 1780 && y >= 830 && y <= 885) {
        if (global->fight->stamina1 < 20)
            return (0);
        global->fight->stamina_used = 1;
        global->fight->stamina1 -= 20;
        if (global->fight->turn == 0)
            global->fight->turn = 1;
        else if (global->fight->turn == 1)
            global->fight->turn = 0;
        fight_display(global);
    }
    else if (x >= 1500 && x <= 1730 && y >= 925 && y <= 980) {
        global->fight->stamina1 += 5;
        if (global->fight->turn == 0)
            global->fight->turn = 1;
        else if (global->fight->turn == 1)
            global->fight->turn = 0;
        fight_display(global);
    }
    return (0);
}

void check_mouse_fight(global_t *global)
{
    int x = 0;
    int y = 0;

    if (global->event.type == sfEvtMouseButtonPressed) {
        x = global->event.mouseButton.x;
        y = global->event.mouseButton.y;
        check_event_fight(global, x, y);
    }
}