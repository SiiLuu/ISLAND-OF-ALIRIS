/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** my_runner
*/

#include "my.h"

void music_game(menu_t *menu)
{
    const char *te = "resource/music.flac";

    menu->musique = sfMusic_createFromFile(te);
    sfMusic_play(menu->musique);
    sfMusic_setLoop(menu->musique, 1);
}

void music_destroy(menu_t *menu)
{
    sfMusic_stop(menu->musique);
    sfMusic_destroy(menu->musique);
}