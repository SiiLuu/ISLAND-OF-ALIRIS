/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** check all events
*/

#include "my.h"
#include "rpg.h"

int check_events(global_t *global)
{
    while (sfRenderWindow_pollEvent(global->window, &global->event)) {
        check_interaction(global);
        check_interaction_village(global);
        check_interaction_fcp(global);
        check_interaction_castel(global);
        check_first_events(global);
        check_next_events(global);
        check_events_scn(global);
        check_events_scn_2(global);
    }
    check_monster_dead(global);
    return (0);
}