/*
** EPITECH PROJECT, 2019
** main fonction
** File description:
** my_rpg, main function
*/
#include "my.h"
#include "rpg.h"

void game_parameters(global_t *global)
{
    check_events(global);
    draw_sprites(global);
}

int main_loop(global_t *global)
{
    global->gameplay->clocks = sfClock_create();
    global->gameplay->view = sfView_create();

    sfRenderWindow_setFramerateLimit(global->window, 60);
    if (menu_start(global, 0) || global->event.type == sfEvtClosed) {
        sfClock_destroy(global->gameplay->clocks);
        return (0);
    }
    init_texture(global);
    pause_create(global);
    global->scn = -2;
    sfView_reset(global->gameplay->view, (sfFloatRect){0, 98, 1920, 1080});
    sfRenderWindow_setView(global->window, global->gameplay->view);
    while (sfRenderWindow_isOpen(global->window))
        if (sfTime_asMilliseconds(sfClock_getElapsedTime(
            global->gameplay->clocks)) > 5) {
            game_parameters(global);
            sfClock_restart(global->gameplay->clocks);
        }
    return (0);
}

void destroy_all(global_t *global)
{
    sfSprite_destroy(global->menu->wp);
    sfSprite_destroy(global->menu->start1);
    sfSprite_destroy(global->menu->quit1);
    sfSprite_destroy(global->menu->start2);
    sfSprite_destroy(global->menu->sounds);
    sfSprite_destroy(global->menu->nosound);
    sfSprite_destroy(global->menu->settingsa);
    sfTexture_destroy(global->menu->wpt);
    sfTexture_destroy(global->menu->start1t);
    sfTexture_destroy(global->menu->quit1t);
    sfTexture_destroy(global->menu->start2t);
    sfTexture_destroy(global->menu->soundt);
    sfTexture_destroy(global->menu->no_soundt);
    sfTexture_destroy(global->menu->settings->settingst);
}

void clean_bytes(global_t *global, char status)
{
    if (status == 'm') {
        global->menu = malloc(sizeof(menu_t) * 1);
        global->pause = malloc(sizeof(pause_t) * 1);
        global->gameplay->item = malloc(sizeof(item_t) * 1);
        global->pause->st_inv = malloc(sizeof(inv_t) * 1);
        global->pause->st_quest = malloc(sizeof(quest_t) * 1);
        global->pause->st_htp = malloc(sizeof(htp_t) * 1);
        global->choose_char = malloc(sizeof(choose_char_t) * 1);
        global->menu->settings = malloc(sizeof(settings_t) * 1);
        global->gameplay->pnj = malloc(sizeof(pnj_t) * 1);
        global->gameplay->pnj->status = malloc(sizeof(pnj_t) * 1);
        global->gameplay->boss = malloc(sizeof(boss_t) * 1);
        global->fight = malloc(sizeof(fight_t) * 1);
    }
    if (status == 'f') {
        free(global->menu->settings);
        free(global->menu);
        free(global);
    }
}

void main_function(global_t *global)
{
    clean_bytes(global, 'm');
    sfVideoMode mode = {1920, 1080, 32};
    global->window = sfRenderWindow_create(mode, "TAILS OF ALIRIS",
                                            sfFullscreen | sfClose, NULL);
    global->menu->settings->sound = 0;
    global->menu->settings->nbr_bar = 4;
    global->gameplay->lenght = 6000;
    global->gameplay->width = 6000;
    global->scn = 0;
    global->gameplay->x = 300;
    global->gameplay->y = 600;
    global->fight->loose = 0;
    music_game(global);
    main_loop(global);
    music_destroy(global);
    sfRenderWindow_destroy(global->window);
    destroy_all(global);
    clean_bytes(global, 'f');
}

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
