/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** my_rpg, enemis.c
*/

#include "my.h"
#include "rpg.h"

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

void create_all(global_t *global)
{
    char *res = "resource/fight/arrow.png";
    char *res2 = "resource/fight/spe_attack.png";
    char *res3 = "resource/fight/attack.png";

    global->fight->wp1s = sfSprite_create();
    global->fight->boss1s = sfSprite_create();
    select_enemis(global);
    global->fight->players = sfSprite_create();
    choose_who_create(global);
    global->fight->arrows = sfSprite_create();
    global->fight->arrowt = sfTexture_createFromFile(res, NULL);
    global->fight->arrowt = sfTexture_createFromFile(res, NULL);
    global->fight->attack_spes = sfSprite_create();
    global->fight->attack_spet = sfTexture_createFromFile(res2, NULL);
    global->fight->attacks = sfSprite_create();
    global->fight->attackt = sfTexture_createFromFile(res3, NULL);
}

void init_to_int(global_t *global)
{
    if (global->fight->enemis == 1) {
        global->gameplay->boss->win_vs_final_boss = 1;
        global->gameplay->boss->quest_fboss += 1;
    }
    if (global->fight->enemis == 2) {
        global->gameplay->boss->win_vs_desert_boss = 1;
        global->gameplay->boss->quest_fboss += 1;
    }
    if (global->fight->enemis == 3) {
        global->gameplay->boss->win_vs_winter_boss = 1;
        global->gameplay->boss->quest_fboss += 1;
    }
    if (global->fight->enemis == 4) {
        global->gameplay->boss->win_vs_hl_boss = 1;
        global->gameplay->boss->quest_fboss += 1;
    }
    if (global->fight->enemis == 5)
        global->gameplay->boss->win_vs_volc_boss = 1;
}