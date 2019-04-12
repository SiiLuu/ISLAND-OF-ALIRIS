/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** my_defender
*/

#ifndef MY_H
#define MY_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <SFML/Graphics.h>
#include <SFML/Window/Export.h>
#include <SFML/Audio.h>
#include <SFML/Config.h>
#include <SFML/System.h>

typedef struct menu {
    sfSprite *wp;
    sfSprite *start1;
    sfSprite *quit1;
    sfSprite *start2;
    sfSprite *sounds;
    sfSprite *nosound;
    sfSprite *settings;
    sfTexture *wpt;
    sfTexture *start1t;
    sfTexture *quit1t;
    sfTexture *start2t;
    sfTexture *soundt;
    sfTexture *no_soundt;
    sfTexture *settingst;
    sfMusic *musique;
    sfText* text_music;
    sfFont* font;
    sfSprite *plus;
    sfSprite *minus;
    sfTexture *minust;
    sfTexture *plust;
    sfTexture *bart;
    sfSprite *bar1;
    sfSprite *bar2;
    sfSprite *bar3;
    sfSprite *bar4;
    int nbr_bar;
    int sound;
}menu_t;

typedef struct global {
    sfRenderWindow *window;
    sfEvent event;
    int xmouse;
    int ymouse;
}global_t;

//In lib/my
void my_putchar(char c);
int my_putnbr(int nb);
int my_putstr(char *str);
char *convert_int_char(unsigned nbr);

//In music.c
void music_game(menu_t *menu);
void music_destroy(menu_t *menu);

//In menu.c
int menu_start(global_t *global, menu_t *menu, int i);
void menu_create(menu_t *menu);
void menu_display(global_t *global, menu_t *menu);
int destroy_menu(global_t *global);
void change_start_btn(global_t *global, menu_t *menu);
void check_mouse(global_t *global, menu_t *menu);
void menu_set_position(menu_t *menu);

//In settings.c
int settings(global_t *global, menu_t *menu);
void all_display_settings(global_t *global, menu_t *menu);

//In sound_bar.c
void display_score(global_t *global, menu_t *menu);
void display_sound_settings(global_t *global, menu_t *menu);
void display_sound_bar(global_t *global, menu_t *menu);

#endif