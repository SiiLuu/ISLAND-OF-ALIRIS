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
        check_interaction(global);
        check_interaction_village(global);
        check_interaction_fcp(global);
        check_interaction_castel(global);
        draw_sprites(global);
        if (sfKeyboard_isKeyPressed(sfKeyLShift) &&
            check_collision_up(global->gameplay, 10) == true) {
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
        check_interaction(global);
        check_interaction_village(global);
        check_interaction_fcp(global);
        check_interaction_castel(global);
        draw_sprites(global);
        if (sfKeyboard_isKeyPressed(sfKeyLShift) &&
            check_collision_down(global->gameplay, 10) == true) {
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
        check_interaction(global);
        check_interaction_village(global);
        check_interaction_fcp(global);
        check_interaction_castel(global);
        draw_sprites(global);
        if (sfKeyboard_isKeyPressed(sfKeyLShift) &&
            check_collision_left(global->gameplay, 10) == true) {
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
        check_interaction(global);
        check_interaction_village(global);
        check_interaction_fcp(global);
        check_interaction_castel(global);
        draw_sprites(global);
        if (sfKeyboard_isKeyPressed(sfKeyLShift) &&
            check_collision_right(global->gameplay, 10) == true) {
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
    if (global->event.key.code == sfKeyUp &&
        check_scn_nbr(global->scn) == true)
        move_up(global);
    if (global->event.key.code == sfKeyDown &&
        check_scn_nbr(global->scn) == true)
        move_down(global);
    if (global->event.key.code == sfKeyLeft &&
        check_scn_nbr(global->scn) == true)
        move_left(global);
    if (global->event.key.code == sfKeyRight &&
        check_scn_nbr(global->scn) == true)
        move_right(global);
}