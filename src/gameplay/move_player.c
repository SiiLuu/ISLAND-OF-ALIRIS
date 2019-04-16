/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** function to move the player on the map
*/

#include "my.h"
#include "rpg.h"

void move_up(gameplay_t *gameplay, global_t *global)
{
    gameplay->rect_man.top = 144;
    while (sfKeyboard_isKeyPressed(sfKeyUp)) {
        move_rect(gameplay);
        move_vue(gameplay, global);
        sfSprite_setTextureRect(gameplay->sprite_man, gameplay->rect_man);
        sfSprite_setPosition(gameplay->sprite_man, (sfVector2f){gameplay->x, gameplay->y});
        sfRenderWindow_drawSprite(global->window, gameplay->sprite_backg, NULL);
        sfRenderWindow_drawSprite(global->window, gameplay->sprite_man, NULL);
        sfRenderWindow_display(global->window);
        gameplay->y -= 5;
    }
}

void move_down(gameplay_t *gameplay, global_t *global)
{
    gameplay->rect_man.top = 0;
    while (sfKeyboard_isKeyPressed(sfKeyDown)) {
        move_rect(gameplay);
        move_vue(gameplay, global);
        sfSprite_setTextureRect(gameplay->sprite_man, gameplay->rect_man);
        sfSprite_setPosition(gameplay->sprite_man, (sfVector2f){gameplay->x, gameplay->y});
        sfRenderWindow_drawSprite(global->window, gameplay->sprite_backg, NULL);
        sfRenderWindow_drawSprite(global->window, gameplay->sprite_man, NULL);
        sfRenderWindow_display(global->window);
        gameplay->y += 5;
    }
}

void move_left(gameplay_t *gameplay, global_t *global)
{
    gameplay->rect_man.top = 48;
    while (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        move_rect(gameplay);
        move_vue(gameplay, global);
        sfSprite_setTextureRect(gameplay->sprite_man, gameplay->rect_man);
        sfSprite_setPosition(gameplay->sprite_man, (sfVector2f){gameplay->x, gameplay->y});
        sfRenderWindow_drawSprite(global->window, gameplay->sprite_backg, NULL);
        sfRenderWindow_drawSprite(global->window, gameplay->sprite_man, NULL);
        sfRenderWindow_display(global->window);
        gameplay->x -= 5;
    }
}

void move_right(gameplay_t *gameplay, global_t *global)
{
    gameplay->rect_man.top = 96;
    while (sfKeyboard_isKeyPressed(sfKeyRight)) {
        move_rect(gameplay);
        move_vue(gameplay, global);
        sfSprite_setTextureRect(gameplay->sprite_man, gameplay->rect_man);
        sfSprite_setPosition(gameplay->sprite_man, (sfVector2f){gameplay->x, gameplay->y});
        sfRenderWindow_drawSprite(global->window, gameplay->sprite_backg, NULL);
        sfRenderWindow_drawSprite(global->window, gameplay->sprite_man, NULL);
        sfRenderWindow_display(global->window);
        gameplay->x += 5;
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