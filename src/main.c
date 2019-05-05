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
        my_putstr("USAGE:\n        ./my_defender\n");
        my_putstr("DESCRIPTION:\n\tto win prevent the enemies to save\n");
        my_putstr("\tthemselves in the water. for that place turrets on\n");
        my_putstr("\tthe map to kill enemies, attention your money is\n");
        my_putstr("\tnot infinite and all the turrets are different\n ");
        my_putstr("\twith different abilities. GOOD LUCK TO YOU !\n");
        return (1);
    }
    if (open_file(global) == 84)
        return (84);
    else
        main_function(global);
    free(global->gameplay);
    return (1);
}
