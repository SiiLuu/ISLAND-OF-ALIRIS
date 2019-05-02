/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** my_rpg, fight.c
*/

#include "my.h"
#include "rpg.h"

void wait(global_t *global)
{
    sfClock *clocks = sfClock_create();

    display_elementary(global);
    sfRenderWindow_display(global->window);
    while (sfTime_asMilliseconds(sfClock_getElapsedTime(
            global->fight->clocks)) < 1000);
    global->fight->turn = 0;
    check_turn(global);
    sfClock_destroy(clocks);
}

int check_event_fight(global_t *global, int x, int y)
{
    if (x >= 1500 && x <= 1780 && y >= 830 && y <= 885) {
        if (global->fight->stamina1 < 20)
            return (0);
        global->fight->stamina_used = 1;
        global->fight->stamina1 -= 20;
        if (global->fight->turn == 0)
            global->fight->turn = 1;
        else if (global->fight->turn == 1)
            global->fight->turn = 0;
        fight_display(global);
    }
    else if (x >= 1500 && x <= 1730 && y >= 925 && y <= 980) {
        global->fight->stamina1 += 5;
        if (global->fight->turn == 0)
            global->fight->turn = 1;
        else if (global->fight->turn == 1)
            global->fight->turn = 0;
        fight_display(global);
    }
    return (0);
}

void check_mouse_fight(global_t *global)
{
    int x = 0;
    int y = 0;

    if (global->event.type == sfEvtMouseButtonPressed) {
        x = global->event.mouseButton.x;
        y = global->event.mouseButton.y;
        check_event_fight(global, x, y);
    }
}

int fight_loop(global_t *global)
{
    while (1) {
        if (dectect_win(global)) {
            move_vue(global);
            global->scn = 1;
            return (0);
        }
        if (sfTime_asMilliseconds(sfClock_getElapsedTime(
            global->fight->clocks)) > 100) {
            check_mouse_fight(global);
            sfClock_restart(global->fight->clocks);
        }
        sfRenderWindow_pollEvent(global->window, &global->event);
    }
    return (0);
}

void fight_choose_player(global_t *global)
{
    if (global->gameplay->player_nb == 1 || global->gameplay->player_nb == 4) {
        global->fight->playert = sfTexture_createFromFile(
                "resource/Sprite player/Actor.png", NULL);
        sfSprite_setTexture(global->fight->players,
                        global->fight->playert, sfTrue);
    }
    if (global->gameplay->player_nb == 2 || global->gameplay->player_nb == 3) {
        global->fight->playert = sfTexture_createFromFile(
                "resource/Sprite player/player2and3.png", NULL);
        sfSprite_setTexture(global->fight->players,
                        global->fight->playert, sfTrue);
    }
    if (global->gameplay->player_nb == 1) {
        global->fight->rect.height = 48;
        global->fight->rect.width = 48;
        global->fight->rect.left = 432;
        global->fight->rect.top = 48;
        sfSprite_setTextureRect(global->fight->players, global->fight->rect);
    }
    if (global->gameplay->player_nb == 2) {
        global->fight->rect.height = 48;
        global->fight->rect.width = 48;
        global->fight->rect.left = 144;
        global->fight->rect.top = 0;
        sfSprite_setTextureRect(global->fight->players, global->fight->rect);
    }
    if (global->gameplay->player_nb == 3) {
        global->fight->rect.height = 48;
        global->fight->rect.width = 48;
        global->fight->rect.left = 0;
        global->fight->rect.top = 240;
        sfSprite_setTextureRect(global->fight->players, global->fight->rect);
    }
    if (global->gameplay->player_nb == 4) {
        global->fight->rect.height = 48;
        global->fight->rect.width = 48;
        global->fight->rect.left = 288;
        global->fight->rect.top = 240;
        sfSprite_setTextureRect(global->fight->players, global->fight->rect);
    }
}

void change_rect_fight(global_t *global)
{
    
    if (global->gameplay->player_nb == 1) {
        if (global->fight->rect.left == 528)
            global->fight->rect.left = 432;
        global->fight->rect.left += 48;
    }
    if (global->gameplay->player_nb == 2) {
        if (global->fight->rect.left == 236)
            global->fight->rect.left = 144;
        global->fight->rect.left += 48;
    }
    if (global->gameplay->player_nb == 3) {
        if (global->fight->rect.left == 92)
            global->fight->rect.left = 0;
        global->fight->rect.left += 48;
    }
    if (global->gameplay->player_nb == 4) {
        if (global->fight->rect.left == 380)
            global->fight->rect.left = 288;
        global->fight->rect.left += 48;
    }
    
}

void fight_animation(global_t *global)
{
    sfClock *clocks = sfClock_create();

    sfRenderWindow_display(global->window);
    fight_choose_player(global);
    while (global->fight->x > 1200) {
        if (sfTime_asMilliseconds(sfClock_getElapsedTime(clocks)) > 1) {
            global->fight->x -= 3;
            change_rect_fight(global);
            //sfSprite_setTextureRect(global->fight->players, global->fight->rect);
            sfSprite_setPosition(global->fight->players, (sfVector2f){global->fight->x, 700});
            sfRenderWindow_drawSprite(global->window, global->fight->wp1s, NULL);
            sfRenderWindow_drawSprite(global->window, global->fight->boss1s, NULL);
            sfRenderWindow_drawSprite(global->window, global->fight->players, NULL);
            sfRenderWindow_display(global->window);
            sfClock_restart(clocks);
        }
        sfRenderWindow_pollEvent(global->window, &global->event);
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            exit (0);
    }
    sfClock_destroy(clocks);
}

void create_all(global_t *global);
void texture_scale(global_t *global);

int fight(global_t *global)
{
    global->fight->clocks = sfClock_create();

    global->fight->x = 2000;
    music_fight(global);
    sfView_reset(global->gameplay->view, (sfFloatRect){0, 0, 1920, 1080});
    sfRenderWindow_setView(global->window, global->gameplay->view);
    global->fight->life1 = 110;
    global->fight->life2 = 95;
    set_my_recta(global);
    create_all(global);
    texture_scale(global);
    fight_animation(global);
    choose_who_create(global);
    sfRenderWindow_pollEvent(global->window, &global->event);
    fight_display(global);
    fight_loop(global);
    fight_destroy(global);
    fight_music_destroy(global);
    return (0);
}
