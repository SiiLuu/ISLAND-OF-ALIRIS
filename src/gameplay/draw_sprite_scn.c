/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** function to draw the sprites from the differents scenes
*/

#include "my.h"
#include "rpg.h"

void which_scn(global_t *global)
{
    if (global->scn == 1)
        scn_1(global);
    if (global->scn == 11)
        scn_11(global);
    if (global->scn == 20)
        scn_10(global);
    if (global->scn == 12)
        scn_12(global);
    if (global->scn == 13)
        scn_13(global);
}

void draw_sprites(global_t *global)
{
    set_cursor(global);
    global->scn = check_map_change(global, global->scn);
    if (check_scn_nbr(global->scn) == true) {
        sfSprite_setPosition(global->gameplay->sprite_man,
        (sfVector2f){global->gameplay->x, global->gameplay->y});
        sfSprite_setTextureRect(global->gameplay->sprite_man,
        global->gameplay->rect_man);
        sfRenderWindow_drawSprite(global->window,
        global->gameplay->sprite_backg, NULL);
        sfRenderWindow_drawSprite(global->window,
        global->gameplay->sprite_man, NULL);
        which_scn(global);
        sfRenderWindow_display(global->window);
    }
    if (global->scn == 5) {
        sfRenderWindow_setMouseCursorVisible(global->window, sfTrue);
        fight(global);
    }
    display_pause(global);
}

void draw_sprites_scn_1(global_t *global)
{
    sfRenderWindow_drawSprite(global->window,
    global->gameplay->pnj->sprite_pnj_d, NULL);
    sfRenderWindow_drawSprite(global->window,
    global->gameplay->pnj->sprite_pnj_ed, NULL);
    sfRenderWindow_drawSprite(global->window,
    global->gameplay->pnj->sprite_pnj_pech, NULL);
    sfRenderWindow_drawSprite(global->window,
    global->gameplay->pnj->sprite_pnj_bot, NULL);
    sfRenderWindow_drawSprite(global->window,
    global->gameplay->pnj->sp_pnj_volc, NULL);
    sfRenderWindow_drawSprite(global->window,
    global->gameplay->boss->sp_final_boss, NULL);
    sfRenderWindow_drawSprite(global->window,
    global->gameplay->boss->sp_winter_boss, NULL);
    sfRenderWindow_drawSprite(global->window,
    global->gameplay->boss->sp_desert_boss, NULL);
    sfRenderWindow_drawSprite(global->window,
    global->gameplay->boss->sp_hl_boss, NULL);
}

void set_cursor(global_t *global)
{
    if (global->scn == 2 || global->scn == 3 || global->scn == 4 ||
        global->scn == 5)
        sfRenderWindow_setMouseCursorVisible(global->window, sfTrue);
    else
        sfRenderWindow_setMouseCursorVisible(global->window, sfFalse);
}