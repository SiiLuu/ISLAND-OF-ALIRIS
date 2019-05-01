/*
** EPITECH PROJECT, 2019
** rpg_2018
** File description:
** interaction with non playable player
*/

#include "my.h"
#include "rpg.h"

void destroy_textures_quetes(global_t *global)
{
    sfText_destroy(global->gameplay->pnj->text);
    sfSprite_destroy(global->gameplay->pnj->s_text_box);
    sfTexture_destroy(global->gameplay->pnj->text_box);
}

void destroy_textures_quetes_d(global_t *global)
{
    sfText_destroy(global->gameplay->pnj->text_d);
}

void destroy_textures_quetes_ed(global_t *global)
{
    sfText_destroy(global->gameplay->pnj->text_ed);
}

void destroy_textures_quetes_pech(global_t *global)
{
    sfText_destroy(global->gameplay->pnj->text_pech);
}

void destroy_textures_quetes_bot(global_t *global)
{
    sfText_destroy(global->gameplay->pnj->text_bot);
}

void set_winter_text(global_t *global)
{
    sfText_setFont(global->gameplay->pnj->text, global->gameplay->pnj->font);
    sfText_setCharacterSize(global->gameplay->pnj->text, 35);
    sfText_setColor(global->gameplay->pnj->text, sfWhite);
    sfText_setPosition(global->gameplay->pnj->text, (sfVector2f){4760, 4900 + 400});
}

void set_desert_text(global_t *global)
{
    sfText_setFont(global->gameplay->pnj->text_d, global->gameplay->pnj->font);
    sfText_setCharacterSize(global->gameplay->pnj->text_d, 35);
    sfText_setColor(global->gameplay->pnj->text_d, sfWhite);
    sfText_setPosition(global->gameplay->pnj->text_d, (sfVector2f){1700, 1900 + 500});
}

void set_edesert_text(global_t *global)
{
    sfText_setFont(global->gameplay->pnj->text_ed, global->gameplay->pnj->font);
    sfText_setCharacterSize(global->gameplay->pnj->text_ed, 35);
    sfText_setColor(global->gameplay->pnj->text_ed, sfWhite);
    sfText_setPosition(global->gameplay->pnj->text_ed, (sfVector2f){2680, 1990 + 500});
}

void set_pech_text(global_t *global)
{
    sfText_setFont(global->gameplay->pnj->text_pech, global->gameplay->pnj->font);
    sfText_setCharacterSize(global->gameplay->pnj->text_pech, 35);
    sfText_setColor(global->gameplay->pnj->text_pech, sfWhite);
    sfText_setPosition(global->gameplay->pnj->text_pech, (sfVector2f){3660, 2000 + 500});
}

void set_bot_text(global_t *global)
{
    sfText_setFont(global->gameplay->pnj->text_bot, global->gameplay->pnj->font);
    sfText_setCharacterSize(global->gameplay->pnj->text_bot, 35);
    sfText_setColor(global->gameplay->pnj->text_bot, sfWhite);
    sfText_setPosition(global->gameplay->pnj->text_bot, (sfVector2f){4210, 4600 + 390});
}

void set_text_box(global_t *global)
{
    global->gameplay->pnj->s_text_box = sfSprite_create();
    global->gameplay->pnj->text_box = sfTexture_createFromFile("resource/text.png", NULL);
    sfSprite_setTexture(global->gameplay->pnj->s_text_box, global->gameplay->pnj->text_box, sfTrue);
    sfSprite_setScale(global->gameplay->pnj->s_text_box, (sfVector2f){3, 1.3});
}

void display_text(global_t *global)
{
    global->gameplay->pnj->font = sfFont_createFromFile("resource/font/arial.ttf");
    if (global->gameplay->pnj->p_text == 1 && global->gameplay->pnj->girl_quest == 1) {
        set_text_box(global);
        global->gameplay->pnj->text = sfText_create();
        sfText_setString(global->gameplay->pnj->text, "I'm dying of cold! I\
        wanted to explore\nnew areas but I ended up losing myself, I follow\n\
        you, help me to go back with my mother !");
        set_winter_text(global);
        sfSprite_setPosition(global->gameplay->pnj->s_text_box, (sfVector2f){4700, 4950 + 320});
        sfRenderWindow_drawSprite(global->window, global->gameplay->pnj->s_text_box, NULL);
        sfRenderWindow_drawText(global->window, global->gameplay->pnj->text, NULL);
    }
    if (global->gameplay->pnj->p_text_ed == 1) {
        set_text_box(global);
        global->gameplay->pnj->text_ed = sfText_create();
        sfText_setString(global->gameplay->pnj->text_ed, "it's too hot in this\
        desert, I can't\neven walk the sand burns. Good Luck to you !");
        set_edesert_text(global);
        sfSprite_setPosition(global->gameplay->pnj->s_text_box, (sfVector2f){2620, 2000 + 450});
        sfRenderWindow_drawSprite(global->window, global->gameplay->pnj->s_text_box, NULL);
        sfRenderWindow_drawText(global->window, global->gameplay->pnj->text_ed, NULL);
    }
    if (global->gameplay->pnj->p_text_pech == 1) {
        set_text_box(global);
        global->gameplay->pnj->text_pech = sfText_create();
        sfText_setString(global->gameplay->pnj->text_pech, "I love coming here\
        to fish,\nthere are lots of fish. it makes me\nfeel good after\
        difficult fights");
        set_pech_text(global);
        sfSprite_setPosition(global->gameplay->pnj->s_text_box, (sfVector2f){3600, 2000 + 470});
        sfRenderWindow_drawSprite(global->window, global->gameplay->pnj->s_text_box, NULL);
        sfRenderWindow_drawText(global->window, global->gameplay->pnj->text_pech, NULL);
    }
    if (global->gameplay->pnj->p_text_bot == 1) {
        set_text_box(global);
        global->gameplay->pnj->text_bot = sfText_create();
        sfText_setString(global->gameplay->pnj->text_bot, "I never go away, my\
        mom forbids me.\nweird things happen down there");
        set_bot_text(global);
        sfSprite_setPosition(global->gameplay->pnj->s_text_box, (sfVector2f){4150, 4500 + 450});
        sfRenderWindow_drawSprite(global->window, global->gameplay->pnj->s_text_box, NULL);
        sfRenderWindow_drawText(global->window, global->gameplay->pnj->text_bot, NULL);
    }
    if (global->gameplay->pnj->p_text_d == 1) {
        set_text_box(global);
        global->gameplay->pnj->text_d = sfText_create();
        if (global->gameplay->pnj->quest_complete == 1) {
            sfText_setString(global->gameplay->pnj->text_d, "Thank you !! my\
            daughter is finally back\nI am happy to see her again!");
        }
        else {
            sfText_setString(global->gameplay->pnj->text_d, "It's been several\
            days since my\ndaughter left and I still have no news.\ncould you\
            help me find it?");
        }
        set_desert_text(global);
        sfSprite_setPosition(global->gameplay->pnj->s_text_box, (sfVector2f){1640, 1950 + 420});
        sfRenderWindow_drawSprite(global->window, global->gameplay->pnj->s_text_box, NULL);
        sfRenderWindow_drawText(global->window, global->gameplay->pnj->text_d, NULL);
    }
}

