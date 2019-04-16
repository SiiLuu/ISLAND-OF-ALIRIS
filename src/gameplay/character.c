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
    sfView_reset(gameplay->view, (sfFloatRect){3008 - 1920, 0,
    1920, 1080});
}

void move_vue(gameplay_t *gameplay, global_t *global)
{
    if ((gameplay->x > 3008 - 1920 / 2 - 48) && (gameplay->y < 1080 / 2 - 48))
        bottom_left_corner(gameplay);
    else if ((gameplay->x < 0 + 1920 / 2 - 48) &&
            (gameplay->y < 1080 / 2 - 48))
        sfView_reset(gameplay->view, (sfFloatRect){0, 0, 1920, 1080});
    else if ((gameplay->x < 0 + 1920 / 2 - 48) &&
            (gameplay->y > 2000 - 1080 / 2 - 48))
        top_right_corner(gameplay);
    else if ((gameplay->x > 3008 - 1920 / 2 - 48) &&
            (gameplay->y > 2000 - 1080 / 2 - 48))
        bottom_right_corner(gameplay);
    else if (gameplay->x > 3008 - (1920 / 2) - 48 ||
            gameplay->x < (1920 / 2) - 48)
        camera_horizontal(gameplay);
    else if (gameplay->y > 2000 - (1080 / 2) - 48 ||
           gameplay->y < (1080 / 2) - 48)
        vertical_camera(gameplay);
    else
        camera_center(gameplay);
    sfRenderWindow_setView(global->window, gameplay->view);
}

void move_rect(gameplay_t *gameplay)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(gameplay->clocks)) > 80) {
        gameplay->rect_man.left += 48;
        sfClock_restart(gameplay->clocks);
    }
    if (gameplay->rect_man.left > 528)
        gameplay->rect_man.left = 432;
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

void set_my_rect(gameplay_t *gameplay)
{
    gameplay->rect_man.height = 48;
    gameplay->rect_man.width = 48;
    gameplay->rect_man.left = 432;
    gameplay->rect_man.top = 0;
}

void set_position(gameplay_t *gameplay)
{
    sfSprite_setPosition(gameplay->sprite_man, (sfVector2f){gameplay->x, gameplay->y});
    sfSprite_setScale(gameplay->sprite_man, (sfVector2f){2.08333, 2.08333});
}

void init_texture(gameplay_t *gameplay)
{
    gameplay->sprite_backg = sfSprite_create();
    gameplay->sprite_man = sfSprite_create();
    gameplay->backg = sfTexture_createFromFile("resource/m.jpg", NULL);
    gameplay->man = sfTexture_createFromFile("resource/characters/Actor1.png", NULL);
    set_my_rect(gameplay);
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