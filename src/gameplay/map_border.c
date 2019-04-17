/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** set the map border
*/

#include "my.h"
#include "rpg.h"

void top_right_corner(gameplay_t *gameplay)
{
    sfView_reset(gameplay->view, (sfFloatRect){0, 2000 - 1080,
    1920, 1080});
}

void bottom_right_corner(gameplay_t *gameplay)
{
    sfView_reset(gameplay->view, (sfFloatRect){3008 - 1920, 2000 - 1080,
    1920, 1080});
}

void vertical_camera(gameplay_t *gameplay)
{
    gameplay->camera_x = gameplay->x - (1920 / 2) + 48;
    sfView_reset(gameplay->view, (sfFloatRect){gameplay->x - (1920 / 2) + 48,
    gameplay->camera_y, 1920, 1080});
}

void camera_horizontal(gameplay_t *gameplay)
{
    gameplay->camera_y = gameplay->y - (1080 / 2) + 48;
    sfView_reset(gameplay->view, (sfFloatRect){gameplay->camera_x,
    gameplay->y - (1080 / 2) + 48, 1920, 1080});
}

void camera_center(gameplay_t *gameplay)
{
    gameplay->camera_x = gameplay->x - (1920 / 2) + 48;
    gameplay->camera_y = gameplay->y - (1080 / 2) + 48;
    sfView_reset(gameplay->view, (sfFloatRect){gameplay->x - ((1920 / 2) - 48),
    gameplay->y - ((1080 / 2) - 48), 1920, 1080});
}