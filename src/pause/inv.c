/*
** EPITECH PROJECT, 2019
** main fonction
** File description:
** my_defender, main function
*/

#include "my.h"
#include "rpg.h"

void display_player_inv(global_t *global, sfSprite *spr)
{
    sfSprite_setScale(spr, (sfVector2f){1.2, 1.2});
    sfSprite_setPosition(spr, (sfVector2f){1205, 200});
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