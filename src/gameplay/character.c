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
        check_interaction(global);
        if (global->event.type == sfEvtClosed)
            sfRenderWindow_close(global->window);
        if ((but_is_c(global->event, global->menu->start1) == 1) &&
            (global->scn == 2)) {
            global->scn = 1;
            move_vue(global);
        }
        if ((but_is_c(global->event, global->menu->quit1) == 1) &&
            (global->scn == 2))
            sfRenderWindow_close(global->window);
        if ((but_is_c(global->event, global->pause->inv) == 1) &&
            (global->scn == 2))
            global->scn = 3;
        if ((but_is_c(global->event, global->pause->quest) == 1) &&
            (global->scn == 2))
            global->scn = 4;
        if (global->event.key.code == sfKeyEscape && global->scn != 0)
            global->scn = 2;
        move_character(global);
    }
    return (0);
}

void init_rect_pnj(global_t *global)
{
    global->gameplay->rect_pnj_1.height = 48;
    global->gameplay->rect_pnj_1.width = 48;
    global->gameplay->rect_pnj_1.left = 480;
    global->gameplay->rect_pnj_1.top = 144;
}

void set_position(global_t *global)
{
    init_rect_pnj(global);
    sfSprite_setTextureRect(global->gameplay->pnj->sprite_pnj_1, global->gameplay->rect_pnj_1);
    sfSprite_setPosition(global->gameplay->pnj->sprite_pnj_1, (sfVector2f){5010, 5000});
    sfSprite_setScale(global->gameplay->pnj->sprite_pnj_1, (sfVector2f){2.08333, 2.08333});
    sfSprite_setPosition(global->gameplay->sprite_man, (sfVector2f){global->gameplay->x, global->gameplay->y});
    sfSprite_setScale(global->gameplay->sprite_man, (sfVector2f){2.08333, 2.08333});
}

void create_sprite(global_t *global)
{
    global->gameplay->pnj->p_text = 0;
    global->gameplay->sprite_backg = sfSprite_create();
    global->gameplay->sprite_man = sfSprite_create();
    global->gameplay->pnj->sprite_pnj_1 = sfSprite_create();
    global->gameplay->pnj->pnj_1 = sfTexture_createFromFile("resource/Sprite player/player2and3.png", NULL);
    global->gameplay->backg = sfTexture_createFromFile("resource/World Map.png", NULL);
}

void set_textures(global_t *global)
{
    sfSprite_setTexture(global->gameplay->pnj->sprite_pnj_1, global->gameplay->pnj->pnj_1, sfTrue);
    sfSprite_setTexture(global->gameplay->sprite_backg, global->gameplay->backg, sfTrue);
    sfSprite_setTexture(global->gameplay->sprite_man, global->gameplay->man, sfTrue);
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
    set_textures(global);
    set_position(global);
}

void draw_sprites(global_t *global)
{
    if (global->scn == 1) {
        sfSprite_setPosition(global->gameplay->sprite_man, (sfVector2f){global->gameplay->x, global->gameplay->y});
        sfSprite_setTextureRect(global->gameplay->sprite_man, global->gameplay->rect_man);
        sfRenderWindow_drawSprite(global->window, global->gameplay->sprite_backg, NULL);
        sfRenderWindow_drawSprite(global->window, global->gameplay->sprite_man, NULL);
        sfRenderWindow_drawSprite(global->window, global->gameplay->pnj->sprite_pnj_1, NULL);
        if (global->gameplay->pnj->p_text == 1)
            display_score(global);
        sfRenderWindow_display(global->window);
    }
    display_pause(global);
}