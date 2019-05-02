/*
** EPITECH PROJECT, 2019
** main fonction
** File description:
** my_defender, main function
*/

#include "my.h"
#include "rpg.h"

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
    sfText_setPosition(global->pause->st_inv->eq2, (sfVector2f){1035, 285});
    sfRenderWindow_drawText(global->window, global->pause->st_inv->eq2, NULL);
    sfText_setPosition(global->pause->st_inv->eq3, (sfVector2f){1050, 770});
    sfRenderWindow_drawText(global->window, global->pause->st_inv->eq3, NULL);
    sfRenderWindow_display(global->window);
}

void draw_pause(global_t *global)
{
    sfRenderWindow_clear(global->window, sfBlack);
    sfView_reset(global->gameplay->view, (sfFloatRect)
        {0, 0, 1920, 1080});
    sfRenderWindow_setView(global->window, global->gameplay->view);
    sfRenderWindow_drawSprite(global->window, global->pause->back, NULL);
    sfSprite_setPosition(global->menu->start1, (sfVector2f){780, 100});
    sfRenderWindow_drawSprite(global->window, global->menu->start1, NULL);
    sfSprite_setPosition(global->menu->quit1, (sfVector2f){780, 700});
    sfRenderWindow_drawSprite(global->window, global->menu->quit1, NULL);
    sfSprite_setPosition(global->pause->inv, (sfVector2f){780, 300});
    sfRenderWindow_drawSprite(global->window, global->pause->inv, NULL);
    sfSprite_setPosition(global->pause->quest, (sfVector2f){780, 500});
    sfRenderWindow_drawSprite(global->window, global->pause->quest, NULL);
    sfRenderWindow_display(global->window);
}

void draw_quest(global_t *global)
{
    sfRenderWindow_clear(global->window, sfBlack);
    sfRenderWindow_drawSprite(global->window,
        global->pause->st_inv->wp_inv, NULL);
    sfSprite_setPosition(global->pause->st_quest->board,
        (sfVector2f){270, 10});
    sfRenderWindow_drawSprite(global->window,
        global->pause->st_quest->board, NULL);
    sfText_setPosition(global->pause->st_quest->tquest,
        (sfVector2f){420, 150});
    sfRenderWindow_drawText(global->window, global->pause->st_quest->tquest,
        NULL);
    sfText_setPosition(global->pause->st_quest->tquest2,
        (sfVector2f){430, 475});
    sfRenderWindow_drawText(global->window, global->pause->st_quest->tquest2,
        NULL);
    sfRenderWindow_display(global->window);
}

void draw_how_to_play(global_t *global)
{
    sfRenderWindow_clear(global->window, sfBlack);
    sfRenderWindow_drawSprite(global->window,
        global->pause->st_htp->htp_bck, NULL);
    sfRenderWindow_display(global->window);
}

void display_pause(global_t *global)
{
    global->pause->st_htp->loading = sfClock_create();

    if (global->scn == 0) {
        draw_how_to_play(global);
        while (sfTime_asSeconds(sfClock_getElapsedTime(
            global->pause->st_htp->loading)) < 5);
        global->scn = 1;
    }
    if (global->scn == 2)
        draw_pause(global);
    if (global->scn == 3)
        display_inv(global);
    if (global->scn == 4)
        draw_quest(global);
}