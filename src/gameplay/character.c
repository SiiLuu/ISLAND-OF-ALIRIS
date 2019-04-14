/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** function to the gameplay
*/

#include "my.h"
#include "rpg.h"

void move_vue(gameplay_t *gameplay, global_t *global)
{
    sfView_reset(gameplay->view, (sfFloatRect){0, 0, 1920, 1080});
    sfView_reset(gameplay->view, (sfFloatRect){gameplay->y - ((1920 / 2) - 64),
    gameplay->x - ((1080 / 2) - 64), 1920, 1080});
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

void move_up(gameplay_t *gameplay, global_t *global)
{
    gameplay->rect_man.top = 144;
    while (sfKeyboard_isKeyPressed(sfKeyUp)) {
        move_rect(gameplay);
        move_vue(gameplay, global);
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
    gameplay->rect_man.top = 0;
    while (sfKeyboard_isKeyPressed(sfKeyDown)) {
        move_rect(gameplay);
        move_vue(gameplay, global);
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
    gameplay->rect_man.top = 48;
    while (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        move_rect(gameplay);
        move_vue(gameplay, global);
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
    gameplay->rect_man.top = 96;
    while (sfKeyboard_isKeyPressed(sfKeyRight)) {
        move_rect(gameplay);
        move_vue(gameplay, global);
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
    sfSprite_setPosition(gameplay->sprite_man, (sfVector2f){gameplay->y, gameplay->x});
    sfSprite_setScale(gameplay->sprite_man, (sfVector2f){2, 2});
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