/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** menu
*/

#include "my.h"
#include "rpg.h"

void choose_display(global_t *global)
{
    sfRenderWindow_drawSprite(global->window,
                                global->choose_char->player1_sprite, NULL);
    sfRenderWindow_drawSprite(global->window,
                                global->choose_char->player2_sprite, NULL);
    sfRenderWindow_drawSprite(global->window,
                                global->choose_char->player3_sprite, NULL);
    sfRenderWindow_drawSprite(global->window,
                                global->choose_char->player4_sprite, NULL);
    sfRenderWindow_display(global->window);
}

void choose_create2(global_t *global)
{
    sfSprite_setTexture(global->choose_char->player1_sprite,
                        global->choose_char->player1_texture, sfTrue);
    sfSprite_setTexture(global->choose_char->player2_sprite,
                        global->choose_char->player2_texture, sfTrue);
    sfSprite_setTexture(global->choose_char->player3_sprite,
                        global->choose_char->player3_texture, sfTrue);
    sfSprite_setTexture(global->choose_char->player4_sprite,
                        global->choose_char->player4_texture, sfTrue);
    sfSprite_setPosition(global->choose_char->player1_sprite,
                        (sfVector2f){50, 390});
    sfSprite_setPosition(global->choose_char->player2_sprite,
                        (sfVector2f){550, 390});
    sfSprite_setPosition(global->choose_char->player3_sprite,
                        (sfVector2f){1050, 390});
    sfSprite_setPosition(global->choose_char->player4_sprite,
                        (sfVector2f){1550, 390});
}

void choose_create(global_t *global)
{
    const char *texture1 = "resource/Sprite player/player1.png";
    const char *texture2 = "resource/Sprite player/player2.png";
    const char *texture3 = "resource/Sprite player/player3.png";
    const char *texture4 = "resource/Sprite player/player4.png";

    global->choose_char->player1_sprite = sfSprite_create();
    global->choose_char->player2_sprite = sfSprite_create();
    global->choose_char->player3_sprite = sfSprite_create();
    global->choose_char->player4_sprite = sfSprite_create();
    global->choose_char->player1_texture = sfTexture_createFromFile(texture1,
                                                NULL);
    global->choose_char->player2_texture = sfTexture_createFromFile(texture2,
                                                NULL);
    global->choose_char->player3_texture = sfTexture_createFromFile(texture3,
                                                NULL);
    global->choose_char->player4_texture = sfTexture_createFromFile(texture4,
                                                NULL);
    choose_create2(global);
}

int choose_character(global_t *global)
{
    int x = 0;
    int y = 0;

    choose_create(global);
    choose_display(global);
    while (global->event.type != sfEvtClosed) {
        if (global->event.key.code == sfKeyEscape) {
            x = global->event.mouseButton.x;
            y = global->event.mouseButton.y;
            return (0);
        }
        sfRenderWindow_pollEvent(global->window, &global->event);
    }
}