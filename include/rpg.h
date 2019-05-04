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
    sfTexture *champ_bckt;
    sfSprite *champ_bck;
    sfTexture *player1_texture;
    sfSprite *player1_sprite;
    sfTexture *player2_texture;
    sfSprite *player2_sprite;
    sfTexture *player3_texture;
    sfSprite *player3_sprite;
    sfTexture *player4_texture;
    sfSprite *player4_sprite;
    sfText *te;
    sfText *te2;
}choose_char_t;

typedef struct fight {
    sfTexture *wp1t;
    sfSprite *wp1s;
    sfTexture *boss1t;
    sfSprite *boss1s;
    sfTexture *playert;
    sfSprite *players;
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
    bool turn;
    bool stamina_used;
    sfClock *clocks;
    sfText* life;
    sfText* life1t;
    sfText* stamina1t;
    sfText* stamina;
    sfMusic *musique;
    int x;
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
    sfSprite *sp_vil_old;
    sfTexture *vil_old;
    sfSprite *sp_pnj_volc;
    sfTexture *pnj_volc;
    sfSprite *sp_chest_1;
    sfTexture *chest_1;
    sfIntRect rect_pnj_d;
    sfIntRect rect_pnj_1;
    sfIntRect rect_pnj_ed;
    sfIntRect rect_pnj_pech;
    sfIntRect rect_pnj_bot;
    sfIntRect rect_vil_old;
    sfIntRect rect_pnj_volc;
    sfIntRect rect_chest_1;
    sfTexture *text_box;
    sfSprite *s_text_box;
    sfText *text;
    sfText *text_d;
    sfText *text_ed;
    sfText *text_pech;
    sfText *text_bot;
    sfText *text_papy;
    sfText *text_volc;
    sfText *text_chest_1;
    sfFont *font;
    int p_text;
    int p_text_d;
    int p_text_ed;
    int p_text_pech;
    int p_text_bot;
    int girl_quest;
    int vil_papy;
    int q_volc;
    int chest_nb1;
    int op_chest;
    int quest_complete;
    int next_text;
    char *sec_q;
}pnj_t;

typedef struct boss {
    sfTexture *final_boss;
    sfSprite *sp_final_boss;
    sfIntRect rect_final_boss;
    int win_vs_final_boss;
    sfTexture *winter_boss;
    sfSprite *sp_winter_boss;
    sfIntRect rect_winter_boss;
    int win_vs_winter_boss;
    sfTexture *desert_boss;
    sfSprite *sp_desert_boss;
    sfIntRect rect_desert_boss;
    int win_vs_desert_boss;
    sfTexture *hl_boss;
    sfSprite *sp_hl_boss;
    sfIntRect rect_hl_boss;
    int win_vs_hl_boss;
    sfTexture *volc_boss;
    sfSprite *sp_volc_boss;
    sfIntRect rect_volc_boss;
    int win_vs_volc_boss;
    int s_last_quest;
    int s_last_quest2;
    int quest_fboss;
}boss_t;

typedef struct item {
    int on;
    sfTexture *bootst;
    sfSprite *boots;
    sfTexture *armort;
    sfSprite *armors;
    sfTexture *axet;
    sfSprite *axes;
    sfTexture *helmett;
    sfSprite *helmets;
    sfTexture *orbt;
    sfSprite *orbs;
}item_t;

