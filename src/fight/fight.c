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
    if (x >= 1500 && x <= 1775 && y >= 675 && y <= 730) {
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
    else if (x >= 1500 && x <= 1740 && y >= 780 && y <= 830) {
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

void fight(global_t *global)
{
    global->fight->clocks = sfClock_create();

    global->fight->life1 = 110;
    global->fight->life2 = 95;
    fight_create(global);
    sfRenderWindow_pollEvent(global->window, &global->event);
    while (1) {
        if (dectect_win(global))
            exit (0);
        if (sfTime_asMilliseconds(sfClock_getElapsedTime(
            global->fight->clocks)) > 100) {
            check_mouse_fight(global);
            sfClock_restart(global->fight->clocks);
        }
        sfRenderWindow_pollEvent(global->window, &global->event);
    }
    fight_destroy(global);
}