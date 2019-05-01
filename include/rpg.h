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

typedef struct choose_char {
    sfTexture *player1_texture;
    sfSprite *player1_sprite;
    sfTexture *player2_texture;
    sfSprite *player2_sprite;
    sfTexture *player3_texture;
    sfSprite *player3_sprite;
    sfTexture *player4_texture;
    sfSprite *player4_sprite;
}choose_char_t;

typedef struct fight {
    sfTexture *wp1t;
    sfSprite *wp1s;
    sfTexture *boss1t;
    sfSprite *boss1s;
    sfTexture *playert;     // A chnager
    sfSprite *players;      // A chnager
    sfSprite *arrows;
    sfTexture *arrowt;
    sfIntRect rect;
    sfSprite *attack_spes;
    sfTexture *attack_spet;
    sfSprite *attacks;
    sfTexture *attackt;
    int life1;
    int life2;
    int stamina1;
    int enemis;
    int win_vs_final_boss;
    bool turn;
    bool stamina_used;
    sfClock *clocks;
    sfText* life;
    sfText* life1t;
    sfText* stamina1t;
    sfText* stamina;
}fight_t;

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
    sfClock *clocks;
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

typedef struct pnj {
    sfSprite *sprite_pnj_1;
    sfTexture *pnj_1;
    sfSprite *sprite_pnj_d;
    sfTexture *pnj_d;
    sfSprite *sprite_pnj_ed;
    sfTexture *pnj_ed;
    sfSprite *sprite_pnj_pech;
    sfTexture *pnj_pech;
    sfSprite *sprite_pnj_bot;
    sfTexture *pnj_bot;
    sfIntRect rect_pnj_d;
    sfIntRect rect_pnj_1;
    sfIntRect rect_pnj_ed;
    sfIntRect rect_pnj_pech;
    sfIntRect rect_pnj_bot;
    sfTexture *text_box;
    sfSprite *s_text_box;
    sfText *text;
    sfText *text_d;
    sfText *text_ed;
    sfText *text_pech;
    sfText *text_bot;
    sfFont *font;
    int p_text;
    int p_text_d;
    int p_text_ed;
    int p_text_pech;
    int p_text_bot;
    int girl_quest;
    int quest_complete;
    char *sec_q;
}pnj_t;

typedef struct boss {
    sfTexture *final_boss;
    sfSprite *sp_final_boss;
    sfIntRect rect_final_boss;
}boss_t;

typedef struct gameplay {
    sfTexture *backg;
    sfSprite *sprite_backg;
    sfTexture *man;
    sfSprite *sprite_man;
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
    pnj_t *pnj;
    boss_t *boss;
}gameplay_t;

typedef struct inv {
    sfTexture *wp_invt;
    sfSprite *wp_inv;
    sfTexture *equipt;
    sfSprite *equip;
    sfTexture *compt;
    sfSprite *comp;
    sfTexture *invt;
    sfSprite *inv;
    sfText *eq;
    sfText *eq2;
    sfText *eq3;
    sfFont *eqf;
}inv_t;

typedef struct quest {
    sfTexture *boardt;
    sfSprite *board;
    sfText *tquest;
    sfText *tquest2;
}quest_t;

typedef struct pause {
    sfRectangleShape *rct;
    sfTexture *invt;
    sfSprite *inv;
    sfSprite *quest;
    sfTexture *questt;
    sfTexture *backt;
    sfSprite *back;
    inv_t *st_inv;
    quest_t *st_quest;
}pause_t;

typedef struct global {
    sfRenderWindow *window;
    sfEvent event;
    menu_t *menu;
    gameplay_t *gameplay;
    pause_t *pause;
    choose_char_t *choose_char;
    fight_t *fight;
    int scn;
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
int check_events(global_t *global);
void draw_sprites(global_t *global);
void init_texture(global_t *global);
void move_vue(global_t *global);
void move_rect_running(gameplay_t *gameplay);
void move_rect(gameplay_t *gameplay);

//In src/gameplay/move_character.c
void move_character(global_t *global);
void move_right(global_t *global);
void move_up(global_t *global);
void move_down(global_t *global);
void move_left(global_t *global);

//In src/gameplay/camera_border.c
void camera_center(global_t *global);
void camera_horizontal(global_t *global);
void vertical_camera(global_t *global);
void bottom_right_corner(global_t *global);
void top_right_corner(global_t *global);

//In src/gameplay/map_border.c
void check_position_right(global_t *global);
void check_position_left(global_t *global);
void check_position_top(global_t *global);
void check_position_down(global_t *global);

//In src/gameplay/buffer_in_array.c
void string_to_tab(gameplay_t *gameplay);

//In src/gameplay/buffer_in_array.c
void string_to_tab(gameplay_t *gameplay);

//In src/Gameplay/rect_in_movement.c
void set_rect_runing(gameplay_t * gameplay);
void set_rect_moving(gameplay_t *gameplay);
void move_rect(gameplay_t *gameplay);

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
void set_rect_right(global_t *global);
void set_rect_left(global_t *global);
void set_rect_top(global_t *global);
void set_rect_down(global_t *global);

//In src/gameplay/movement_player/set_player_rect.c
void set_my_rect_p1(global_t *global);
void set_my_rect_p2(global_t *global);
void set_my_rect_p3(global_t *global);
void set_my_rect_p4(global_t *global);

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

// In src/choose_character/choose_character.c
int choose_character(global_t *global);

// In src/choose_character/choose_character_display.c
void choose_display(global_t *global);

// In src/pause/pause.c
void pause_create(global_t *global);
void display_player_inv(global_t *global, sfSprite *spr);

// In src/pause/inv.c
void chose_good_char(global_t *global);
void display_pause(global_t *global);
int but_is_c(sfEvent event, sfSprite *spr);

// In src/pause/draw_pause.c
void display_pause(global_t *global);
sfText *create_text(sfText *text, sfFont *fon);

// In src/pause/quest.c
void init_texts_quest(global_t *global);

//In src/gameplay/interaction/pnj_interaction.c
void check_interaction(global_t *global);
void display_text(global_t *global);

//In src/gameplay/interaction/pnj_interaction.c
void switch_in_fight(global_t *global);

// In src/fight/fight.c
int fight(global_t *global);
void wait(global_t *global);

// In src/fight/detect_win.c
int dectect_win(global_t *global);

// In src/fight/fight_init.c
void fight_create(global_t *global);
void fight_destroy(global_t *global);
void set_my_recta(global_t *global);

// In src/fight/fight_turn.c
void check_turn(global_t *global);
void choose_who_create(global_t *global);

// In src/fight/fight_display.c
void display_elementary(global_t *global);
void fight_display(global_t *global);
void draw_fight_info(global_t *global);

#endif