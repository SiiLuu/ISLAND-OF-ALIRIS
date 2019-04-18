/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** menu
*/

#include "my.h"
#include "rpg.h"

int check_menu(global_t *global, int x, int y)
{
    if (settings(global, x, y))
        return (0);
    else
        menu_choose_create_display(global, 1);
    if (x >= 795 && x <= 1050 && y >= 237 && y <= 350)
        return (0);
    if (x >= 800 && x <= 1050 && y >= 562 && y <= 694) {
        if (destroy_menu(global) == 1)
            return (0);
        return (1);
    }
    return (3);
}