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
    const char *te = "resource/music.flac";

    global->menu->musique = sfMusic_createFromFile(te);
    sfMusic_play(global->menu->musique);
    sfMusic_setLoop(global->menu->musique, 1);
}

void music_destroy(global_t *global)
{
    sfMusic_stop(global->menu->musique);
    sfMusic_destroy(global->menu->musique);
}