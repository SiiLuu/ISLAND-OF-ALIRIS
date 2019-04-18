/*
** EPITECH PROJECT, 2019
** rpg.h
** File description:
** protoype for the rpg function
*/

#ifndef RPG_H
#define RPG_H

#include <time.h>
#include <SFML/Graphics.h>
#include <sys/stat.h>
#include <fcntl.h>
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

typedef struct gameplay {
    sfTexture *backg;
    sfSprite *sprite_backg;
    sfTexture *man;
    sfSprite *sprite_man;
    sfTexture *man2;
    sfSprite *sprite_man2;
    sfTexture *man3;
    sfSprite *sprite_man3;
    sfTexture *man4;
    sfSprite *sprite_man4;
    sfIntRect rect_man;
    sfClock *clocks;
    sfView * view;
    char *buffer;
    char **map;
    int x;
    int y;
    int camera_x;
    int camera_y;
}gameplay_t;

typedef struct global {
    sfRenderWindow *window;
    sfEvent event;
    menu_t *menu;
    //gameplay_t *gameplay;
}global_t;


//In music.c
void music_game(global_t *global);
void music_destroy(global_t *global);

//In menu.c
int menu_start(global_t *global, int i);
void menu_create(global_t *global);
void menu_display(global_t *global);
int destroy_menu(global_t *global);
void change_start_btn(global_t *global);
void check_mouse(global_t *global);
void menu_set_position(global_t *global);

//In settings.c
int settings(global_t *global, int x, int y);
void all_display_settings(global_t *global);

//In sound_bar.c
void display_sound(global_t *global);
void display_sound_settings(global_t *global);
void display_sound_bar(global_t *global);

//In src/move_character/character.c
void set_my_rect(gameplay_t *gameplay);
int check_events(global_t *global, gameplay_t *gameplay);
void draw_sprites(gameplay_t *gameplay, global_t *global);
void init_texture(gameplay_t *gameplay);
void move_vue(gameplay_t *gameplay, global_t *global);
void move_rect_running(gameplay_t *gameplay);
void move_rect(gameplay_t *gameplay);

//In src/gameplay/move_character.c
void move_character(gameplay_t *gameplay, global_t *global);
void move_right(gameplay_t *gameplay, global_t *global);
void move_up(gameplay_t *gameplay, global_t *global);
void move_down(gameplay_t *gameplay, global_t *global);
void move_left(gameplay_t *gameplay, global_t *global);

//In src/gameplay/camera_border.c
void camera_center(gameplay_t *gameplay);
void camera_horizontal(gameplay_t *gameplay);
void vertical_camera(gameplay_t *gameplay);
void bottom_right_corner(gameplay_t *gameplay);
void top_right_corner(gameplay_t *gameplay);

//In src/gameplay/map_border.c
void check_position_right(gameplay_t *gameplay);
void check_position_left(gameplay_t *gameplay);
void check_position_top(gameplay_t *gameplay);
void check_position_down(gameplay_t *gameplay);

//In src/gameplay/buffer_in_array.c
void string_to_tab(gameplay_t *gameplay);

#endif