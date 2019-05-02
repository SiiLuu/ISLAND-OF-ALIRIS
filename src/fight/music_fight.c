/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** my_rpg, music_fight.c
*/

#include "my.h"
#include "rpg.h"

void music_fight(global_t *global)
{
    const char *te = "resource/fight_music.ogg";

    sfMusic_pause(global->menu->settings->musique);
    global->fight->musique = sfMusic_createFromFile(te);
    sfMusic_play(global->fight->musique);
    sfMusic_setLoop(global->fight->musique, 1);
}

void fight_music_destroy(global_t *global)
{
    sfMusic_stop(global->fight->musique);
    sfMusic_destroy(global->fight->musique);
    sfMusic_play(global->menu->settings->musique);
    sfMusic_setLoop(global->menu->settings->musique, 1);
}