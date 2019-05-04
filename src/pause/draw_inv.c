/*
** EPITECH PROJECT, 2019
** main fonction
** File description:
** my_defender, main function
*/

#include "my.h"
#include "rpg.h"

void display_inv2(global_t *global)
{
    sfRenderWindow_clear(global->window, sfBlack);
    sfRenderWindow_drawSprite(global->window,
        global->pause->st_inv->wp_inv, NULL);
    sfSprite_setPosition(global->pause->st_inv->equip,
        (sfVector2f){1000, 100});
    sfRenderWindow_drawSprite(global->window,
        global->pause->st_inv->equip, NULL);
    chose_good_char(global);
}

void draw_instruct(global_t *global)
{
    sfRenderWindow_clear(global->window, sfBlack);
    sfRenderWindow_drawSprite(global->window,
        global->pause->st_htp->ins1_bck, NULL);
    sfRenderWindow_display(global->window);
}

void draw_instruct2(global_t *global)
{
    sfRenderWindow_clear(global->window, sfBlack);
    sfRenderWindow_drawSprite(global->window,
        global->pause->st_htp->ins2_bck, NULL);
    sfRenderWindow_display(global->window);
}