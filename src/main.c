/*
** EPITECH PROJECT, 2019
** main fonction
** File description:
** my_defender, main function
*/

#include "my.h"

int main_loop(global_t *global, menu_t *menu)
{
    sfClock *clocks = sfClock_create();

    sfRenderWindow_setFramerateLimit(global->window, 60);
    if (menu_start(global, menu, 0))
        return (0);
    return (0);
    while (sfRenderWindow_isOpen(global->window)) {
        if (sfTime_asMilliseconds(sfClock_getElapsedTime(clocks)) > 5) {
            sfClock_restart(clocks);
        }
    }
    sfClock_destroy(clocks);
    return (0);
}

void main_function(void)
{
    global_t *global;
    menu_t *menu;

    menu = malloc(sizeof(menu_t) * 1);
    global = malloc(sizeof(global_t) * 1);
    sfVideoMode mode = {1920, 1080, 32};
    global->window = sfRenderWindow_create(mode, "my_RPG",
                                            sfResize | sfClose, NULL);
    menu->sound = 0;
    music_game(menu);
    main_loop(global, menu);
    music_destroy(menu);
    sfRenderWindow_destroy(global->window);
    free(global);
    free(menu);
}

int main(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        my_putstr("USAGE:\n        ./my_defender\n");
        my_putstr("DESCRIPTION:\n\tto win prevent the enemies to save\n");
        my_putstr("\tthemselves in the water. for that place turrets on\n");
        my_putstr("\tthe map to kill enemies, attention your money is\n");
        my_putstr("\tnot infinite and all the turrets are different\n ");
        my_putstr("\twith different abilities. GOOD LUCK TO YOU !\n");
        return (1);
    }
    else
        main_function();
    return (1);
}