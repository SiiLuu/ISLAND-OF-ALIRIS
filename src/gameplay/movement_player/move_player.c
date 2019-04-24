/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** function to move the player on the map
*/

#include <stdbool.h>
#include "my.h"
#include "rpg.h"

void move_up(gameplay_t *gameplay, global_t *global)
{
    set_rect_top(gameplay);
    while (sfKeyboard_isKeyPressed(sfKeyUp)) {
        check_position_top(gameplay);
        move_rect(gameplay);
        move_vue(gameplay, global);
        sfSprite_setTextureRect(gameplay->sprite_man, gameplay->rect_man);
        sfSprite_setPosition(gameplay->sprite_man, (sfVector2f){gameplay->x, gameplay->y});
        sfRenderWindow_drawSprite(global->window, gameplay->sprite_backg, NULL);
        sfRenderWindow_drawSprite(global->window, gameplay->sprite_man, NULL);
        sfRenderWindow_display(global->window);
        if (sfKeyboard_isKeyPressed(sfKeyLShift) && check_collision_up(gameplay, 10) == true) {
            set_rect_runing(gameplay);
            gameplay->y -= 10;
        }
        else if (check_collision_up(gameplay, 5) == true) {
            set_rect_moving(gameplay);
            gameplay->y -= 5;
        }
    }
}

void move_down(gameplay_t *gameplay, global_t *global)
{
    set_rect_down(gameplay);
    while (sfKeyboard_isKeyPressed(sfKeyDown)) {
        check_position_down(gameplay);
        move_rect(gameplay);
        move_vue(gameplay, global);
        sfSprite_setTextureRect(gameplay->sprite_man, gameplay->rect_man);
        sfSprite_setPosition(gameplay->sprite_man, (sfVector2f){gameplay->x, gameplay->y});
        sfRenderWindow_drawSprite(global->window, gameplay->sprite_backg, NULL);
        sfRenderWindow_drawSprite(global->window, gameplay->sprite_man, NULL);
        sfRenderWindow_display(global->window);
        if (sfKeyboard_isKeyPressed(sfKeyLShift) && check_collision_down(gameplay, 10) == true) {
            set_rect_runing(gameplay);
            gameplay->y += 10;
        }
        else if (check_collision_down(gameplay, 5) == true) {
            set_rect_moving(gameplay);
            gameplay->y += 5;
        }
    }
}

void move_left(gameplay_t *gameplay, global_t *global)
{
    set_rect_left(gameplay);
    while (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        check_position_left(gameplay);
        move_rect(gameplay);
        move_vue(gameplay, global);
        sfSprite_setTextureRect(gameplay->sprite_man, gameplay->rect_man);
        sfSprite_setPosition(gameplay->sprite_man, (sfVector2f){gameplay->x, gameplay->y});
        sfRenderWindow_drawSprite(global->window, gameplay->sprite_backg, NULL);
        sfRenderWindow_drawSprite(global->window, gameplay->sprite_man, NULL);
        sfRenderWindow_display(global->window);
        if (sfKeyboard_isKeyPressed(sfKeyLShift) && check_collision_left(gameplay, 10) == true) {
            set_rect_runing(gameplay);
            gameplay->x -= 10;
        }
        else if (check_collision_left(gameplay, 5) == true) {
            set_rect_moving(gameplay);
            gameplay->x -= 5;
        }
    }
}

void move_right(gameplay_t *gameplay, global_t *global)
{
    set_rect_right(gameplay);
    while (sfKeyboard_isKeyPressed(sfKeyRight)) {
        check_position_right(gameplay);
        move_vue(gameplay, global);
        sfSprite_setTextureRect(gameplay->sprite_man, gameplay->rect_man);
        sfSprite_setPosition(gameplay->sprite_man, (sfVector2f){gameplay->x, gameplay->y});
        sfRenderWindow_drawSprite(global->window, gameplay->sprite_backg, NULL);
        sfRenderWindow_drawSprite(global->window, gameplay->sprite_man, NULL);
        sfRenderWindow_display(global->window);
        printf("y = %d, x = %d\n", gameplay->y, gameplay->x);
        if (sfKeyboard_isKeyPressed(sfKeyLShift) && check_collision_right(gameplay, 10) == true) {
            set_rect_runing(gameplay);
            gameplay->x += 10;
        }
        else if (check_collision_right(gameplay, 5) == true) {
            set_rect_moving(gameplay);
            gameplay->x += 5;
        }
    }
}

void move_character(gameplay_t *gameplay, global_t *global)
{
    if (global->event.key.code == sfKeyUp)
        move_up(gameplay, global);
    if (global->event.key.code == sfKeyDown)
        move_down(gameplay, global);
    if (global->event.key.code == sfKeyLeft)
        move_left(gameplay, global);
    if (global->event.key.code == sfKeyRight)
        move_right(gameplay, global);
}