/*
** EPITECH PROJECT, 2019
** main fonction
** File description:
** my_defender, main function
*/

#include "my.h"
#include "rpg.h"

sfText *create_text(sfText *text, sfFont *fon)
{
    text = sfText_create();
    fon = sfFont_createFromFile("resource/font/arial.ttf");
    sfText_setFont(text, fon);
    sfText_setColor(text, sfWhite);
    return (text);
}

void init_texts(global_t *global)
{
    global->pause->st_inv->eq = create_text(global->pause->st_inv->eq,
        global->pause->st_inv->eqf);
    global->pause->st_inv->eq2 = create_text(global->pause->st_inv->eq2,
         global->pause->st_inv->eqf);
    global->pause->st_inv->eq3 = create_text(global->pause->st_inv->eq3,
         global->pause->st_inv->eqf);
    sfText_setString(global->pause->st_inv->eq, "INVENTORY");
    sfText_setString(global->pause->st_inv->eq2,
    "Main Weapon\t\t\t\t\t\t\t\t\t\t   \
    Secondary Weapon\n\n\n\n\n\n\n\nMain Defense\t\t\t\t\t\t\t\t\t\t \
    Secondary Defense\n\n\n\n\n\n\n\n\nMain Power\t\t\t\t\t\t\t\t\t\t\t  \
    Secondary Power");
    sfText_setCharacterSize(global->pause->st_inv->eq, 75);
    sfText_setCharacterSize(global->pause->st_inv->eq2, 20);
    sfText_setCharacterSize(global->pause->st_inv->eq3, 30);
    init_texts_quest(global);
}

void pause_create3(global_t *global)
{
    global->pause->st_quest->board = sfSprite_create();
    global->pause->st_quest->boardt = sfTexture_createFromFile(
        "resource/menu/quest.png", NULL);
    sfSprite_setTexture(global->pause->st_quest->board,
        global->pause->st_quest->boardt, sfTrue);
    sfSprite_setScale(global->pause->st_quest->board, (sfVector2f){2.3, 2.3});
}

void pause_create2(global_t *global)
{
    pause_create3(global);
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
    global->pause->quest = sfSprite_create();
    global->pause->questt = sfTexture_createFromFile(
        "resource/menu/but_quest.png", NULL);
    sfSprite_setTexture(global->pause->quest, global->pause->questt, sfTrue);
    sfSprite_setScale(global->pause->quest, (sfVector2f){0.60, 0.60});
    init_texts(global);
    init_how_to_play(global);
    init_instruct(global);
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
    global->pause->invt = sfTexture_createFromFile("resource/menu/but_inv.png",
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