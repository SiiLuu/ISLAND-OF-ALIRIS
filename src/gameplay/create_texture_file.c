/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** create the textures from the file
*/

#include "my.h"
#include "rpg.h"

void init_gameplay_action(global_t *global)
{
    global->gameplay->pnj->status->p_text_bot = 0;
    global->gameplay->pnj->status->p_text_pech = 0;
    global->gameplay->pnj->status->p_text_ed = 0;
    global->gameplay->pnj->status->p_text = 0;
    global->gameplay->pnj->status->girl_quest = 0;
    global->gameplay->pnj->status->quest_complete = 0;
    global->gameplay->boss->win_vs_final_boss = 0;
    global->gameplay->boss->win_vs_winter_boss = 0;
    global->gameplay->boss->win_vs_desert_boss = 0;
    global->gameplay->pnj->status->op_chest = 0;
    global->gameplay->boss->s_last_quest2 = 0;
    global->gameplay->pnj->status->q_volc = 0;
    global->gameplay->boss->win_vs_hl_boss = 0;
    global->gameplay->boss->win_vs_volc_boss = 0;
    global->gameplay->boss->quest_fboss = 0;
    global->gameplay->pnj->status->vil_papy = 0;
}

void textures(global_t *global)
{
    global->gameplay->boss->volc_boss = sfTexture_createFromFile(
        "resource/fight/Boss.png", NULL);
    global->gameplay->pnj->vil_old = sfTexture_createFromFile(
        "resource/Sprite player/People1.png", NULL);
    global->gameplay->pnj->pnj_volc = sfTexture_createFromFile(
        "resource/Sprite player/People3.png", NULL);
    global->gameplay->pnj->knight_1 = sfTexture_createFromFile(
        "resource/Sprite player/People3.png", NULL);
    global->gameplay->pnj->knight_2 = sfTexture_createFromFile(
        "resource/Sprite player/People3.png", NULL);
    global->gameplay->pnj->princess = sfTexture_createFromFile(
        "resource/Sprite player/People3.png", NULL);
    global->gameplay->pnj->pnj_garden = sfTexture_createFromFile(
        "resource/Sprite player/People1.png", NULL);
    global->gameplay->pnj->chest_1 = sfTexture_createFromFile(
        "resource/Sprite player/Chest.png", NULL);
}

void textures_creation(global_t *global)
{
    global->gameplay->pnj->pnj_d = sfTexture_createFromFile(
        "resource/Sprite player/Actor3.png", NULL);
    global->gameplay->pnj->pnj_1 = sfTexture_createFromFile(
        "resource/Sprite player/player2and3.png", NULL);
    global->gameplay->pnj->pnj_ed = sfTexture_createFromFile(
        "resource/Sprite player/player2and3.png", NULL);
    global->gameplay->pnj->pnj_pech = sfTexture_createFromFile(
        "resource/Sprite player/Actor.png", NULL);
    global->gameplay->pnj->pnj_bot = sfTexture_createFromFile(
        "resource/Sprite player/Actor3.png", NULL);
    global->gameplay->boss->final_boss = sfTexture_createFromFile(
        "resource/fight/bigmonster.png", NULL);
    global->gameplay->boss->winter_boss = sfTexture_createFromFile(
        "resource/fight/bigmonster.png", NULL);
    global->gameplay->boss->desert_boss = sfTexture_createFromFile(
        "resource/fight/bigmonster.png", NULL);
    global->gameplay->boss->hl_boss = sfTexture_createFromFile(
        "resource/fight/bigmonster.png", NULL);
    textures(global);
}

void sprites_creation(global_t *global)
{
    global->gameplay->sprite_backg = sfSprite_create();
    global->gameplay->sprite_man = sfSprite_create();
    global->gameplay->pnj->sprite_pnj_1 = sfSprite_create();
    global->gameplay->pnj->sprite_pnj_d = sfSprite_create();
    global->gameplay->pnj->sprite_pnj_ed = sfSprite_create();
    global->gameplay->pnj->sprite_pnj_pech = sfSprite_create();
    global->gameplay->pnj->sprite_pnj_bot = sfSprite_create();
    global->gameplay->boss->sp_final_boss = sfSprite_create();
    global->gameplay->boss->sp_winter_boss = sfSprite_create();
    global->gameplay->pnj->sp_vil_old = sfSprite_create();
    global->gameplay->pnj->sp_pnj_volc = sfSprite_create();
    global->gameplay->boss->sp_desert_boss = sfSprite_create();
    global->gameplay->boss->sp_hl_boss = sfSprite_create();
    global->gameplay->boss->sp_volc_boss = sfSprite_create();
    global->gameplay->pnj->sp_chest_1 = sfSprite_create();
    global->gameplay->pnj->sp_knight_1 = sfSprite_create();
    global->gameplay->pnj->sp_knight_2 = sfSprite_create();
    global->gameplay->pnj->sp_princess = sfSprite_create();
    global->gameplay->pnj->sp_pnj_garden = sfSprite_create();
}

void create_sprite(global_t *global)
{
    global->gameplay->backg_outpy = sfTexture_createFromFile(
        "resource/Out Pyramid.jpg", NULL);
    global->gameplay->backg_fcas = sfTexture_createFromFile(
        "resource/Flying Castle.jpg", NULL);
    global->gameplay->backg_inpy = sfTexture_createFromFile(
        "resource/In Pyramid.jpg", NULL);
    sprites_creation(global);
    textures_creation(global);
    create_map_sprites(global);
    create_item(global);
}