/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** init the differents players
*/

#include "my.h"
#include "rpg.h"

void player_1(global_t *global)
{
    global->gameplay->man = sfTexture_createFromFile(
                            "resource/Sprite player/Actor.png", NULL);
    set_my_rect_p1(global);
}

void player_2(global_t *global)
{
    global->gameplay->man = sfTexture_createFromFile(
                        "resource/Sprite player/player2and3.png", NULL);
    set_my_rect_p2(global);
}

void player_3(global_t *global)
{
    global->gameplay->man = sfTexture_createFromFile(
                           "resource/Sprite player/player2and3.png", NULL);
    set_my_rect_p3(global);
}

void player_4(global_t *global)
{
    global->gameplay->man = sfTexture_createFromFile(
                            "resource/Sprite player/Actor.png", NULL);
    set_my_rect_p4(global);
}

void init_texture(global_t *global)
{
    init_gameplay_action(global);
    create_sprite(global);
    if (global->gameplay->player_nb == 1)
        player_1(global);
    if (global->gameplay->player_nb == 2)
        player_2(global);
    if (global->gameplay->player_nb == 3)
        player_3(global);
    if (global->gameplay->player_nb == 4)
        player_4(global);
    set_textures(global);
    set_position(global);
}