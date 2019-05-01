/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** function to the gameplay
*/

#include "my.h"
#include "rpg.h"

void bottom_left_corner(global_t *global)
{
    sfView_reset(global->gameplay->view, (sfFloatRect){6000 - 1920, 0,
    1920, 1080});
}

void move_vue(global_t *global)
{
    if ((global->gameplay->x > 6000 - 1920 / 2 - 48) && (global->gameplay->y < 1080 / 2 - 48))
        bottom_left_corner(global);
    else if ((global->gameplay->x < 0 + (1920 / 2) - 48) &&
            (global->gameplay->y < (1080 / 2) - 48))
        sfView_reset(global->gameplay->view, (sfFloatRect){0, 0, 1920, 1080});
    else if ((global->gameplay->x < 0 + 1920 / 2 - 48) &&
            (global->gameplay->y > 6000 - 1080 / 2 - 48))
        top_right_corner(global);
    else if ((global->gameplay->x > 6000 - 1920 / 2 - 48) &&
            (global->gameplay->y > 6000 - 1080 / 2 - 48))
        bottom_right_corner(global);
    else if (global->gameplay->x > 6000 - (1920 / 2) - 48 ||
            global->gameplay->x < (1920 / 2) - 48)
        camera_horizontal(global);
    else if (global->gameplay->y > 6000 - (1080 / 2) - 48 ||
           global->gameplay->y < (1080 / 2) - 48)
        vertical_camera(global);
    else
        camera_center(global);
    sfRenderWindow_setView(global->window, global->gameplay->view);
}

void check_monster_dead(global_t *global)
{
    if (global->gameplay->boss->win_vs_final_boss == 1) {
        sfSprite_setColor(global->gameplay->boss->sp_final_boss, sfTransparent);
        global->gameplay->map[5][23] = '0';
        global->gameplay->map[5][24] = '0';
    }
    if (global->gameplay->boss->win_vs_winter_boss == 1) {
        sfSprite_setColor(global->gameplay->boss->sp_winter_boss, sfTransparent);
        global->gameplay->map[31][54] = '0';
    }
    if (global->gameplay->pnj->girl_quest == 0)
        global->gameplay->map[50][50] = '0';
    else
        global->gameplay->map[50][50] = '5';
}

int check_events(global_t *global)
{
    while (sfRenderWindow_pollEvent(global->window, &global->event)) {
        check_interaction(global);
        if (global->event.type == sfEvtClosed)
            sfRenderWindow_close(global->window);
        if ((but_is_c(global->event, global->menu->start1) == 1) &&
            (global->scn == 2)) {
            global->scn = 1;
            move_vue(global);
        }
        if ((but_is_c(global->event, global->menu->quit1) == 1) &&
            (global->scn == 2))
            sfRenderWindow_close(global->window);
        if ((but_is_c(global->event, global->pause->inv) == 1) &&
            (global->scn == 2))
            global->scn = 3;
        if ((but_is_c(global->event, global->pause->quest) == 1) &&
            (global->scn == 2))
            global->scn = 4;
        if (global->event.key.code == sfKeyEscape && global->scn != 0)
            global->scn = 2;
        if (global->event.key.code == sfKeySpace && global->scn == 1)
            global->scn = 5;
        move_character(global);
    }
    check_monster_dead(global);
    return (0);
}

void init_rect_boss(global_t *global)
{
    global->gameplay->boss->rect_final_boss.height = 120;
    global->gameplay->boss->rect_final_boss.width = 120;
    global->gameplay->boss->rect_final_boss.left = 120;
    global->gameplay->boss->rect_final_boss.top = 240;
    global->gameplay->boss->rect_winter_boss.height = 120;
    global->gameplay->boss->rect_winter_boss.width = 120;
    global->gameplay->boss->rect_winter_boss.left = 120;
    global->gameplay->boss->rect_winter_boss.top = 120;
}

void init_rect_pnj(global_t *global)
{
    global->gameplay->pnj->rect_pnj_1.height = 48;
    global->gameplay->pnj->rect_pnj_1.width = 48;
    global->gameplay->pnj->rect_pnj_1.left = 480;
    global->gameplay->pnj->rect_pnj_1.top = 144;
    global->gameplay->pnj->rect_pnj_d.height = 48;
    global->gameplay->pnj->rect_pnj_d.width = 48;
    global->gameplay->pnj->rect_pnj_d.left = 336;
    global->gameplay->pnj->rect_pnj_d.top = 192;
    global->gameplay->pnj->rect_pnj_ed.height = 48;
    global->gameplay->pnj->rect_pnj_ed.width = 48;
    global->gameplay->pnj->rect_pnj_ed.left = 48;
    global->gameplay->pnj->rect_pnj_ed.top = 96;
    global->gameplay->pnj->rect_pnj_pech.height = 48;
    global->gameplay->pnj->rect_pnj_pech.width = 48;
    global->gameplay->pnj->rect_pnj_pech.left = 48;
    global->gameplay->pnj->rect_pnj_pech.top = 192;
    global->gameplay->pnj->rect_pnj_bot.height = 48;
    global->gameplay->pnj->rect_pnj_bot.width = 48;
    global->gameplay->pnj->rect_pnj_bot.left = 480;
    global->gameplay->pnj->rect_pnj_bot.top = 240;
    init_rect_boss(global);
}

