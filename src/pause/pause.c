/*
** EPITECH PROJECT, 2019
** main fonction
** File description:
** my_defender, main function
*/

#include "my.h"
#include "rpg.h"

void pause_create2(global_t *global)
{
    global->pause->st_inv->comp = sfSprite_create();
    global->pause->st_inv->compt = sfTexture_createFromFile(
        "resource/menu/comp.png", NULL);
    sfSprite_setTexture(global->pause->st_inv->comp,
        global->pause->st_inv->compt, sfTrue);
    sfSprite_setScale(global->pause->st_inv->comp, (sfVector2f){3.63, 3});
    global->pause->st_inv->inv = sfSprite_create();
    global->pause->st_inv->invt = sfTexture_createFromFile(
        "resource/menu/inv.jpg", NULL);
    sfSprite_setTexture(global->pause->st_inv->inv,
        global->pause->st_inv->invt, sfTrue);
    sfSprite_setScale(global->pause->st_inv->inv, (sfVector2f){2.75, 2.75});
    global->pause->st_inv->eq = sfText_create();
    global->pause->st_inv->eqf = sfFont_createFromFile(
        "resource/font/arial.ttf");
    sfText_setFont(global->pause->st_inv->eq, global->pause->st_inv->eqf);
    sfText_setString(global->pause->st_inv->eq, "INVENTAIRE");
    sfText_setCharacterSize(global->pause->st_inv->eq, 75);
    sfText_setColor(global->pause->st_inv->eq, sfWhite);
}

void pause_create(global_t *global)
{
    global->pause->back = sfSprite_create();
    global->pause->st_inv->wp_inv = sfSprite_create();
    global->pause->st_inv->equip = sfSprite_create();
    global->pause->inv = sfSprite_create();
    global->pause->backt = sfTexture_createFromFile("resource/menu/menu.jpg",
        NULL);
    global->pause->st_inv->wp_invt = sfTexture_createFromFile(
        "resource/menu/menu_pause.jpg", NULL);
    global->pause->invt = sfTexture_createFromFile("resource/menu/s1.png",
        NULL);
    global->pause->st_inv->equipt = sfTexture_createFromFile(
        "resource/menu/equip.png", NULL);
    sfSprite_setTexture(global->pause->back, global->pause->backt, sfTrue);
    sfSprite_setTexture(global->pause->inv, global->pause->invt, sfTrue);
    sfSprite_setTexture(global->pause->st_inv->wp_inv,
        global->pause->st_inv->wp_invt, sfTrue);
    sfSprite_setTexture(global->pause->st_inv->equip,
        global->pause->st_inv->equipt, sfTrue);
    sfSprite_setScale(global->pause->inv, (sfVector2f){0.60, 0.60});
    sfSprite_setScale(global->pause->st_inv->equip, (sfVector2f){3.5, 3.5});
    pause_create2(global);
}

void display_inv(global_t *global)
{
    sfRenderWindow_clear(global->window, sfBlack);
    sfRenderWindow_drawSprite(global->window,
        global->pause->st_inv->wp_inv, NULL);
    sfSprite_setPosition(global->pause->st_inv->equip,
        (sfVector2f){1000, 100});
    sfRenderWindow_drawSprite(global->window,
        global->pause->st_inv->equip, NULL);
    chose_good_char(global);
    sfSprite_setPosition(global->pause->st_inv->comp, (sfVector2f){1000, 745});
    sfRenderWindow_drawSprite(global->window, global->pause->st_inv->comp,
        NULL);
    sfSprite_setPosition(global->pause->st_inv->inv, (sfVector2f){200, 260});
    sfRenderWindow_drawSprite(global->window, global->pause->st_inv->inv,
        NULL);
    sfText_setPosition(global->pause->st_inv->eq, (sfVector2f){320, 100});
    sfRenderWindow_drawText(global->window, global->pause->st_inv->eq, NULL);
    sfRenderWindow_display(global->window);
}

void draw_pause(global_t *global)
{
    sfRenderWindow_clear(global->window, sfBlack);
    sfView_reset(global->gameplay->view, (sfFloatRect)
        {0, 0, 1920, 1080});
    sfRenderWindow_setView(global->window, global->gameplay->view);
    sfRenderWindow_drawSprite(global->window, global->pause->back, NULL);
    sfSprite_setPosition(global->menu->start1, (sfVector2f){780, 150});
    sfRenderWindow_drawSprite(global->window, global->menu->start1, NULL);
    sfSprite_setPosition(global->menu->quit1, (sfVector2f){780, 650});
    sfRenderWindow_drawSprite(global->window, global->menu->quit1, NULL);
    sfSprite_setPosition(global->pause->inv, (sfVector2f){780, 400});
    sfRenderWindow_drawSprite(global->window, global->pause->inv, NULL);
    sfRenderWindow_display(global->window);
}

void display_pause(global_t *global)
{
    if (global->scn == 2) {
        draw_pause(global);
    }
    if (global->scn == 3) {
        display_inv(global);
    }
}