typedef struct gameplay {
    sfTexture *backg;
    sfTexture *backg_vil;
    sfTexture *backg_cas;
    sfTexture *backg_vol;
    sfTexture *backg_fcp;
    sfSprite *sprite_backg;
    sfTexture *man;
    sfSprite *sprite_man;
    sfIntRect rect_man;
    sfClock *clocks;
    sfView * view;
    char **map;
    char **wmap;
    char **mapc_fcp;
    char **mapc_cas;
    char **mapc_vol;
    char **mapc_vil;
    int x;
    int y;
    int camera_x;
    int camera_y;
    int width;
    int lenght;
    int player_nb;
    pnj_t *pnj;
    boss_t *boss;
    item_t *item;
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

typedef struct htp {
    sfTexture *htpt_bck;
    sfSprite *htp_bck;
    sfTexture *ins1t_bck;
    sfSprite *ins1_bck;
    sfTexture *ins2t_bck;
    sfSprite *ins2_bck;
    sfClock *loading;
}htp_t;

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
    htp_t *st_htp;
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
char **string_to_tab(char *buffer);

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

// In src/choose_character/choose_text.c
void string_p(global_t *global);
void choose_create3(global_t *global);

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
void init_how_to_play(global_t *global);
void init_instruct(global_t *global);

//In src/gameplay/interaction/pnj_interaction.c
void check_interaction(global_t *global);
void display_text(global_t *global);

//In src/gameplay/interaction/pnj_interaction.c
void switch_in_fight(global_t *global);

//In src/gameplay/interaction/pnj_interaction_vil.c
void display_text_vill(global_t *global);
void check_interaction_village(global_t *global);

//In src/gameplay/interaction/fcp_interaction.c
void display_text_fcp(global_t *global);
void check_interaction_fcp(global_t *global);

//In src/gameplay/interaction/display_text.c
void display_text(global_t *global);
void fight_in_volc(global_t *global);

//In src/gameplay/interaction/display_text.c
void set_text_box(global_t *global);
void destroy_textures_quetes(global_t *global);
void display_text_volc(global_t *global);

//In src/gameplay/interaction/destroy_sprites.c
void destroy_textures_quetes_bot(global_t *global);
void destroy_textures_quetes_pech(global_t *global);
void destroy_textures_quetes_ed(global_t *global);
void destroy_textures_quetes_d(global_t *global);
void destroy_textures_quetes_volc(global_t *global);

//In src/gameplay/interaction/display_pnj_settings.c
void display_text_quest(global_t *global);
void display_text_bottom(global_t *global);
void display_text_pech(global_t *global);
void different_text(global_t *global);
void display_text_desert(global_t *global);

//IN src/gameplay/interaction/text_settings.c
void set_winter_text(global_t *global);
void set_desert_text(global_t *global);
void set_edesert_text(global_t *global);
void set_pech_text(global_t *global);
void set_bot_text(global_t *global);
void set_volc_text(global_t *global);

// In src/fight/fight.c
int fight(global_t *global);
void wait(global_t *global);

// In src/fight/detect_win.c
int dectect_win(global_t *global);

// In src/fight/fight_init.c
void fight_create(global_t *global);
void fight_destroy(global_t *global);
void set_my_recta(global_t *global);
void create_all(global_t *global);
void texture_scale(global_t *global);

// In src/fight/fight_turn.c
void check_turn(global_t *global);
void choose_who_create(global_t *global);

// In src/fight/music_fight.c
void music_fight(global_t *global);
void fight_music_destroy(global_t *global);

// In src/fight/fight_display.c
void display_elementary(global_t *global);
void fight_display(global_t *global);
void draw_fight_info(global_t *global);

//In src/gameplay/movement_player/open_col_files.c
int open_file(global_t *global);
char **get_map(char *path, char **map);

//In src/gameplay/map_management/change_map.c
int check_map_change(global_t *global, int scn);

//In src/gameplay/map_management/check_enter_builds.c
int check_village(global_t *global, int mpos_x, int mpos_y, int scn);
int check_castle(global_t *global, int mpos_x, int mpos_y, int scn);

//In src/gameplay/map_management/check_leaving_builds.c
int check_leave_cas(global_t *global, int mpos_x, int mpos_y, int scn);
int check_leave_vil(global_t *global, int mpos_x, int mpos_y, int scn);
int check_leave_builds(global_t *global, int mpos_x, int mpos_y, int scn);

//In src/gameplay/map_management/check_enter_dungeons.c
int check_volcano(global_t *global, int mpos_x, int mpos_y, int scn);

//In src/gameplay/map_management/check_leave_dungeon.c
int check_leave_vol(global_t *global, int mpos_x, int mpos_y, int scn);

//In src/gameplay/map_management/check_enter_fc.c
int check_firecamp(global_t *global, int mpos_x, int mpos_y, int scn);

//In src/gameplay/map_management/check_leaving_fc.c
int check_leave_pfc(global_t *global, int mpos_x, int mpos_y, int scn);
int check_leave_firecamps(global_t *global, int mpos_x, int mpos_y, int scn);

// In src/gameplay/inv/items.c
void create_item(global_t *global);
void draw_item(global_t *global);
int item_is_c(sfEvent event, sfSprite *spr);

// In src/fight/select_enemis.c
void fight_choose_player(global_t *global);
int check_event_fight(global_t *global, int x, int y);
void check_mouse_fight(global_t *global);

// In src/fight/change_rect.c
void change_rect_fight(global_t *global);

// In src/fight/reward.c
void reward(global_t *global);

// In src/pause/draw_inv.c
void display_inv2(global_t *global);
void draw_instruct(global_t *global);
void draw_instruct2(global_t *global);

#endif