void set_position_2(global_t *global)
{
    sfSprite_setTextureRect(global->gameplay->boss->sp_final_boss, global->gameplay->boss->rect_final_boss);
    sfSprite_setPosition(global->gameplay->boss->sp_final_boss, (sfVector2f){2310, 490});
    sfSprite_setScale(global->gameplay->boss->sp_final_boss, (sfVector2f){1.5, 1.5});
    sfSprite_setTextureRect(global->gameplay->boss->sp_winter_boss, global->gameplay->boss->rect_winter_boss);
    sfSprite_setPosition(global->gameplay->boss->sp_winter_boss, (sfVector2f){5350, 3010});
    sfSprite_setScale(global->gameplay->boss->sp_winter_boss, (sfVector2f){1.5, 1.5});
}

void set_position(global_t *global)
{
    init_rect_pnj(global);
    sfSprite_setTextureRect(global->gameplay->pnj->sprite_pnj_d, global->gameplay->pnj->rect_pnj_d);
    sfSprite_setTextureRect(global->gameplay->pnj->sprite_pnj_1, global->gameplay->pnj->rect_pnj_1);
    sfSprite_setTextureRect(global->gameplay->pnj->sprite_pnj_ed, global->gameplay->pnj->rect_pnj_ed);
    sfSprite_setTextureRect(global->gameplay->pnj->sprite_pnj_pech, global->gameplay->pnj->rect_pnj_pech);
    sfSprite_setTextureRect(global->gameplay->pnj->sprite_pnj_bot, global->gameplay->pnj->rect_pnj_bot);
    sfSprite_setPosition(global->gameplay->pnj->sprite_pnj_1, (sfVector2f){5010, 5000});
    sfSprite_setPosition(global->gameplay->pnj->sprite_pnj_d, (sfVector2f){1790, 1900});
    sfSprite_setPosition(global->gameplay->pnj->sprite_pnj_ed, (sfVector2f){2790, 2095});
    sfSprite_setPosition(global->gameplay->pnj->sprite_pnj_pech, (sfVector2f){3710, 2000});
    sfSprite_setPosition(global->gameplay->pnj->sprite_pnj_bot, (sfVector2f){4310, 4600});
    sfSprite_setScale(global->gameplay->pnj->sprite_pnj_d, (sfVector2f){2.08333, 2.08333});
    sfSprite_setScale(global->gameplay->pnj->sprite_pnj_1, (sfVector2f){2.08333, 2.08333});
    sfSprite_setScale(global->gameplay->pnj->sprite_pnj_ed, (sfVector2f){2.08333, 2.08333});
    sfSprite_setScale(global->gameplay->pnj->sprite_pnj_pech, (sfVector2f){2.08333, 2.08333});
    sfSprite_setScale(global->gameplay->pnj->sprite_pnj_bot, (sfVector2f){2.08333, 2.08333});
    sfSprite_setPosition(global->gameplay->sprite_man, (sfVector2f){global->gameplay->x, global->gameplay->y});
    sfSprite_setScale(global->gameplay->sprite_man, (sfVector2f){2.08333, 2.08333});
    set_position_2(global);
}

void create_sprite(global_t *global)
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
    global->gameplay->pnj->pnj_d = sfTexture_createFromFile("resource/Sprite player/Actor3.png", NULL);
    global->gameplay->pnj->pnj_1 = sfTexture_createFromFile("resource/Sprite player/player2and3.png", NULL);
    global->gameplay->pnj->pnj_ed = sfTexture_createFromFile("resource/Sprite player/player2and3.png", NULL);
    global->gameplay->pnj->pnj_pech = sfTexture_createFromFile("resource/Sprite player/Actor.png", NULL);
    global->gameplay->pnj->pnj_bot = sfTexture_createFromFile("resource/Sprite player/Actor3.png", NULL);
    global->gameplay->boss->final_boss = sfTexture_createFromFile("resource/fight/bigmonster.png", NULL);
    global->gameplay->boss->winter_boss = sfTexture_createFromFile("resource/fight/bigmonster.png", NULL);
    global->gameplay->backg = sfTexture_createFromFile("resource/World Map.png", NULL);
}

