/*
** EPITECH PROJECT, 2019
** main fonction
** File description:
** my_rpg, main function
*/
#include "my.h"
#include "rpg.h"

int main(int ac, char **av)
{
    global_t *global = malloc(sizeof(global_t) * 1);

    global->gameplay = malloc(sizeof(gameplay_t) * 1);
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        my_putstr("USAGE:\n        ./my_rpg\n");
        my_putstr("DESCRIPTION:\n\tFollow the adventure of our hero ");
        my_putstr("through \n\tmany events on the island of Aliris.\n");
        my_putstr("\tFollow the quests to save the local inhabitants\n");
        my_putstr("\tand protect them against the mythical monsters.\n ");
        my_putstr("\tGOOD LUCK TO YOU !\n");
        return (1);
    }
    if (open_file(global) == 84)
        return (84);
    else
        main_function(global);
    free(global->gameplay);
    return (1);
}
