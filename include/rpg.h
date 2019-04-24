/*
** EPITECH PROJECT, 2019
** rpg.h
** File description:
** protoype for the rpg function
*/

#ifndef RPG_H
#define RPG_H

#include <time.h>
#include <stdbool.h>
#include <SFML/Graphics.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <SFML/Window/Export.h>
#include <SFML/Audio.h>
#include <SFML/Config.h>
#include <SFML/System.h>

typedef struct settings {
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
}settings_t;

typedef struct menu {
    sfSprite *wp;
    sfSprite *start1;
    sfSprite *quit1;
    sfSprite *start2;
    sfSprite *sounds;
    sfSprite *nosound;
    sfSprite *settingsa;
    sfTexture *wpt;
    sfTexture *start1t;
    sfTexture *quit1t;
    sfTexture *start2t;
    sfTexture *soundt;
    sfTexture *no_soundt;
    settings_t *settings;
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
    int player_nb;
}gameplay_t;

typedef struct global {
    sfRenderWindow *window;
    sfEvent event;
    menu_t *menu;
    //gameplay_t *gameplay;
}global_t;


//In src/menu/music.c
void music_game(global_t *global);
void music_destroy(global_t *global);

//In src/menu/menu.c
int menu_start(global_t *global, int i);
void menu_create(global_t *global);
void menu_display(global_t *global);
int destroy_menu(global_t *global);
void change_start_btn(global_t *global);
void check_mouse(global_t *global);
void menu_set_position(global_t *global);
void menu_create2(global_t *global);
void menu_choose_create_display(global_t *global, int i);

//In src/menu/settings.c
int settings(global_t *global, int x, int y);
void all_display_settings(global_t *global);

//In src/menu/sound_bar.c
void display_sound(global_t *global);
void display_sound_settings(global_t *global);
void display_sound_bar(global_t *global);

// In src/menu/check_menu.c
int check_menu(global_t *global, int x, int y);

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

//In src/gameplay/buffer_in_array.c
void string_to_tab(gameplay_t *gameplay);

//In src/Gameplay/rect_in_movement.c
void set_rect_runing(gameplay_t * gameplay);
void set_rect_moving(gameplay_t *gameplay);
void set_rect_left(gameplay_t *gameplay);
void move_rect(gameplay_t *gameplay);
void set_rect_down(gameplay_t *gameplay);
void set_rect_top(gameplay_t *gameplay);
void set_rect_right(gameplay_t *gameplay);

//In src/gameplay/set_player_running.c
void move_rect_running(gameplay_t *gameplay);
void move_rect_running_p2(gameplay_t *gameplay);
void move_rect_running_p3(gameplay_t *gameplay);
void move_rect_running_p4(gameplay_t *gameplay);

//In src/gameplay/movement_player/set_player_moving.c
void move_rect_p1(gameplay_t *gameplay);
void move_rect_p2(gameplay_t *gameplay);
void move_rect_p3(gameplay_t *gameplay);
void move_rect_p4(gameplay_t *gameplay);

//In src/gameplay/movement_player/set_player_direction.c
void set_rect_right(gameplay_t *gameplay);
void set_rect_left(gameplay_t *gameplay);
void set_rect_top(gameplay_t *gameplay);
void set_rect_down(gameplay_t *gameplay);

//In src/gameplay/movement_player/set_player_rect.c
void set_my_rect_p1(gameplay_t *gameplay);
void set_my_rect_p2(gameplay_t *gameplay);
void set_my_rect_p3(gameplay_t *gameplay);
void set_my_rect_p4(gameplay_t *gameplay);

//In src/gameplay/check_collision.c
bool check_collision_up(gameplay_t *gameplay, int distance);
bool check_collision_down(gameplay_t *gameplay, int distance);
bool check_collision_left(gameplay_t *gameplay, int distance);
bool check_collision_right(gameplay_t *gameplay, int distance);

//In src/gameplay/manage_collision.c
bool manage_col_up(gameplay_t *gameplay, int pos_x, int mpos_y);
bool manage_col_left(gameplay_t *gameplay, int pos_x, int pos_y);
bool manage_col_right(gameplay_t *gameplay, int mpos_x, int pos_y);
bool manage_col_down(gameplay_t *gameplay, int pos_x, int mpos_y);

#endif