void init_gameplay_action(global_t *global)
{
    global->gameplay->pnj->p_text_bot = 0;
    global->gameplay->pnj->p_text_pech = 0;
    global->gameplay->pnj->p_text_ed = 0;
    global->gameplay->pnj->p_text = 0;
    global->gameplay->pnj->girl_quest = 0;
    global->gameplay->pnj->quest_complete = 0;
    global->gameplay->boss->win_vs_final_boss = 0;
    global->gameplay->boss->win_vs_winter_boss = 0;
    global->gameplay->pnj->sec_q = \
    "secondary quests: Find the lost girl and bring her back to her mother";
}

void set_textures(global_t *global)
{
    sfSprite_setTexture(global->gameplay->pnj->sprite_pnj_ed, global->gameplay->pnj->pnj_ed, sfTrue);
    sfSprite_setTexture(global->gameplay->pnj->sprite_pnj_d, global->gameplay->pnj->pnj_d, sfTrue);
    sfSprite_setTexture(global->gameplay->pnj->sprite_pnj_1, global->gameplay->pnj->pnj_1, sfTrue);
    sfSprite_setTexture(global->gameplay->pnj->sprite_pnj_pech, global->gameplay->pnj->pnj_pech, sfTrue);
    sfSprite_setTexture(global->gameplay->pnj->sprite_pnj_bot, global->gameplay->pnj->pnj_bot, sfTrue);
    sfSprite_setTexture(global->gameplay->boss->sp_final_boss, global->gameplay->boss->final_boss, sfTrue);
    sfSprite_setTexture(global->gameplay->boss->sp_winter_boss, global->gameplay->boss->winter_boss, sfTrue);
    sfSprite_setTexture(global->gameplay->sprite_backg, global->gameplay->backg, sfTrue);
    sfSprite_setTexture(global->gameplay->sprite_man, global->gameplay->man, sfTrue);
}

void init_texture(global_t *global)
{
    init_gameplay_action(global);
    create_sprite(global);
    if (global->gameplay->player_nb == 1) {
        global->gameplay->man = sfTexture_createFromFile("resource/Sprite player/Actor.png", NULL);
        set_my_rect_p1(global);
    }
    if (global->gameplay->player_nb == 2) {
        global->gameplay->man = sfTexture_createFromFile("resource/Sprite player/player2and3.png", NULL);
        set_my_rect_p2(global);
    }
    if (global->gameplay->player_nb == 3) {
        global->gameplay->man = sfTexture_createFromFile("resource/Sprite player/player2and3.png", NULL);
        set_my_rect_p3(global);
    }
    if (global->gameplay->player_nb == 4) {
        global->gameplay->man = sfTexture_createFromFile("resource/Sprite player/Actor.png", NULL);
        set_my_rect_p4(global);
    }
    set_textures(global);
    set_position(global);
}

void draw_sprites(global_t *global)
{
    if (global->scn == 1) {
        sfSprite_setPosition(global->gameplay->sprite_man, (sfVector2f){global->gameplay->x, global->gameplay->y});
        sfSprite_setTextureRect(global->gameplay->sprite_man, global->gameplay->rect_man);
        sfRenderWindow_drawSprite(global->window, global->gameplay->sprite_backg, NULL);
        sfRenderWindow_drawSprite(global->window, global->gameplay->sprite_man, NULL);
        if (global->gameplay->pnj->girl_quest == 1)
            sfRenderWindow_drawSprite(global->window, global->gameplay->pnj->sprite_pnj_1, NULL);
        sfRenderWindow_drawSprite(global->window, global->gameplay->pnj->sprite_pnj_d, NULL);
        sfRenderWindow_drawSprite(global->window, global->gameplay->pnj->sprite_pnj_ed, NULL);
        sfRenderWindow_drawSprite(global->window, global->gameplay->pnj->sprite_pnj_pech, NULL);
        sfRenderWindow_drawSprite(global->window, global->gameplay->pnj->sprite_pnj_bot, NULL);
        sfRenderWindow_drawSprite(global->window, global->gameplay->boss->sp_final_boss, NULL);
        sfRenderWindow_drawSprite(global->window, global->gameplay->boss->sp_winter_boss, NULL);
        switch_in_fight(global);
        display_text(global);
        sfRenderWindow_display(global->window);
    }
    if (global->scn == 5)
        fight(global);
    display_pause(global);
}