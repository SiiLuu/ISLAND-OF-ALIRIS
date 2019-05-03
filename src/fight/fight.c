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

void fight_animation_display(global_t *global)
{
    sfSprite_setTextureRect(global->fight->players, global->fight->rect);
    sfSprite_setPosition(global->fight->players,
                        (sfVector2f){global->fight->x, 700});
    sfRenderWindow_drawSprite(global->window, global->fight->wp1s, NULL);
    sfRenderWindow_drawSprite(global->window, global->fight->boss1s, NULL);
    sfRenderWindow_drawSprite(global->window, global->fight->players, NULL);
    sfRenderWindow_display(global->window);
}

void fight_animation(global_t *global)
{
    sfClock *clocks = sfClock_create();

    sfRenderWindow_display(global->window);
    fight_choose_player(global);
    sfSprite_setScale(global->fight->players, (sfVector2f){2.20, 2.20});
    while (global->fight->x > 1200) {
        if (sfTime_asMilliseconds(sfClock_getElapsedTime(clocks)) > 1) {
            global->fight->x -= 3;
            if (sfTime_asMilliseconds(sfClock_getElapsedTime(
                global->gameplay->clocks)) > 100) {
                change_rect_fight(global);
                sfClock_restart(global->gameplay->clocks);
            }
            fight_animation_display(global);
            sfClock_restart(clocks);
        }
        sfRenderWindow_pollEvent(global->window, &global->event);
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            exit (0);
    }
    sfClock_destroy(clocks);
}

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
