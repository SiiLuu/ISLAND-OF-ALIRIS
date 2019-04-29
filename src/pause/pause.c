/*
** EPITECH PROJECT, 2019
** main fonction
** File description:
** my_defender, main function
*/

#include "my.h"
#include "rpg.h"

void pause_create(global_t *global)
{
    global->pause->back = sfSprite_create();
    global->pause->st_inv->wp_inv = sfSprite_create();
    global->pause->st_inv->equip = sfSprite_create();
    global->pause->inv = sfSprite_create();
    global->pause->backt = sfTexture_createFromFile("resource/menu/menu.jpg", NULL);
    global->pause->st_inv->wp_invt = sfTexture_createFromFile("resource/menu/menu_pause.jpg", NULL);
    global->pause->invt = sfTexture_createFromFile("resource/menu/s1.png", NULL);
    global->pause->st_inv->equipt = sfTexture_createFromFile("resource/menu/equip.png", NULL);
    sfSprite_setTexture(global->pause->back, global->pause->backt, sfTrue);
    sfSprite_setTexture(global->pause->inv, global->pause->invt, sfTrue);
    sfSprite_setTexture(global->pause->st_inv->wp_inv, global->pause->st_inv->wp_invt, sfTrue);
    sfSprite_setTexture(global->pause->st_inv->equip, global->pause->st_inv->equipt, sfTrue);
    sfSprite_setScale(global->pause->inv, (sfVector2f){0.60, 0.60});
    sfSprite_setScale(global->pause->st_inv->equip, (sfVector2f){3.5, 3.5});
}

void display_player_inv(global_t *global, sfSprite *spr)
{
    sfSprite_setScale(spr, (sfVector2f){1.3, 1.3});
    sfSprite_setPosition(spr, (sfVector2f){1210, 200});
    sfRenderWindow_drawSprite(global->window, spr, NULL);
}

void chose_good_char(global_t *global)
{
    if (global->gameplay->player_nb == 1)
        display_player_inv(global, global->choose_char->player1_sprite);
    if (global->gameplay->player_nb == 2)
        display_player_inv(global, global->choose_char->player2_sprite);
    if (global->gameplay->player_nb == 3)
        display_player_inv(global, global->choose_char->player3_sprite);
    if (global->gameplay->player_nb == 4)
        display_player_inv(global, global->choose_char->player4_sprite);
}

void display_pause(global_t *global)
{
    if (global->scn == 2) {
        sfRenderWindow_clear(global->window, sfBlack);
        sfView_reset(global->gameplay->view, (sfFloatRect){0, 0, 1920, 1080});
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
    if (global->scn == 3) {
        sfRenderWindow_clear(global->window, sfBlack);
        sfRenderWindow_drawSprite(global->window, global->pause->st_inv->wp_inv, NULL);
        sfSprite_setPosition(global->pause->st_inv->equip, (sfVector2f){1000, 100});
        sfRenderWindow_drawSprite(global->window, global->pause->st_inv->equip, NULL);
        chose_good_char(global);
        sfRenderWindow_display(global->window);
    }
}

int but_is_c(sfEvent event, sfSprite *spr)
{
    sfVector2f target_pos;
    int x = event.mouseButton.x;
    int y = event.mouseButton.y;

    target_pos = sfSprite_getPosition(spr);
    if (x >= target_pos.x + 20 &&
        x <= target_pos.x + 260 &&
        y >= target_pos.y + 90 &&
        y <= target_pos.y + 200)
        return (1);
    return (0);
}