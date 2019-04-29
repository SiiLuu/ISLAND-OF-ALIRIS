/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** function to the gameplay
*/

#include "my.h"
#include "rpg.h"

void bottom_left_corner(global_t *global)
{
    sfView_reset(global->gameplay->view, (sfFloatRect){6000 - 1920, 0,
    1920, 1080});
}

void move_vue(global_t *global)
{
    if ((global->gameplay->x > 6000 - 1920 / 2 - 48) && (global->gameplay->y < 1080 / 2 - 48))
        bottom_left_corner(global);
    else if ((global->gameplay->x < 0 + (1920 / 2) - 48) &&
            (global->gameplay->y < (1080 / 2) - 48))
        sfView_reset(global->gameplay->view, (sfFloatRect){0, 0, 1920, 1080});
    else if ((global->gameplay->x < 0 + 1920 / 2 - 48) &&
            (global->gameplay->y > 6000 - 1080 / 2 - 48))
        top_right_corner(global);
    else if ((global->gameplay->x > 6000 - 1920 / 2 - 48) &&
            (global->gameplay->y > 6000 - 1080 / 2 - 48))
        bottom_right_corner(global);
    else if (global->gameplay->x > 6000 - (1920 / 2) - 48 ||
            global->gameplay->x < (1920 / 2) - 48)
        camera_horizontal(global);
    else if (global->gameplay->y > 6000 - (1080 / 2) - 48 ||
           global->gameplay->y < (1080 / 2) - 48)
        vertical_camera(global);
    else
        camera_center(global);
    sfRenderWindow_setView(global->window, global->gameplay->view);
}

int check_events(global_t *global)
{
    while (sfRenderWindow_pollEvent(global->window, &global->event)) {
        if (global->event.type == sfEvtClosed)
            sfRenderWindow_close(global->window);
        if ((but_is_c(global->event, global->menu->start1) == 1) &&
            (global->scn == 2)) {
            global->scn = 1;
            sfView_reset(global->gameplay->view,(sfFloatRect){global->gameplay->x / 2 - 100, global->gameplay->y / 2 - 100, 1920, 1080});
            sfRenderWindow_setView(global->window, global->gameplay->view);
        }
        if ((but_is_c(global->event, global->menu->quit1) == 1) &&
            (global->scn == 2))
            sfRenderWindow_close(global->window);
        if ((but_is_c(global->event, global->pause->inv) == 1) &&
            (global->scn == 2))
            global->scn = 3;
        if (global->event.key.code == sfKeyEscape && global->scn != 0)
            global->scn = 2;
        move_character(global);
    }
    return (0);
}

void set_position(global_t *global)
{
    sfSprite_setPosition(global->gameplay->sprite_man, (sfVector2f){global->gameplay->x, global->gameplay->y});
    sfSprite_setScale(global->gameplay->sprite_man, (sfVector2f){2.08333, 2.08333});
}

void create_sprite(global_t *global)
{
    global->gameplay->sprite_backg = sfSprite_create();
    global->gameplay->sprite_man = sfSprite_create();
    global->gameplay->sprite_man2 = sfSprite_create();
    global->gameplay->sprite_man3 = sfSprite_create();
    global->gameplay->sprite_man4 = sfSprite_create();
    global->gameplay->backg = sfTexture_createFromFile("resource/World Map.png", NULL);
}

void init_texture(global_t *global)
{
    create_sprite(global);
    if (global->gameplay->player_nb == 1) {
        global->gameplay->man = sfTexture_createFromFile("resource/Sprite player/Actor.png", NULL);
        set_my_rect_p1(global);
    }
    if (global->gameplay->player_nb == 2) {
        global->gameplay->man = sfTexture_createFromFile("resource/Sprite player/player2and3.png", NULL);
        set_my_rect_p2(global);
    }
    if (global->gameplay->player_nb == 3) {
        global->gameplay->man = sfTexture_createFromFile("resource/Sprite player/player2and3.png", NULL);
        set_my_rect_p3(global);
    }
    if (global->gameplay->player_nb == 4) {
        global->gameplay->man = sfTexture_createFromFile("resource/Sprite player/Actor.png", NULL);
        set_my_rect_p4(global);
    }
    sfSprite_setTexture(global->gameplay->sprite_backg, global->gameplay->backg, sfTrue);
    sfSprite_setTexture(global->gameplay->sprite_man, global->gameplay->man, sfTrue);
    set_position(global);
}

void draw_sprites(global_t *global)
{
    if (global->scn == 1) {
        sfSprite_setTextureRect(global->gameplay->sprite_man, global->gameplay->rect_man);
        sfRenderWindow_drawSprite(global->window, global->gameplay->sprite_backg, NULL);
        sfRenderWindow_drawSprite(global->window, global->gameplay->sprite_man, NULL);
        sfRenderWindow_display(global->window);
    }
    if (global->scn == 2) {
        sfRenderWindow_clear(global->window, sfBlack);
        sfView_reset(global->gameplay->view, (sfFloatRect){0, 0, 1920, 1080});
        sfRenderWindow_setView(global->window, global->gameplay->view);
        sfRenderWindow_drawSprite(global->window, global->pause->back, NULL);
        sfSprite_setPosition(global->menu->start1, (sfVector2f){780, 150});
        sfRenderWindow_drawSprite(global->window, global->menu->start1, NULL);
        sfSprite_setPosition(global->menu->quit1, (sfVector2f){780, 650});
        sfRenderWindow_drawSprite(global->window, global->menu->quit1, NULL);
        sfSprite_setPosition(global->pause->inv, (sfVector2f){780, 400});
        sfRenderWindow_drawSprite(global->window, global->pause->inv, NULL);
        sfRenderWindow_display(global->window);
    }
    if (global->scn == 3) {
        sfRenderWindow_clear(global->window, sfBlack);
        sfRenderWindow_drawSprite(global->window, global->pause->st_inv->wp_inv, NULL);
        sfRenderWindow_display(global->window);
    }
}