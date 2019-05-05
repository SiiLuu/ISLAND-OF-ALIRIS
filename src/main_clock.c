/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** game in a clock
*/

#include "my.h"
#include "rpg.h"

void game_parameters(global_t *global)
{
    check_events(global);
    draw_sprites(global);
}

int game_in_clock(global_t *global)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(
        global->gameplay->clocks)) > 5) {
        if (global->fight->loose == 1)
            return (1);
        game_parameters(global);
        sfClock_restart(global->gameplay->clocks);
    }
    return (0);
}