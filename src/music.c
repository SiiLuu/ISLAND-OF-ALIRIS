/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** my_runner
*/

#include "my.h"
#include "rpg.h"

void music_game(global_t *global)
{
    const char *te = "resource/music.ogg";

    global->menu->settings->musique = sfMusic_createFromFile(te);
    sfMusic_play(global->menu->settings->musique);
    sfMusic_setLoop(global->menu->settings->musique, 1);
}

void music_destroy(global_t *global)
{
    sfMusic_stop(global->menu->settings->musique);
    sfMusic_destroy(global->menu->settings->musique);
}