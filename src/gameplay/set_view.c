/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** set the camera in the differents side
*/

#include "my.h"
#include "rpg.h"

void bottom_left_corner(global_t *global)
{
    sfView_reset(global->gameplay->view, (sfFloatRect){
        global->gameplay->width - 1920, 0, 1920, 1080});
}

void move_vue(global_t *global)
{
    if ((global->gameplay->x > global->gameplay->width - 1920 / 2 - 48) &&
        (global->gameplay->y < 1080 / 2 - 48))
        bottom_left_corner(global);
    else if ((global->gameplay->x < 0 + (1920 / 2) - 48) &&
            (global->gameplay->y < (1080 / 2) - 48))
        sfView_reset(global->gameplay->view, (sfFloatRect){0, 0, 1920, 1080});
    else if ((global->gameplay->x < 0 + 1920 / 2 - 48) &&
            (global->gameplay->y > global->gameplay->lenght - 1080 / 2 - 48))
        top_right_corner(global);
    else if ((global->gameplay->x > global->gameplay->width - 1920 / 2 - 48) &&
            (global->gameplay->y > global->gameplay->lenght - 1080 / 2 - 48))
        bottom_right_corner(global);
    else if (global->gameplay->x > global->gameplay->width - (1920 / 2) - 48 ||
            global->gameplay->x < (1920 / 2) - 48)
        camera_horizontal(global);
    else if (global->gameplay->y > global->gameplay->lenght\
            - (1080 / 2) - 48 || global->gameplay->y < (1080 / 2) - 48)
        vertical_camera(global);
    else
        camera_center(global);
    sfRenderWindow_setView(global->window, global->gameplay->view);
}