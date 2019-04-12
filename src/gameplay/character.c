/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** function to the gameplay
*/

#include "my.h"
#include "rpg.h"

int check_events(global_t *global, gameplay_t *gameplay)
{
    while (sfRenderWindow_pollEvent(global->window, &global->event)) {
        if (global->event.type == sfEvtClosed)
            sfRenderWindow_close(global->window);
        if (global->event.key.code == sfKeyUp) {
            sfSprite_setPosition(gameplay->sprite_man, (sfVector2f){300, 200});
            gameplay->rect_man.top = 0;
        }
        if (global->event.key.code == sfKeyDown) {
            sfSprite_setPosition(gameplay->sprite_man, (sfVector2f){300, 400});
            gameplay->rect_man.top = 128;
        }
        if (global->event.key.code == sfKeyLeft) {
            sfSprite_setPosition(gameplay->sprite_man, (sfVector2f){200, 300});
            gameplay->rect_man.top = 64;
        }
        if (global->event.key.code == sfKeyRight) {
            sfSprite_setPosition(gameplay->sprite_man, (sfVector2f){400, 300});
            gameplay->rect_man.top = 192;
        }
    }
    return (0);
}

void move_rect(gameplay_t *gameplay)
{
    gameplay->rect_man.left += 64;
    if (gameplay->rect_man.left > 512)
        gameplay->rect_man.left = 0;
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
    sfSprite_setPosition(gameplay->sprite_man, (sfVector2f){300, 300});
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