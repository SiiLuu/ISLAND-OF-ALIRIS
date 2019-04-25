/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** menu
*/

#include "my.h"
#include "rpg.h"

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

int choose_character1(global_t *global, int x, int y)
{
    if (x >= 50 && x <= 325 && y >= 390 && y <= 652) {
        global->gameplay->player_nb = 1;
        return (1);
    }
    else if (x >= 550 && x <= 791 && y >= 390 && y <= 644) {
        global->gameplay->player_nb = 2;
        return (1);
    }
    else if (x >= 1050 && x <= 1313 && y >= 390 && y <= 673) {
        global->gameplay->player_nb = 3;
        return (1);
    }
    else if (x >= 1550 && x <= 1852 && y >= 390 && y <= 662) {
        global->gameplay->player_nb = 4;
        return (1);
    }
    else
        return (0);
}

void character_choose_create_display(global_t *global)
{
    static bool i = 0;    

    if (i == 1)
        choose_display(global);
    else {
        choose_create(global);
        choose_display(global);
        i = 1;
    }
}

int choose_character(global_t *global)
{
    int x = 0;
    int y = 0;

    character_choose_create_display(global);
    while (global->event.type != sfEvtClosed) {
        if (global->event.type == sfEvtMouseButtonPressed) {
            x = global->event.mouseButton.x;
            y = global->event.mouseButton.y;
            if (choose_character1(global, x, y))
                return (0);
        }
        if (global->event.key.code == sfKeyEscape)
            exit (0);
        sfRenderWindow_pollEvent(global->window, &global->event);
    }
}
