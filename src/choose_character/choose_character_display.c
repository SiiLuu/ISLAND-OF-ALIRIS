/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** menu
*/

#include "my.h"
#include "rpg.h"

void choose_display(global_t *global)
{
    sfRenderWindow_clear(global->window, sfBlack);
    sfRenderWindow_drawSprite(global->window,
                                global->choose_char->player1_sprite, NULL);
    sfRenderWindow_drawSprite(global->window,
                                global->choose_char->player2_sprite, NULL);
    sfRenderWindow_drawSprite(global->window,
                                global->choose_char->player3_sprite, NULL);
    sfRenderWindow_drawSprite(global->window,
                                global->choose_char->player4_sprite, NULL);
    sfRenderWindow_display(global->window);
}