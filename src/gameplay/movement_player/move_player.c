/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** function to move the player on the map
*/

#include <stdbool.h>
#include "my.h"
#include "rpg.h"

void move_up(global_t *global)
{
    set_rect_top(global);
    while (sfKeyboard_isKeyPressed(sfKeyUp)) {
        check_position_top(global);
        move_rect(global->gameplay);
        move_vue(global);
        sfSprite_setTextureRect(global->gameplay->sprite_man, global->gameplay->rect_man);
        sfSprite_setPosition(global->gameplay->sprite_man, (sfVector2f){global->gameplay->x, global->gameplay->y});
        sfRenderWindow_drawSprite(global->window, global->gameplay->sprite_backg, NULL);
        sfRenderWindow_drawSprite(global->window, global->gameplay->sprite_man, NULL);
        sfRenderWindow_display(global->window);
        if (sfKeyboard_isKeyPressed(sfKeyLShift) && check_collision_up(global->gameplay, 10) == true) {
            set_rect_runing(global->gameplay);
            global->gameplay->y -= 10;
        }
        else if (check_collision_up(global->gameplay, 5) == true) {
            set_rect_moving(global->gameplay);
            global->gameplay->y -= 5;
        }
    }
}

void move_down(global_t *global)
{
    set_rect_down(global);
    while (sfKeyboard_isKeyPressed(sfKeyDown)) {
        check_position_down(global);
        move_rect(global->gameplay);
        move_vue(global);
        sfSprite_setTextureRect(global->gameplay->sprite_man, global->gameplay->rect_man);
        sfSprite_setPosition(global->gameplay->sprite_man, (sfVector2f){global->gameplay->x, global->gameplay->y});
        sfRenderWindow_drawSprite(global->window, global->gameplay->sprite_backg, NULL);
        sfRenderWindow_drawSprite(global->window, global->gameplay->sprite_man, NULL);
        sfRenderWindow_display(global->window);
        if (sfKeyboard_isKeyPressed(sfKeyLShift) && check_collision_down(global->gameplay, 10) == true) {
            set_rect_runing(global->gameplay);
            global->gameplay->y += 10;
        }
        else if (check_collision_down(global->gameplay, 5) == true) {
            set_rect_moving(global->gameplay);
            global->gameplay->y += 5;
        }
    }
}

void move_left(global_t *global)
{
    set_rect_left(global);
    while (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        check_position_left(global);
        move_rect(global->gameplay);
        move_vue(global);
        sfSprite_setTextureRect(global->gameplay->sprite_man, global->gameplay->rect_man);
        sfSprite_setPosition(global->gameplay->sprite_man, (sfVector2f){global->gameplay->x, global->gameplay->y});
        sfRenderWindow_drawSprite(global->window, global->gameplay->sprite_backg, NULL);
        sfRenderWindow_drawSprite(global->window, global->gameplay->sprite_man, NULL);
        sfRenderWindow_display(global->window);
        if (sfKeyboard_isKeyPressed(sfKeyLShift) && check_collision_left(global->gameplay, 10) == true) {
            set_rect_runing(global->gameplay);
            global->gameplay->x -= 10;
        }
        else if (check_collision_left(global->gameplay, 5) == true) {
            set_rect_moving(global->gameplay);
            global->gameplay->x -= 5;
        }
    }
}

void move_right(global_t *global)
{
    set_rect_right(global);
    while (sfKeyboard_isKeyPressed(sfKeyRight)) {
        check_position_right(global);
        move_rect(global->gameplay);
        move_vue(global);
        sfSprite_setTextureRect(global->gameplay->sprite_man, global->gameplay->rect_man);
        sfSprite_setPosition(global->gameplay->sprite_man, (sfVector2f){global->gameplay->x, global->gameplay->y});
        sfRenderWindow_drawSprite(global->window, global->gameplay->sprite_backg, NULL);
        sfRenderWindow_drawSprite(global->window, global->gameplay->sprite_man, NULL);
        sfRenderWindow_display(global->window);
        //printf("y = %d, x = %d\n", global->gameplay->y, global->gameplay->x);
        if (sfKeyboard_isKeyPressed(sfKeyLShift) && check_collision_right(global->gameplay, 10) == true) {
            set_rect_runing(global->gameplay);
            global->gameplay->x += 10;
        }
        else if (check_collision_right(global->gameplay, 5) == true) {
            set_rect_moving(global->gameplay);
            global->gameplay->x += 5;
        }
    }
}

void move_character(global_t *global)
{
    if (global->event.key.code == sfKeyUp && (global->scn == 1))
        move_up(global);
    if (global->event.key.code == sfKeyDown && (global->scn == 1))
        move_down(global);
    if (global->event.key.code == sfKeyLeft && (global->scn == 1))
        move_left(global);
    if (global->event.key.code == sfKeyRight && (global->scn == 1))
        move_right(global);
}