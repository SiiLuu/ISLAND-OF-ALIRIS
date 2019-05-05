/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** main function
*/

#include "my.h"
#include "rpg.h"

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
        if (game_in_clock(global) == 1) {
            my_putstr("YOU LOSE !! Restart the game to try again");
            return (0);
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

void free_all(global_t *global)
{
    free(global->menu);
    free(global->pause);
    free(global->gameplay->item);
    free(global->pause->st_inv);
    free(global->pause->st_quest);
    free(global->pause->st_htp);
    free(global->choose_char);
    free(global->menu->settings);
    free(global->gameplay->pnj);
    free(global->gameplay->pnj->status);
    free(global->gameplay->boss);
    free(global->fight);
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
        free_all(global);
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
