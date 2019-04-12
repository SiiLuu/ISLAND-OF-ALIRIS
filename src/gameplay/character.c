/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** function to the gameplay
*/

#include "my.h"
#include "rpg.h"

void set_position(gameplay_t *gameplay)
{
    sfSprite_setPosition(gameplay->sprite_man, (sfVector2f){500, 500});
}

void init_texture(gameplay_t *gameplay)
{
    gameplay->sprite_backg = sfSprite_create();
    gameplay->sprite_man = sfSprite_create();
    gameplay->backg = sfTexture_createFromFile("resource/test.jpg", NULL);
    gameplay->man = sfTexture_createFromFile("resource/char.png", NULL);
    set_position(gameplay);
}

void draw_sprites(gameplay_t *gameplay, global_t *global)
{
    sfRenderWindow_drawSprite(global->window, gameplay->sprite_backg, NULL);
    sfRenderWindow_drawSprite(global->window, gameplay->sprite_man, NULL);
    sfRenderWindow_display(global->window);
}