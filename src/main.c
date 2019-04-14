/*
** EPITECH PROJECT, 2019
** main fonction
** File description:
** my_defender, main function
*/

#include "my.h"
#include "rpg.h"

void game_parameters(gameplay_t *gameplay, global_t *global)
{
    check_events(global, gameplay);
    draw_sprites(gameplay, global);
}


int main_loop(global_t *global, menu_t *menu, gameplay_t *gameplay)
{
    gameplay->clocks = sfClock_create();
    gameplay->view = sfView_create();

    gameplay->x = (1080 / 2) - 64;
    gameplay->y = (1920 / 2) - 64;
    init_texture(gameplay);
    sfRenderWindow_setFramerateLimit(global->window, 60);
    if (menu_start(global, menu, 0) || global->event.type == sfEvtClosed) {
        sfClock_destroy(gameplay->clocks);
        return (0);
    }
    while (sfRenderWindow_isOpen(global->window)) {
        if (sfTime_asMilliseconds(sfClock_getElapsedTime(gameplay->clocks)) > 5) {
            game_parameters(gameplay, global);
            sfClock_restart(gameplay->clocks);
        }
    }
    return (0);
}

void destroy_all(menu_t *menu)
{
    sfSprite_destroy(menu->wp);
    sfSprite_destroy(menu->start1);
    sfSprite_destroy(menu->quit1);
    sfSprite_destroy(menu->start2);
    sfSprite_destroy(menu->sounds);
    sfSprite_destroy(menu->nosound);
    sfSprite_destroy(menu->settings);
    sfTexture_destroy(menu->wpt);
    sfTexture_destroy(menu->start1t);
    sfTexture_destroy(menu->quit1t);
    sfTexture_destroy(menu->start2t);
    sfTexture_destroy(menu->soundt);
    sfTexture_destroy(menu->no_soundt);
    sfTexture_destroy(menu->settingst);
}

void main_function(void)
{
    global_t *global;
    menu_t *menu;
    gameplay_t *gameplay;

    gameplay = malloc(sizeof(gameplay_t) * 1);
    menu = malloc(sizeof(menu_t) * 1);
    global = malloc(sizeof(global_t) * 1);
    sfVideoMode mode = {3008, 2000, 32};
    global->window = sfRenderWindow_create(mode, "my_RPG",
                                            sfResize | sfClose, NULL);
    menu->sound = 0;
    menu->nbr_bar = 4;
    music_game(menu);
    main_loop(global, menu, gameplay);
    music_destroy(menu);
    sfRenderWindow_destroy(global->window);
    destroy_all(menu);
    free(global);
    free(gameplay);
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