void check_interaction_2(global_t *global)
{
    if (sfKeyboard_isKeyPressed(sfKeyA) &&
        (global->gameplay->x > 2850 && global->gameplay->x < 2950) &&
        (global->gameplay->y > 2070 && global->gameplay->y < 2200)) {
        global->gameplay->pnj->p_text_ed = 1;
        }
    if (sfKeyboard_isKeyPressed(sfKeyA) &&
        (global->gameplay->x > 3680 && global->gameplay->x < 3800) &&
        (global->gameplay->y > 2090 && global->gameplay->y < 2200)) {
        global->gameplay->pnj->p_text_pech = 1;
        }
    if (sfKeyboard_isKeyPressed(sfKeyA) &&
        (global->gameplay->x > 4200 && global->gameplay->x < 4300) &&
        (global->gameplay->y > 4550 && global->gameplay->y < 4650)) {
        global->gameplay->pnj->p_text_bot = 1;
        }
    if (global->gameplay->pnj->p_text == 1 &&
        (global->gameplay->y < 4850 || global->gameplay->y > 5000)) {
        global->gameplay->pnj->p_text = 0;
        destroy_textures_quetes(global);
        }
    if (global->gameplay->pnj->p_text_d == 1 &&
        ((global->gameplay->y < 1900 || global->gameplay->y > 2100) ||
        (global->gameplay->x < 1700 || global->gameplay->x > 1900))) {
        global->gameplay->pnj->p_text_d = 0;
        destroy_textures_quetes_d(global);
        }
    if (global->gameplay->pnj->p_text_ed == 1 &&
        ((global->gameplay->y < 2000 || global->gameplay->y > 2200) ||
        (global->gameplay->x < 2800 || global->gameplay->x > 2950))) {
        global->gameplay->pnj->p_text_ed = 0;
        destroy_textures_quetes_ed(global);
        }
    if (global->gameplay->pnj->p_text_pech == 1 &&
        ((global->gameplay->x < 3680 || global->gameplay->x > 3800) ||
        (global->gameplay->y < 2090 || global->gameplay->y > 2200))) {
        global->gameplay->pnj->p_text_pech = 0;
        destroy_textures_quetes_pech(global);
        }
    if (global->gameplay->pnj->p_text_bot == 1 &&
        ((global->gameplay->x < 4200 || global->gameplay->x > 4300) ||
        (global->gameplay->y < 4550 || global->gameplay->y > 4650))) {
        global->gameplay->pnj->p_text_bot = 0;
        destroy_textures_quetes_bot(global);
        }
}

void check_interaction(global_t *global)
{
    if (sfKeyboard_isKeyPressed(sfKeyA) &&
        (global->gameplay->x > 4900 && global->gameplay->x < 5100) &&
        (global->gameplay->y > 4800 && global->gameplay->y < 5000)) {
        global->gameplay->pnj->p_text = 1;
        global->gameplay->pnj->quest_complete = 1;
        }
    if (sfKeyboard_isKeyPressed(sfKeyA) &&
        (global->gameplay->x > 1700 && global->gameplay->x < 1810) &&
        (global->gameplay->y > 1950 && global->gameplay->y < 2100)) {
        global->gameplay->pnj->p_text_d = 1;
        global->gameplay->pnj->girl_quest = 1;
        }
    if (sfKeyboard_isKeyPressed(sfKeyA) &&
        (global->gameplay->x > 1700 && global->gameplay->x < 1810) &&
        (global->gameplay->y > 1950 && global->gameplay->y < 2100) &&
        (global->gameplay->pnj->quest_complete == 1))
        global->gameplay->pnj->girl_quest = 0;
    check_interaction_2(global);
}