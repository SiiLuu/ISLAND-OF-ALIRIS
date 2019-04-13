/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** function to the gameplay
*/

#include "my.h"
#include "rpg.h"

void move_rect(gameplay_t *gameplay)
{
    gameplay->rect_man.left += 64;
    if (gameplay->rect_man.left > 512)
        gameplay->rect_man.left = 0;
}

void move_up(gameplay_t *gameplay, global_t *global)
{
    gameplay->rect_man.top = 0;
    while (sfKeyboard_isKeyPressed(sfKeyUp)) {
        move_rect(gameplay);
        sfSprite_setTextureRect(gameplay->sprite_man, gameplay->rect_man);
        sfSprite_setPosition(gameplay->sprite_man, (sfVector2f){gameplay->y, gameplay->x});
        sfRenderWindow_drawSprite(global->window, gameplay->sprite_backg, NULL);
        sfRenderWindow_drawSprite(global->window, gameplay->sprite_man, NULL);
        sfRenderWindow_display(global->window);
        gameplay->x -= 5;
    }
}

void move_down(gameplay_t *gameplay, global_t *global)
{
    gameplay->rect_man.top = 128;
    while (sfKeyboard_isKeyPressed(sfKeyDown)) {
        move_rect(gameplay);
        sfSprite_setTextureRect(gameplay->sprite_man, gameplay->rect_man);
        sfSprite_setPosition(gameplay->sprite_man, (sfVector2f){gameplay->y, gameplay->x});
        sfRenderWindow_drawSprite(global->window, gameplay->sprite_backg, NULL);
        sfRenderWindow_drawSprite(global->window, gameplay->sprite_man, NULL);
        sfRenderWindow_display(global->window);
        gameplay->x += 5;
    }
}

void move_left(gameplay_t *gameplay, global_t *global)
{
    gameplay->rect_man.top = 64;
    while (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        move_rect(gameplay);
        sfSprite_setTextureRect(gameplay->sprite_man, gameplay->rect_man);
        sfSprite_setPosition(gameplay->sprite_man, (sfVector2f){gameplay->y, gameplay->x});
        sfRenderWindow_drawSprite(global->window, gameplay->sprite_backg, NULL);
        sfRenderWindow_drawSprite(global->window, gameplay->sprite_man, NULL);
        sfRenderWindow_display(global->window);
        gameplay->y -= 5;
    }
}

void move_right(gameplay_t *gameplay, global_t *global)
{
    gameplay->rect_man.top = 192;
    while (sfKeyboard_isKeyPressed(sfKeyRight)) {
        move_rect(gameplay);
        sfSprite_setTextureRect(gameplay->sprite_man, gameplay->rect_man);
        sfSprite_setPosition(gameplay->sprite_man, (sfVector2f){gameplay->y, gameplay->x});
        sfRenderWindow_drawSprite(global->window, gameplay->sprite_backg, NULL);
        sfRenderWindow_drawSprite(global->window, gameplay->sprite_man, NULL);
        sfRenderWindow_display(global->window);
        gameplay->y += 5;
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

int check_events(global_t *global, gameplay_t *gameplay)
{
    while (sfRenderWindow_pollEvent(global->window, &global->event)) {
        if (global->event.type == sfEvtClosed)
            sfRenderWindow_close(global->window);
        move_character(gameplay, global);
    }
    return (0);
}

void set_my_rect(gameplay_t *gameplay)
{
    gameplay->rect_man.height = 64;
    gameplay->rect_man.width = 64;
    gameplay->rect_man.left = 0;
    gameplay->rect_man.top = 0;
}

void set_position(gameplay_t *gameplay)
{
    sfSprite_setPosition(gameplay->sprite_man, (sfVector2f){gameplay->y, gameplay->x});
    sfSprite_setScale(gameplay->sprite_man, (sfVector2f){2, 2});
}

void init_texture(gameplay_t *gameplay)
{
    gameplay->sprite_backg = sfSprite_create();
    gameplay->sprite_man = sfSprite_create();
    gameplay->backg = sfTexture_createFromFile("resource/test.jpg", NULL);
    gameplay->man = sfTexture_createFromFile("resource/char.png", NULL);
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