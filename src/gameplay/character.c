/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** function to the gameplay
*/

#include "my.h"
#include "rpg.h"
void bottom_left_corner(gameplay_t *gameplay)
{
    sfView_reset(gameplay->view, (sfFloatRect){6000 - 1920, 0,
    1920, 1080});
}

void move_vue(gameplay_t *gameplay, global_t *global)
{
    if ((gameplay->x > 6000 - 1920 / 2 - 48) && (gameplay->y < 1080 / 2 - 48))
        bottom_left_corner(gameplay);
    else if ((gameplay->x < 0 + (1920 / 2) - 48) &&
            (gameplay->y < (1080 / 2) - 48))
        sfView_reset(gameplay->view, (sfFloatRect){0, 0, 1920, 1080});
    else if ((gameplay->x < 0 + 1920 / 2 - 48) &&
            (gameplay->y > 6000 - 1080 / 2 - 48))
        top_right_corner(gameplay);
    else if ((gameplay->x > 6000 - 1920 / 2 - 48) &&
            (gameplay->y > 6000 - 1080 / 2 - 48))
        bottom_right_corner(gameplay);
    else if (gameplay->x > 6000 - (1920 / 2) - 48 ||
            gameplay->x < (1920 / 2) - 48)
        camera_horizontal(gameplay);
    else if (gameplay->y > 6000 - (1080 / 2) - 48 ||
           gameplay->y < (1080 / 2) - 48)
        vertical_camera(gameplay);
    else
        camera_center(gameplay);
    sfRenderWindow_setView(global->window, gameplay->view);
}

int check_events(global_t *global, gameplay_t *gameplay)
{
    while (sfRenderWindow_pollEvent(global->window, &global->event)) {
        if (global->event.type == sfEvtClosed)
            sfRenderWindow_close(global->window);
        if (global->event.key.code == sfKeyEscape)
            sfRenderWindow_close(global->window);
        move_character(gameplay, global);
    }
    return (0);
}

void set_position(gameplay_t *gameplay)
{
    sfSprite_setPosition(gameplay->sprite_man, (sfVector2f){gameplay->x, gameplay->y});
    sfSprite_setScale(gameplay->sprite_man, (sfVector2f){2.08333, 2.08333});
}

void create_sprite(gameplay_t *gameplay)
{
    gameplay->sprite_backg = sfSprite_create();
    gameplay->sprite_man = sfSprite_create();
    gameplay->sprite_man2 = sfSprite_create();
    gameplay->sprite_man3 = sfSprite_create();
    gameplay->sprite_man4 = sfSprite_create();
    gameplay->backg = sfTexture_createFromFile("resource/World Map.png", NULL);
}

void init_texture(gameplay_t *gameplay)
{
    gameplay->player_nb = 2;
    create_sprite(gameplay);
    if (gameplay->player_nb == 1) {
        gameplay->man = sfTexture_createFromFile("resource/Sprite player/Actor.png", NULL);
        set_my_rect_p1(gameplay);
    }
    if (gameplay->player_nb == 2) {
        gameplay->man = sfTexture_createFromFile("resource/Sprite player/player2and3.png", NULL);
        set_my_rect_p2(gameplay);
    }
    if (gameplay->player_nb == 3) {
        gameplay->man = sfTexture_createFromFile("resource/Sprite player/player2and3.png", NULL);
        set_my_rect_p3(gameplay);
    }
    if (gameplay->player_nb == 4) {
        gameplay->man = sfTexture_createFromFile("resource/Sprite player/Actor.png", NULL);
        set_my_rect_p4(gameplay);
    }
    sfSprite_setTexture(gameplay->sprite_backg, gameplay->backg, sfTrue);
    sfSprite_setTexture(gameplay->sprite_man, gameplay->man, sfTrue);
    set_position(gameplay);
}

void draw_sprites(gameplay_t *gameplay, global_t *global)
{
    sfSprite_setTextureRect(gameplay->sprite_man, gameplay->rect_man);
    sfRenderWindow_drawSprite(global->window, gameplay->sprite_backg, NULL);
    sfRenderWindow_drawSprite(global->window, gameplay->sprite_man, NULL);
    sfRenderWindow_display(global->window);
}