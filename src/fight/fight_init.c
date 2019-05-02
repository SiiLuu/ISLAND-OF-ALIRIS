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
    if (global->fight->enemis == 2)
        global->fight->boss1t = sfTexture_createFromFile(
        "resource/fight/Dragon.png", NULL);
    if (global->fight->enemis == 3) {
        global->fight->boss1t = sfTexture_createFromFile(
        "resource/fight/God.png", NULL);
        global->fight->wp1t = sfTexture_createFromFile(
        "resource/fight/IceCave.png", NULL);
    }
}

void create_all(global_t *global)
{
    global->fight->wp1s = sfSprite_create();
    global->fight->boss1s = sfSprite_create();
    select_enemis(global);
    global->fight->players = sfSprite_create();
    choose_who_create(global);
    global->fight->arrows = sfSprite_create();
    global->fight->arrowt = sfTexture_createFromFile("resource/fight/arrow.png",
                                                        NULL);
    global->fight->attack_spes = sfSprite_create();
    global->fight->attack_spet = sfTexture_createFromFile("resource/fight/test.png",
                                                            NULL);
    global->fight->attacks = sfSprite_create();
    global->fight->attackt = sfTexture_createFromFile("resource/fight/test2.png",
                                                        NULL);
}

void texture_scale(global_t *global)
{
    sfSprite_setTexture(global->fight->wp1s, global->fight->wp1t, sfTrue);
    sfSprite_setScale(global->fight->wp1s, (sfVector2f){2.10, 1.90});
    if (global->fight->enemis == 2)
        sfSprite_setScale(global->fight->boss1s, (sfVector2f){1.2, 1.2});
    sfSprite_setTexture(global->fight->boss1s, global->fight->boss1t, sfTrue);
    sfSprite_setPosition(global->fight->boss1s, (sfVector2f){50, 500});
    sfSprite_setTexture(global->fight->players,
                        global->fight->playert, sfTrue);
    sfSprite_setTextureRect(global->fight->players, global->fight->rect);
    sfSprite_setScale(global->fight->players, (sfVector2f){2.10, 2.10});
    sfSprite_setPosition(global->fight->players, (sfVector2f){1200, 700});
    sfSprite_setTexture(global->fight->arrows, global->fight->arrowt, sfTrue);
    sfSprite_setPosition(global->fight->attack_spes, (sfVector2f){1500, 800});
    sfSprite_setTexture(global->fight->attack_spes,
                        global->fight->attack_spet, sfTrue);
    sfSprite_setPosition(global->fight->attacks, (sfVector2f){1500, 900});
    sfSprite_setTexture(global->fight->attacks,
                        global->fight->attackt, sfTrue);
}

void fight_create(global_t *global)
{
    set_my_recta(global);
    create_all(global);
    texture_scale(global);
    fight_display(global);
}

void fight_destroy(global_t *global)
{
    sfSprite_destroy(global->fight->wp1s);
    sfSprite_destroy(global->fight->boss1s);
    sfSprite_destroy(global->fight->players);
    sfSprite_destroy(global->fight->arrows);
    sfSprite_destroy(global->fight->attack_spes);
    sfSprite_destroy(global->fight->attacks);
    sfClock_destroy(global->fight->clocks);
}

void set_my_recta(global_t *global)
{
    global->fight->rect.height = 64;
    global->fight->rect.width = 64;
    global->fight->rect.left = 256;
    global->fight->rect.top = 0;
    global->fight->turn = 0;
    global->fight->stamina1 = 0;
}