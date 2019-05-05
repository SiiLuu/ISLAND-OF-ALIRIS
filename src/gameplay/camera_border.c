/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** set the map border
*/

#include "my.h"
#include "rpg.h"

void top_right_corner(global_t *global)
{
    sfView_reset(global->gameplay->view, (sfFloatRect){0,
    global->gameplay->lenght - 1080, 1920, 1080});
}

void bottom_right_corner(global_t *global)
{
    sfView_reset(global->gameplay->view, (sfFloatRect){
        global->gameplay->width - 1920, global->gameplay->lenght - 1080, 1920,
        1080});
}

void vertical_camera(global_t *global)
{
    global->gameplay->camera_x = global->gameplay->x - (1920 / 2) + 48;
    sfView_reset(global->gameplay->view, (sfFloatRect){
        global->gameplay->x - (1920 / 2) + 48, global->gameplay->camera_y,
        1920, 1080});
}

void camera_horizontal(global_t *global)
{
    global->gameplay->camera_y = global->gameplay->y - (1080 / 2) + 48;
    sfView_reset(global->gameplay->view, (sfFloatRect){
        global->gameplay->camera_x, global->gameplay->y - (1080 / 2) + 48,
        1920, 1080});
}

void camera_center(global_t *global)
{
    global->gameplay->camera_x = global->gameplay->x - (1920 / 2) + 48;
    global->gameplay->camera_y = global->gameplay->y - (1080 / 2) + 48;
    sfView_reset(global->gameplay->view,
    (sfFloatRect){global->gameplay->x - ((1920 / 2) - 48),
    global->gameplay->y - ((1080 / 2) - 48), 1920, 1080});
}